/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcaetano <wcaetano@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 21:51:53 by wcaetano          #+#    #+#             */
/*   Updated: 2023/02/12 23:54:00 by wcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# define WIDTH 600
# define HEIGHT 600
# define MAX_R 2.0
# define MIN_R -2.0
# define MAX_I 2.0
# define MIN_I -2.0
# define MAX_ITER 220

# include "minilibx/mlx.h"
# include "libft/libft.h"

typedef int	(*t_fractal_func)(double c_r, double c_i);

typedef struct s_factor {
	double	real;
	double	i;
}				t_factor;

typedef struct s_coord {
	double	real;
	double	i;
}				t_coord;

typedef struct s_data {
	void	*mlx;
	void	*mlx_win;
	void	*img;
	void	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		(*fractal)(double, double);
	double	zoom;
	double	centralize_x;
	double	centralize_y;
	double	factor_r;
	double	factor_i;
}				t_data;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
int		get_color(int iter);
int		close_window(t_data *data);
int		handle_keyboard(int keycode, t_data *data);
int		handle_mouse(int keycode, int x, int y, t_data *data);
int		mandelbrot(double c_r, double c_i);
int		julia(double c_r, double c_i);
void	print_fractal(t_data *data);
void	check_args(int argc, char **argv);

#endif
