/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcaetano <wcaetano@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 21:38:47 by wcaetano          #+#    #+#             */
/*   Updated: 2023/02/12 21:48:00 by wcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	mandelbrot(double c_r, double c_i)
{
	int		i;
	double	x;
	double	y;
	double	x_next;
	double	y_next;

	i = 0;
	x = 0;
	y = 0;
	while (x * x + y * y <= 4 && i < MAX_ITER)
	{
		x_next = (x * x) - (y * y) + c_r;
		y_next = 2 * x * y + c_i;
		i++;
		x = x_next;
		y = y_next;
	}
	return (i);
}
