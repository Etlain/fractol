/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmouhssi <mmouhssi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/16 23:50:42 by mmouhssi          #+#    #+#             */
/*   Updated: 2016/09/22 19:02:28 by mmouhssi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <mlx.h>
//#include "minilibx_macos/mlx.h"
//#include <fcntl.h>
#include "../includes/fractol.h"



#include <stdio.h>
// iteration, zoom, deplacement

void	init_env(t_env *e)
{
	e->mlx = NULL;
	e->win = NULL;
	e->img = NULL;
	e->x1 = -2.1;
	e->x2 = 0.6;
	e->y1 = -1.2;
	e->y2 = 1.2;
	e->zoom_y = HEIGHT / (e->y2 - e->y1);
	e->zoom_x = WIDTH / (e->x2 - e->x1);
	e->i_max = 50;
	e->b = 0;
}

int main()
{
	/*void *mlx;
	void *win;
	void *img;*/
	t_env e;
	char *data;
	int sizeline;
	int bpp;
	int endian;

	bpp = 0;
	sizeline = 0;
	endian = 0;
	init_env(&e);
	e.mlx = mlx_init();
	e.win = mlx_new_window(e.mlx, WIDTH, HEIGHT, "test");
	e.img = mlx_new_image(e.mlx, WIDTH, HEIGHT);
	e.data = mlx_get_data_addr(e.img, &bpp, &sizeline, &endian);
	ft_mandelbrot(&e);
	//put_pixel(data, 100, 100, 0xffffff);
	//ft_printf("test : %x\n", 0x000000ff);
	mlx_put_image_to_window(e.mlx, e.win, e.img, 0, 0);
	mlx_destroy_image(e.mlx, e.img);
	mlx_hook(e.win, 2, 1, key_hook, &e);
	mlx_hook(e.win, 6, 1, pos_mouse, &e);
	mlx_hook(e.win, 17, 1, close_hook, NULL);
	mlx_mouse_hook(e.win, mouse_hook, &e);
	mlx_loop_hook(e.mlx, expose_hook, &e);
	mlx_loop(e.mlx);
	return (0);
}
