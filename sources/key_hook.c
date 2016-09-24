/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmouhssi <mmouhssi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/28 19:17:24 by mmouhssi          #+#    #+#             */
/*   Updated: 2016/09/24 16:59:50 by mmouhssi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

#include <stdio.h>
void	direction(int keycode, t_env *e)
{
	if (keycode == 123)
	{
		e->x1 -= 100 / e->zoom_x;
		e->x2 -= 100 / e->zoom_x;
		e->b = 1;
	}
	if (keycode == 124)
	{
		e->x1 += 100 / e->zoom_x;
		e->x2 += 100 / e->zoom_x;
		e->b = 1;
	}
	if (keycode == 125)
	{
		e->y1 += 100 / e->zoom_y;
		e->y2 += 100 / e->zoom_y;
		e->b = 1;
	}
	if (keycode == 126)
	{
		e->y1 -= 100 / e->zoom_y;
		e->y2 -= 100 / e->zoom_y;
		e->b = 1;
	}
	printf("key : %d\n", keycode);
	//printf("val x : %f, %f\n", e->x1, e->x2);
	//printf("val y : %f, %f\n", e->y1, e->y2);
}

void	key_init(int keycode, t_env *e)
{
	if (keycode == 15)
	{
		init_fract(e);
		e->b = 1;
	}
	else if (keycode == 83 || keycode == 18)
	{
		e->fractal = 1;
		init_fract(e);
		e->b = 1;
	}
	else if (keycode == 84 || keycode == 19)
	{
		e->fractal = 2;
		init_fract(e);
		e->b = 1;
	}
	else if (keycode == 85 || keycode == 20)
	{
		e->fractal = 3;
		init_fract(e);
		e->b = 1;
	}
}

void	zoom_iter(int keycode, t_env *e)
{
	if (keycode == 69)
	{
		e->zoom_x = e->zoom_x * 1.1;
		e->zoom_y = e->zoom_y * 1.1;
		e->b = 1;
	}
	else if (keycode == 78)
	{
		e->zoom_x = e->zoom_x / 1.1;
		e->zoom_y = e->zoom_y / 1.1;
		e->b = 1;
	}
	else if (keycode == 75)
	{
		if (e->i_max > 10)
			e->i_max -= 10;
		e->b = 1;
	}
	else if (keycode == 67)
	{
		e->i_max += 10;
		e->b = 1;
	}
}

int		key_hook(int keycode, t_env *e)
{
	if (keycode == 53)
	{
		mlx_clear_window(e->mlx, e->win);
		exit(0);
	}
	else if (keycode == 35)
	{
		if (e->mouse == 1)
			e->mouse = 0;
		else if (e->mouse == 0)
			e->mouse = 1;
	}
	zoom_iter(keycode, e);
	key_init(keycode, e);
	direction(keycode, e);
	return (0);
}
