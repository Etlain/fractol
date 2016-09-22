/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmouhssi <mmouhssi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/28 19:17:24 by mmouhssi          #+#    #+#             */
/*   Updated: 2016/09/22 19:02:20 by mmouhssi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

#include <stdio.h>

int		close_hook(void)
{
	exit(0);
	return (0); // gerer leaks
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
		ft_mandelbrot(e);
		mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
		mlx_destroy_image(e->mlx, e->img);
		e->b = 0;
	}
	return (0);
}

int		pos_mouse(int x, int y, t_env *e)
{
//	double h;
//	double w;	
	e->mx = (double)x / e->zoom_x + e->x1;
	e->my = (double)y / e->zoom_y + e->y1;
	printf("%f %f\n", e->mx, e->my);
	return (0);
}


int		mouse_hook(int button, int x, int y, t_env *e)
{
	if (button == 1)
	{
		e->x1 = e->mx - 1;
		e->x2 = e->mx + 1;
		e->y1 = e->my - 1;
		e->y2 = e->my + 1;
		e->zoom_x = e->zoom_x * 1.1;
		e->zoom_y = e->zoom_y * 1.1;
		e->b = 1;
	}
	/*if (button == 2)
	{
		e->x1 = e->mx + 1;
		e->x2 = e->mx - 1;
		e->y1 = e->my + 1;
		e->y2 = e->my - 1;
		e->zoom_x = e->zoom_x / 1.1;
		e->zoom_y = e->zoom_y / 1.1;
		e->b = 1;
	}*/
	return (0);
}


void	direction(int keycode, t_env *e)
{
	if (keycode == 123)
	{
		e->x1 -= 0.1 /* /e->zoom */; // depend du zoom
		e->x2 -= 0.1;
		e->b = 1;
	}
	if (keycode == 124)
	{
		e->x1 += 0.1;
		e->x2 += 0.1;
		e->b = 1;
	}
	if (keycode == 125)
	{
		e->y1 -= 0.1;
		e->y2 -= 0.1;
		e->b = 1;
	}
	if (keycode == 126)
	{
		e->y1 += 0.1;
		e->y2 += 0.1;
		e->b = 1;
	}
	printf("key : %d\n", keycode);
	printf("val x : %f, %f\n", e->x1, e->x2);
	printf("val y : %f, %f\n", e->y1, e->y2);
}

int		key_hook(int keycode, t_env *e)
{
	if (keycode == 53)
	{
		mlx_clear_window(e->mlx, e->win);
		//free_lst(env->map);
	//	free_env() si necessaire // gerer leaks
		//mlx destroy image
		exit(0);
	}
	else if (keycode == 69)
	{
		//e->x1 = e->x1 + 1; // en haut a droite
		//e->y2 = e->y2 - 1;
	/*	e->x1 = e->x1 + 1; // en haut a droite
		e->y2 = e->y2 - 1;	
	*/	//e->x1 = e->x2 + 0.1;
		/*e->y2 = e->y2 + 0.01;*/
		e->zoom_x = e->zoom_x * 1.1;
		e->zoom_y = e->zoom_y * 1.1;
		
		e->b = 1;
		//mlx_mouse_hook(e->win, mouse_hook, e);
	}
	else if (keycode == 78/* && *(int *)env->zoom > 0*/)
	{
		//e->x1 = e->x1 - 1;
		//e->y2 = e->y2 + 1;
	/*	e->x1 = e->x2 - 0.01;
		e->y2 = e->y2 + 0.01;*/
		e->zoom_x = e->zoom_x / 1.1;
		e->zoom_y = e->zoom_y / 1.1;
		e->b = 1;	
	}
	direction(keycode, e);
	/*if (keycode >= 123 && keycode <= 126)
		*(int *)env->p[5] = 1;
	redraw(env);*/
	return (0);
}
