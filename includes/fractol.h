/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmouhssi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/21 12:42:15 by mmouhssi          #+#    #+#             */
/*   Updated: 2016/09/21 15:46:18 by mmouhssi         ###   ########.fr       */
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
	double x1;
	double x2;
	double y1;
	double y2;
	double zoom_y;
	double zoom_x;
	double c_r;
	double c_i;
	double z_r;
	double z_i;
}				t_env;

#endif
