/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmouhssi <mmouhssi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/28 19:17:24 by mmouhssi          #+#    #+#             */
/*   Updated: 2016/09/24 17:02:16 by mmouhssi         ###   ########.fr       */
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

double	ft_abs_d(double nbr) // biblio ajout
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
