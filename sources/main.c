/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmouhssi <mmouhssi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/16 23:50:42 by mmouhssi          #+#    #+#             */
/*   Updated: 2016/09/23 23:46:48 by mmouhssi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <mlx.h>
//#include "minilibx_macos/mlx.h"
//#include <fcntl.h>
#include "../includes/fractol.h"



#include <stdio.h>
// iteration, zoom, deplacement

void	init_julia(t_env *e)
{
	/*e->mlx = NULL;
	e->win = NULL;
	e->img = NULL;*/
	e->fractal = 2;
	e->x1 = -2;
	e->x2 = 2;//0.6;
	e->y1 = -2.4;//-1.2;
	e->y2 = 2.4;//1.2;
	e->zoom_y = HEIGHT / (e->y2 - e->y1);
	e->zoom_x = WIDTH / (e->x2 - e->x1);
	e->i_max = 100;
	e->b = 0;
}

void	init_mandel(t_env *e)
{
	/*e->mlx = NULL;
	e->win = NULL;
	e->img = NULL;*/
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
	/*e->mlx = NULL;
	e->win = NULL;
	e->img = NULL;*/
	e->fractal = 3;
	e->x1 = -3;//-2.1;
	e->x2 = 2;//0.6;
	e->y1 = -3;//-1.2;
	e->y2 = 2;//1.2;
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

void param(t_env *e, char **argv, int argc)
{
	if (argc == 2)
	{
		if (ft_strcmp(argv[1], "mandelbrot") == 0)
			init_mandel(e);
		else if (ft_strcmp(argv[1], "julia") == 0)
			init_julia(e);
		else if (ft_strcmp(argv[1], "burningship") == 0)
			init_burning(e);
		else
		{
			ft_printf("param :\nburningship\nmandelbrot\njulia\n");
			exit(0);
		}

	}
	else
	{
		ft_printf("param :\n\tburningship\n\tmandelbrot\n\tjulia\n");
		exit(0);
	}
}

void	ft_fractal(t_env *e)
{
	if (e->fractal == 1)
		ft_mandelbrot(e);
	else if (e->fractal == 2)
		ft_julia(e);
	else if (e->fractal == 3)
		ft_burningship(e);
}

int main(int argc, char **argv)
{
	t_env e;
	char *data;
	int sizeline;
	int bpp;
	int endian;

	bpp = 0;
	sizeline = 0;
	endian = 0;
	//init_env(&e);
	//init_julia(&e);
	//init_burning(&e);
	//init_mander(&e);
	param(&e, argv, argc);
	e.mlx = mlx_init();
	e.win = mlx_new_window(e.mlx, WIDTH, HEIGHT, "test");
	e.img = mlx_new_image(e.mlx, WIDTH, HEIGHT);
	e.data = mlx_get_data_addr(e.img, &bpp, &sizeline, &endian);
	ft_fractal(&e);
	//ft_julia(&e);
	//ft_mandelbrot(&e);
	//ft_burningship(&e);
	//put_pixel(data, 100, 100, 0xffffff);
	//ft_printf("test : %x\n", 0x000000ff);
	mlx_put_image_to_window(e.mlx, e.win, e.img, 0, 0);
	mlx_destroy_image(e.mlx, e.img);
	mlx_hook(e.win, 2, 1, key_hook, &e);
	//mlx_hook(e.win, 6, 1, pos_mouse, &e);
	mlx_hook(e.win, 17, 1, close_hook, NULL);
	mlx_mouse_hook(e.win, mouse_hook, &e);
	mlx_loop_hook(e.mlx, expose_hook, &e);
	mlx_loop(e.mlx);
	return (0);
}
