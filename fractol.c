/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcaetano <wcaetano@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 21:38:23 by wcaetano          #+#    #+#             */
/*   Updated: 2023/02/13 00:04:22 by wcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	print_fractal(t_data *data)
{
	int			x;
	int			y;
	int			iter;
	t_coord		coords;	

	x = 0;
	while (x < WIDTH)
	{
		y = 0;
		coords.real = MIN_R + data->centralize_x
			+ x * data->factor_r * data->zoom;
		while (y < HEIGHT)
		{
			coords.i = MIN_I + data->centralize_y
				+ y * data->factor_i * data->zoom;
			iter = (*data->fractal)(coords.real, coords.i);
			my_mlx_pixel_put(data, x, y, get_color(iter));
			y++;
		}
		x++;
	}
	mlx_clear_window(data->mlx, data->mlx_win);
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->img, 0, 0);
}

t_fractal_func	select_fractal(int argc, char **argv)
{
	if (!ft_strncmp(argv[1], "mandelbrot", 11))
		return (&mandelbrot);
	if (!ft_strncmp(argv[1], "julia", 6))
		return (&julia);
	return (NULL);
}

int	main(int argc, char **argv)
{
	t_data		data;

	data.zoom = 1;
	data.factor_i = (MAX_R - MIN_R) / (WIDTH - 1);
	data.factor_r = (MAX_I - MIN_I) / (HEIGHT - 1);
	data.centralize_x = 0;
	data.centralize_y = 0;
	check_args(argc, argv);
	data.fractal = select_fractal(argc, argv);
	if (! data.fractal)
		exit(1);
	data.mlx = mlx_init();
	data.mlx_win = mlx_new_window(data.mlx, WIDTH, HEIGHT, "Fractol");
	data.img = mlx_new_image(data.mlx, WIDTH, HEIGHT);
	data.addr = mlx_get_data_addr(data.img, &data.bits_per_pixel,
			&data.line_length, &data.endian);
	mlx_hook(data.mlx_win, 17, 0, close_window, &data);
	mlx_key_hook(data.mlx_win, handle_keyboard, &data);
	mlx_mouse_hook(data.mlx_win, handle_mouse, &data);
	print_fractal(&data);
	mlx_loop(data.mlx);
}
