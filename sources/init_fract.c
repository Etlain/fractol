/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_fract.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmouhssi <mmouhssi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/16 23:50:42 by mmouhssi          #+#    #+#             */
/*   Updated: 2016/09/26 14:52:05 by mmouhssi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	init_julia(t_env *e)
{
	e->mouse = 0;
	e->f = 1;
	e->fractal = 2;
	e->x1 = -2;
	e->x2 = 2;
	e->y1 = -2.4;
	e->y2 = 2.4;
	e->zoom_y = HEIGHT / (e->y2 - e->y1);
	e->zoom_x = WIDTH / (e->x2 - e->x1);
	e->i_max = 100;
	e->b = 0;
}

void	init_mandel(t_env *e)
{
	e->fractal = 1;
	e->x1 = -2.1;
	e->x2 = 0.6;
	e->y1 = -1.2;
	e->y2 = 1.2;
	e->zoom_y = HEIGHT / (e->y2 - e->y1);
	e->zoom_x = WIDTH / (e->x2 - e->x1);
	e->i_max = 50;
	e->b = 0;
}

void	init_burning(t_env *e)
{
	e->fractal = 3;
	e->x1 = -3;
	e->x2 = 2;
	e->y1 = -3;
	e->y2 = 2;
	e->zoom_y = HEIGHT / (e->y2 - e->y1);
	e->zoom_x = WIDTH / (e->x2 - e->x1);
	e->i_max = 50;
	e->b = 0;
}

void	init_fract(t_env *e)
{
	if (e->fractal == 1)
		init_mandel(e);
	else if (e->fractal == 2)
		init_julia(e);
	else if (e->fractal == 3)
		init_burning(e);
}
