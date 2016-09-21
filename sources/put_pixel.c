/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_pixel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmouhssi <mmouhssi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/16 23:50:42 by mmouhssi          #+#    #+#             */
/*   Updated: 2016/09/21 19:02:22 by mmouhssi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	put_pixel(char *data, int width, int heigth, int color)
{
	int index;

	if (!(width >= 0 && width <= WIDTH) || !(heigth <= HEIGHT && heigth >= 0))
		return ;
	index = (heigth * WIDTH * 4) + (width * 4);
	data[index] = (color & 0x000000ff);
	data[index + 1] = (color & 0x0000ff00) >> (2 * 4);
	data[index + 2] = (color & 0x00ff0000) >> (4 * 4);
	data[index + 3] = (color & 0xff000000) >> (6 * 4);
}
