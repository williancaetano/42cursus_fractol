/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcaetano <wcaetano@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 21:38:34 by wcaetano          #+#    #+#             */
/*   Updated: 2023/02/12 21:46:50 by wcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	julia(double c_r, double c_i)
{
	int		i;
	double	x_next;
	double	y_next;
	double	x;
	double	y;

	i = 0;
	x = c_r;
	y = c_i;
	while (x * x + y * y <= 4 && i < MAX_ITER)
	{
		x_next = (x * x) - (y * y) + (-0.835);
		y_next = 2 * x * y + (-0.2321);
		i++;
		x = x_next;
		y = y_next;
	}
	return (i);
}
