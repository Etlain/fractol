/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmouhssi <mmouhssi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/28 19:17:24 by mmouhssi          #+#    #+#             */
/*   Updated: 2016/09/24 14:49:52 by mmouhssi         ###   ########.fr       */
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
		ft_fractal(e);
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
	double tmp;	
	
	if (e->mouse == 1)
	{
		e->mx = (double)x / e->zoom_x + e->x1;
		e->my = (double)y / e->zoom_y + e->y1;
		tmp = e->mx * e->my;
		if (tmp != 0)
			e->f = tmp;
		printf("test %f\n", tmp);
		e->b = 1;
		//printf("%f\n", e->mx);
		//printf("%f %f\n", e->mx, e->my);
	}
	return (0);
}

double	ft_abs_d(double nbr)
{
	return (nbr > 0 ? nbr : (nbr * -1));
}
/*
int		mouse_hook(int button, int x, int y, t_env *e)
{
	double middle;
	if (button == 1)
	{
		if (e->x1 < 0)
			middle = (e->x2 + e->x1) / (double)2.0;
		else
			middle = e->x1 + (e->x2 - e->x1) / (double)2.0;
		printf("middle : %f\n", middle);
		if (e->mx < middle)
		{
			if (middle > 0 && e->mx < 0)
			{
				e->x1 -= ft_abs_d(middle + e->mx); //- 1;
				e->x2 -= ft_abs_d(middle + e->mx); //+ 1;
			}
			else
			{
				e->x1 -= ft_abs_d(middle - e->mx); //- 1;
				e->x2 -= ft_abs_d(middle - e->mx);
			}
		}
		else
		{
			if (e->mx > 0 && middle < 0)
			{
				e->x1 += ft_abs_d(e->mx + middle); //- 1;
				e->x2 += ft_abs_d(e->mx + middle); //+ 1;
			}
			else
			{
				printf("cal : %f\n", e->mx);
				e->x1 += ft_abs_d(e->mx - middle); //- 1;
				e->x2 += ft_abs_d(e->mx - middle);
			}
		}
		//printf("cal : %f, %f\n", e->x1, e->x2);
		if (e->y1 < 0)
			middle = (e->y2 + e->y1) / (double)2.0;
		else
			middle = e->y1 + (e->y2 - e->y1) / (double)2.0;
		if (e->my < middle)
		{
			if (middle > 0 && e->my < 0)
			{
				e->y1 -= ft_abs_d(middle + e->my); //- 1;
				e->y2 -= ft_abs_d(middle + e->my); //+ 1;
			}
			else
			{
				e->y1 -= ft_abs_d(middle - e->my); //- 1;
				e->y2 -= ft_abs_d(middle - e->my);
			}
		}
		else
		{
			if (e->mx > 0 && middle < 0)
			{
				e->y1 += ft_abs_d(e->my + middle); //- 1;
				e->y2 += ft_abs_d(e->my + middle); //+ 1;
			}
			else
			{
				printf("cal : %f\n", e->my);
				e->y1 += ft_abs_d(e->my - middle); //- 1;
				e->y2 += ft_abs_d(e->my - middle);
			}
		}
		e->x1 /= 1.1;
		e->x2 /= 1.1;
		e->y1 /= 1.1;
		e->y2 /= 1.1;
		e->zoom_x *= 1.1;
		e->zoom_y *= 1.1;
		//printf("cal : %f\n", middle);
		//e->y1 += e->my - e->y1 + middle; //- 1;
		//e->y2 += e->my - e->y1 + middle; //+ 1;
		e->b = 1;
	}
	if (button == 2)
	{
		e->x1 = e->mx + 1;
		e->x2 = e->mx - 1;
		e->y1 = e->my + 1;
		e->y2 = e->my - 1;
		e->zoom_x = e->zoom_x / 1.1;
		e->zoom_y = e->zoom_y / 1.1;
		e->b = 1;
	}
	return (0);
}
*/

void	direction(int keycode, t_env *e)
{
	if (keycode == 123)
	{
		e->x1 -= 100 / e->zoom_x ; // depend du zoom
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
	else if (keycode == 15)
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
	else if (keycode == 35)
	{
		if (e->mouse == 1)
			e->mouse = 0;
		else if (e->mouse == 0)
			e->mouse = 1;
	}
	direction(keycode, e);
	return (0);
}
