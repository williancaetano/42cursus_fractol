/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcaetano <wcaetano@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 21:38:54 by wcaetano          #+#    #+#             */
/*   Updated: 2023/02/13 00:03:31 by wcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	handle_mouse(int keycode, int x, int y, t_data *data)
{
	double	old_x;
	double	old_y;
	double	new_x;
	double	new_y;

	old_x = MIN_R + x * data->factor_r * data->zoom;
	old_y = MIN_I + y * data->factor_i * data->zoom;
	if (keycode == 4)
	{
		data->zoom *= 1.1;
		new_x = MIN_R + x * data->factor_r * data->zoom;
		new_y = MIN_I + y * data->factor_i * data->zoom;
		data->centralize_x -= new_x - old_x;
		data->centralize_y -= new_y - old_y;
	}
	else if (keycode == 5)
	{
		data->zoom *= 0.9;
		new_x = MIN_R + x * data->factor_r * data->zoom;
		new_y = MIN_I + y * data->factor_i * data->zoom;
		data->centralize_x -= new_x - old_x;
		data->centralize_y -= new_y - old_y;
	}
	print_fractal(data);
	return (0);
}
