/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmouhssi <mmouhssi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/16 23:50:42 by mmouhssi          #+#    #+#             */
/*   Updated: 2016/09/21 15:45:18 by mmouhssi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <mlx.h>
//#include "minilibx_macos/mlx.h"
//#include <fcntl.h>
#include "../includes/fractol.h"

/*
int	key_hook(int keycode, void *ptr, void *win)
{
	if (keycode == 53)
	{
		mlx_clear_window(ptr, win);
		exit(0);
	}
	return (0);
}
*/
int	close_hook(int keycode, void *ptr, void *win)
{
	//if (keycode == 53)
	//{
		//mlx_clear_window(ptr, win);
		exit(0);
	//}
	return (0);
}

void	put_pixel(char *data, int width, int heigth, int color) // Necessite les constante max
{
	int index;

	if (!(width >= 0 && width <= WIDTH) || !(heigth <= HEIGHT && heigth >= 0))
		return ;
	index = (heigth * WIDTH * 4) + (width * 4);
	data[index] = (color & 0x000000ff);/*(color & 0x0000ff00)*//* >> (2 * 4) << (4 * 4)*/ // color & 0xff0000
	data[index + 1] = (color & 0x0000ff00) >> (2 * 4);
	data[index + 2] = (color & 0x00ff0000) >> (4 * 4);/*(color*/ /*& 0xff000000*///);
	data[index + 3] = (color & 0xff000000) >> (6 * 4);
	//ft_printf("put pixel : %d %d %d %d %d\n", color, data[index], data[index + 0], data[index + 2], data[index + 3]);
}

#include <stdio.h>

void ft_test2(char *data)
{
	double x1 = -1;
	double x2 = 1;
	double y1 = -1.2;
	double y2 = 1.2;
	double zoom_y = HEIGHT / (y2 - y1); // variable a definir a l exterieur
	double zoom_x = WIDTH / (x2 - x1);
	double zoom = 100;
	int iteration_max = 100;
	int x = 0;
	int y = 0;
	double c_r;
	double c_i;
	double z_r;
	double z_i;
	int i = 0;
	double tmp;

	//double image_x = ((x2 - x1) * zoom);
	//double image_y = ((y2 - y1) * zoom);
	while (x < HEIGHT)
	{
		y = 0;
		while (y < WIDTH)
		{
			z_r = x / zoom_x + x1;
			z_i = y / zoom_y + y1;
			c_r = 0.285;
			c_i = 0.01;
			i = 0;
			while (i < iteration_max && ((z_r * z_r) + (z_i * z_i)) < 4)
			{
				tmp = z_r;
				z_r = z_r * z_r - z_i * z_i + c_r;
				z_i = 2 * z_i * tmp + c_i;
				i++;
			}
			if (i == iteration_max)
				put_pixel(data, x, y, 0xffffff);
			y++;
		}
		x++;
	}
}

void ft_test(char *data)
{
	double x1 = -2.1;
	double x2 = 0.6;
	double y1 = -1.2;
	double y2 = 1.2;
	double zoom_y = HEIGHT / (y2 - y1); // variable a definir a l exterieur
	double zoom_x = WIDTH / (x2 - x1);
	//double zoom_y = 550;
	//double zoom_x = 500;
	int iteration_max = 50;
	int x = 0;
	int y = 0;
	double c_r;
	double c_i;
	double z_r;
	double z_i;
	int i = 0;
	double tmp;

	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			c_r = x / zoom_x + x1;
			c_i = y / zoom_y + y1;
			z_r = 0;
			z_i = 0;
			i = 0;
			while (i < iteration_max && ((z_r * z_r) + (z_i * z_i)) < 4)
			{
				tmp = z_r;
				z_r = z_r * z_r - z_i * z_i + c_r;
				z_i = 2 * z_i * tmp + c_i;
				i++;
			}
			if (i == iteration_max)
				put_pixel(data, x, y, 0xffffff);
			x++;
		}
		y++;
	}
}

// iteration, zoom, deplacement

int main()
{
	void *mlx;
	void *win;
	void *img;
	char *data;
	int sizeline;
	int bpp;
	int endian;

	bpp = 0;
	sizeline = 0;
	endian = 0;
	mlx = mlx_init();
	win = mlx_new_window(mlx, WIDTH, HEIGHT, "test");
	img = mlx_new_image(mlx, WIDTH, HEIGHT);
	data = mlx_get_data_addr(img, &bpp, &sizeline, &endian);
	ft_test(data);
	//put_pixel(data, 100, 100, 0xffffff);
	//ft_printf("test : %x\n", 0x000000ff);
	mlx_put_image_to_window(mlx, win, img, 0, 0);
	mlx_hook(win, 17, 1, close_hook, NULL);
	mlx_loop(mlx);
	return (0);
}
