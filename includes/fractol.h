/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmouhssi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/21 12:42:15 by mmouhssi          #+#    #+#             */
/*   Updated: 2016/09/26 15:12:56 by mmouhssi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include "../libft/includes/libft.h"
# include "../minilibx_macos/mlx.h"
# define HEIGHT 800
# define WIDTH 800

typedef struct	s_env
{
	void		*mlx;
	void		*win;
	void		*img;
	char		*data;
	int			fractal;
	int			mouse;
	double		f;
	double		mx;
	double		my;
	double		x1;
	double		x2;
	double		y1;
	double		y2;
	double		zoom_y;
	double		zoom_x;
	int			i_max;
	int			b;
	double		c_r;
	double		c_i;
	double		z_r;
	double		z_i;
}				t_env;

void			put_pixel(char *data, int width, int heigth, int color);
int				close_hook(void);
int				key_hook(int keycode, t_env *e);
int				expose_hook(t_env *e);
int				mouse_hook(int button, int x, int y, t_env *e);
int				pos_mouse(int x, int y, t_env *e);
void			init_fract(t_env *e);
void			ft_fractal(t_env *e);
void			init_mandel(t_env *e);
void			init_burning(t_env *e);
void			init_julia(t_env *e);

#endif
