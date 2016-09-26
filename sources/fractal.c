/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmouhssi <mmouhssi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/16 23:50:42 by mmouhssi          #+#    #+#             */
/*   Updated: 2016/09/26 15:08:30 by mmouhssi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static void	draw_fractal(t_env *e, void (*f)(t_env *, int, int))
{
	int y;
	int x;

	x = 0;
	while (x < HEIGHT)
	{
		y = 0;
		while (y < WIDTH)
		{
			f(e, x, y);
			y++;
		}
		x++;
	}
}

static void	ft_julia(t_env *e, int x, int y)
{
	double	tmp;
	int		i;

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
}

static void	ft_mandelbrot(t_env *e, int x, int y)
{
	double	tmp;
	int		i;

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
		put_pixel(e->data, x, y, i * 0xffff / e->i_max);
	else
		put_pixel(e->data, x, y, i * 0xffff / e->i_max);
}

static void	ft_burningship(t_env *e, int x, int y)
{
	int		i;
	double	tmp;

	e->c_r = x / e->zoom_x + e->x1;
	e->c_i = y / e->zoom_y + e->y1;
	e->z_r = 0;
	e->z_i = 0;
	i = 0;
	while (i < e->i_max && ((e->z_r * e->z_r) + (e->z_i * e->z_i)) < 4)
	{
		tmp = e->z_r;
		e->z_r = ft_fabs(e->z_r * e->z_r) - e->z_i * e->z_i + e->c_r;
		e->z_i = 2 * ft_fabs(e->z_i) * ft_fabs(tmp) + e->c_i;
		i++;
	}
	if (i == e->i_max)
		put_pixel(e->data, x, y, i * 0xffff / e->i_max);
	else
		put_pixel(e->data, x, y, i * 0xffff / e->i_max);
}

void		ft_fractal(t_env *e)
{
	if (e->fractal == 1)
		draw_fractal(e, ft_mandelbrot);
	else if (e->fractal == 2)
		draw_fractal(e, ft_julia);
	else if (e->fractal == 3)
		draw_fractal(e, ft_burningship);
}
