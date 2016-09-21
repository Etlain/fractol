/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmouhssi <mmouhssi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/16 23:50:42 by mmouhssi          #+#    #+#             */
/*   Updated: 2016/09/21 20:26:24 by mmouhssi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

#include <stdio.h>
void ft_julia(char *data)
{
	double x1 = -1;
	double x2 = 1;
	double y1 = -1.2;
	double y2 = 1.2;
	double zoom_y = HEIGHT / (y2 - y1); // variable a definir a l exterieur
	double zoom_x = WIDTH / (x2 - x1);
	double zoom = 100;
	int iteration_max = 100;
	int x = 0;
	int y = 0;
	double c_r;
	double c_i;
	double z_r;
	double z_i;
	int i = 0;
	double tmp;

	//double image_x = ((x2 - x1) * zoom);
	//double image_y = ((y2 - y1) * zoom);
	while (x < HEIGHT)
	{
		y = 0;
		while (y < WIDTH)
		{
			z_r = x / zoom_x + x1;
			z_i = y / zoom_y + y1;
			c_r = 0.285;
			c_i = 0.01;
			i = 0;
			while (i < iteration_max && ((z_r * z_r) + (z_i * z_i)) < 4)
			{
				tmp = z_r;
				z_r = z_r * z_r - z_i * z_i + c_r;
				z_i = 2 * z_i * tmp + c_i;
				i++;
			}
			if (i == iteration_max)
				put_pixel(data, x, y, 0xffffff);
			y++;
		}
		x++;
	}
}

void ft_mandelbrot(t_env *e)
{
	/*double x1 = -2.1;
	double x2 = 0.6;
	double y1 = -1.2;
	double y2 = 1.2;*/
	/*double zoom_y = HEIGHT / (y2 - y1); // variable a definir a l exterieur
	double zoom_x = WIDTH / (x2 - x1);*/
	//int iteration_max = 50;
	int x = 0;
	int y = 0;
	//double c_r;
	//double c_i;
	//double z_r;
	//double z_i;
	int i = 0;
	double tmp;

	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			e->c_r = x / e->zoom_x + e->x1;
			e->c_i = y / e->zoom_y + e->y1;
			e->z_r = 0;
			e->z_i = 0;
			i = 0;
			while (i < e->i_max && ((e->z_r * e->z_r) + (e->z_i * e->z_i)) < 4)
			{
				tmp = e->z_r;
				e->z_r = e->z_r * e->z_r - e->z_i * e->z_i + e->c_r;
				e->z_i = 2 * e->z_i * tmp + e->c_i;
				i++;
			}
			if (i == e->i_max)
				put_pixel(e->data, x, y, 0xffffff);
			x++;
		}
		y++;
	}
}
