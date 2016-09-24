/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmouhssi <mmouhssi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/16 23:50:42 by mmouhssi          #+#    #+#             */
/*   Updated: 2016/09/24 14:28:08 by mmouhssi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

#include <stdio.h>
void ft_julia(t_env *e)
{
	int x = 0;
	int y = 0;
	int i = 0;
	double tmp;

	while (x < HEIGHT)
	{
		y = 0;
		while (y < WIDTH)
		{
			e->z_r = x / e->zoom_x + e->x1;
			e->z_i = y / e->zoom_y + e->y1;
			e->c_r = 0.285 * e->f;
			e->c_i = 0.01 * e->f;
			i = 0;
			while (i < e->i_max && ((e->z_r * e->z_r) + (e->z_i * e->z_i)) < 4)
			{
				tmp = e->z_r;
				e->z_r = e->z_r * e->z_r - e->z_i * e->z_i + e->c_r;
				e->z_i = 2 * e->z_i * tmp + e->c_i;
				i++;
			}
			if (i == e->i_max)
				put_pixel(e->data, x, y, i * 0xffff / e->i_max);
			else
				put_pixel(e->data, x, y, i * 0xffff / e->i_max);
			y++;
		}
		x++;
	}
}

void ft_mandelbrot(t_env *e)
{
	int x;
	int y;
	int i;
	double tmp;
	
	y = 0;
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
				//put_pixel(e->data, x, y, i * 0xffa500 / e->i_max);
				//put_pixel(e->data, x, y, i * 0xff / e->i_max);
				put_pixel(e->data, x, y, i * 0xffff / e->i_max);
			else
				//put_pixel(e->data, x, y, i * 0xffff / e->i_max);
				//put_pixel(e->data, x, y, i * 0xff / e->i_max);
				put_pixel(e->data, x, y, i * 0xffff / e->i_max);
			x++;
		}
		y++;
	}
}

void ft_burningship(t_env *e)
{
	int x;
	int y;
	int i;
	double tmp;
	
	y = 0;
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
				e->z_r = ft_abs_d(e->z_r * e->z_r) - e->z_i * e->z_i + e->c_r;
				e->z_i = 2 * ft_abs_d(e->z_i) * ft_abs_d(tmp) + e->c_i;
				i++;
			}
			if (i == e->i_max)
				put_pixel(e->data, x, y, i * 0xffff / e->i_max);
			else
				put_pixel(e->data, x, y, i * 0xffff / e->i_max);
			x++;
		}
		y++;
	}
}
