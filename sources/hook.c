/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmouhssi <mmouhssi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/28 19:17:24 by mmouhssi          #+#    #+#             */
/*   Updated: 2016/09/26 15:08:35 by mmouhssi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int		close_hook(void)
{
	exit(0);
	return (0);
}

int		expose_hook(t_env *e)
{
	int sizeline;
	int bpp;
	int endian;

	if (e->b == 1)
	{
		e->img = mlx_new_image(e->mlx, WIDTH, HEIGHT);
		e->data = mlx_get_data_addr(e->img, &bpp, &sizeline, &endian);
		ft_fractal(e);
		mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
		mlx_destroy_image(e->mlx, e->img);
		e->b = 0;
	}
	return (0);
}

int		pos_mouse(int x, int y, t_env *e)
{
	double tmp;

	if (e->mouse == 1)
	{
		e->mx = (double)x / e->zoom_x + e->x1;
		e->my = (double)y / e->zoom_y + e->y1;
		tmp = e->mx * e->my;
		if (tmp != 0)
			e->f = tmp;
		e->b = 1;
	}
	return (0);
}

int		mouse_hook(int button, int x, int y, t_env *e)
{
	if (button == 4)
	{
		e->zoom_x = e->zoom_x * 1.1;
		e->zoom_y = e->zoom_y * 1.1;
		e->b = 1;
	}
	else if (button == 5)
	{
		e->zoom_x = e->zoom_x / 1.1;
		e->zoom_y = e->zoom_y / 1.1;
		e->b = 1;
	}
	return (0);
}
