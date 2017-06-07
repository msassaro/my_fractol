/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot_julia_jules_blob.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msassaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 14:18:26 by msassaro          #+#    #+#             */
/*   Updated: 2016/03/02 14:18:28 by msassaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_fractol_mandelbrot(t_env e)
{
	e.x = -1;
	while (++e.x < e.x_img)
	{
		e.y = -1;
		while (++e.y < e.y_img)
		{
			e.c_r = e.x / e.zoom + e.x1;
			e.c_i = e.y / e.zoom + e.y1;
			e.z_r = 0;
			e.z_i = 0;
			e.j = -1;
			while ((e.z_r * e.z_r + e.z_i * e.z_i) < 4 && ++e.j < e.iter_max)
			{
				e.tmp = e.z_r;
				e.z_r = e.z_r * e.z_r - e.z_i * e.z_i + e.c_r;
				e.z_i = 2 * e.z_i * e.tmp + e.c_i;
			}
			if (e.j == e.iter_max)
				e.img_tab[e.y][e.x] = 0x000000;
			else
				e.img_tab[e.y][e.x] = ft_fractol_colorize(e);
		}
	}
}

void	ft_fractol_julia(t_env e)
{
	e.x = -1;
	while (++e.x < e.x_img)
	{
		e.y = -1;
		while (++e.y < e.y_img)
		{
			e.c_r = 0.285 + e.mouse_x;
			e.c_i = 0.01 + e.mouse_y;
			e.z_r = e.x / e.zoom + e.x1;
			e.z_i = e.y / e.zoom + e.y1;
			e.j = -1;
			while ((e.z_r * e.z_r + e.z_i * e.z_i) < 4 && ++e.j < e.iter_max)
			{
				e.tmp = e.z_r;
				e.z_r = e.z_r * e.z_r - e.z_i * e.z_i + e.c_r;
				e.z_i = 2 * e.z_i * e.tmp + e.c_i;
			}
			if (e.j == e.iter_max)
				e.img_tab[e.y][e.x] = 0x000000;
			else
				e.img_tab[e.y][e.x] = ft_fractol_colorize(e);
		}
	}
}

void	ft_fractol_jules(t_env e)
{
	e.x = -1;
	while (++e.x < e.x_img)
	{
		e.y = -1;
		while (++e.y < e.y_img)
		{
			e.c_r = -1;
			e.c_i = -0.7;
			e.z_r = e.x / e.zoom + e.x1;
			e.z_i = e.y / e.zoom + e.y1;
			e.j = -1;
			while ((e.z_r * e.z_r + e.z_i * e.z_i) < 4 && ++e.j < e.iter_max)
			{
				e.tmp = e.z_r;
				e.z_r = e.z_r * e.z_r - e.z_i * e.z_i + e.c_r;
				e.z_i = 2 * e.z_i * e.tmp + e.c_i;
			}
			if (e.j == e.iter_max)
				e.img_tab[e.y][e.x] = 0x000000;
			else
				e.img_tab[e.y][e.x] = ft_fractol_colorize(e);
		}
	}
}

void	ft_fractol_blob(t_env e)
{
	e.x = -1;
	while (++e.x < e.x_img)
	{
		e.y = -1;
		while (++e.y < e.y_img)
		{
			e.z_r = e.x / e.zoom + e.x1;
			e.z_i = e.y / e.zoom + e.y1;
			e.j = -1;
			while ((e.z_r * e.z_r + e.z_i * e.z_i) < 1 && ++e.j < e.iter_max)
			{
				e.tmp = e.z_r;
				e.z_r = 5 * (e.z_r) / 6 - (e.z_r * e.z_r - e.z_i * e.z_i) /
				(e.z_r * e.z_r + e.z_i * e.z_i) / (e.z_r * e.z_r + e.z_i
				* e.z_i) / 6;
				e.z_i = 5 * e.z_i / 6 + 2 * e.z_i * e.tmp / (e.tmp * e.tmp +
				e.z_i * e.z_i) / (e.tmp * e.tmp + e.z_i * e.z_i) / 6;
			}
			if (e.j == e.iter_max)
				e.img_tab[e.y][e.x] = 0x000000;
			else
				e.img_tab[e.y][e.x] = ft_fractol_colorize(e);
		}
	}
}
