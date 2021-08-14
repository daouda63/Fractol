/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdaouda <gdaouda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 18:17:51 by gdaouda           #+#    #+#             */
/*   Updated: 2021/08/14 16:01:22 by gdaouda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./mlx/mlx.h"
#include <stdio.h>

int main()
{
	double	x;
	double	y;
	double	t;
	long	i;
	const double c = -0.75;

	x = 1;
	y = 0.2;
	i = 0;
	t = 0;
	void    *init_mlx;
	void    *windows_mlx;

	init_mlx = mlx_init();
	windows_mlx = mlx_new_window(init_mlx, 1000, 1000, "fractol");
	while (i < 1000)
	{	
		t = x;
		x = c + ((x * x) - (y * y));
		y = ((t * y) + (y * t));
		y = y * 1000;
		x = x * 1000;
		mlx_pixel_put(init_mlx, windows_mlx, y, x, 0xff0000);
		y = y / 1000;
		x = x / 1000;
		i++;
	}
	mlx_loop(init_mlx);
}
