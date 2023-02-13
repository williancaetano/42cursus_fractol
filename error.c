/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcaetano <wcaetano@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 21:38:16 by wcaetano          #+#    #+#             */
/*   Updated: 2023/02/12 23:22:26 by wcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>

void	check_args(int argc, char **argv)
{
	if (argc != 2)
	{
		write(2, "Incorrect number of parameters!", 31);
		exit(1);
	}
	if (ft_strncmp(argv[1], "mandelbrot", 11) != 0
		&& ft_strncmp(argv[1], "julia", 6) != 0)
	{
		write(2, "Unknown fractal. Available fractals:\n\nmandelbrot\njulia\n", 55);
		exit(1);
	}
}
