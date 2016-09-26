/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmouhssi <mmouhssi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/16 23:50:42 by mmouhssi          #+#    #+#             */
/*   Updated: 2016/09/26 15:47:42 by mmouhssi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static void	param(t_env *e, char **argv, int argc)
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

static void	key(void)
{
	ft_putstr("fleches      :\tdeplacements\n");
	ft_putstr("zoom         :\t+ - molette\n");
	ft_putstr("reinitialiser:\tr\n");
	ft_putstr("fractales    :\t1 2 3\n");
	ft_putstr("iterations   :\t/ *\n");
	ft_putstr("param julia  :\tp\n");
	ft_putstr("quitter      :\techap\n");
}

int			main(int argc, char **argv)
{
	t_env	e;
	char	*data;
	int		sizeline;
	int		bpp;
	int		endian;

	bpp = 0;
	sizeline = 0;
	endian = 0;
	param(&e, argv, argc);
	key();
	e.mlx = mlx_init();
	e.win = mlx_new_window(e.mlx, WIDTH, HEIGHT, "test");
	e.img = mlx_new_image(e.mlx, WIDTH, HEIGHT);
	e.data = mlx_get_data_addr(e.img, &bpp, &sizeline, &endian);
	ft_fractal(&e);
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
