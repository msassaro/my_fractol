/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clover_newton_bship_helios.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msassaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 14:18:03 by msassaro          #+#    #+#             */
/*   Updated: 2016/03/02 14:18:05 by msassaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_fractol_newton_clover_if(t_env e)
{
	if (e.absv > 0.00001)
		e.img_tab[e.y][e.x] = 0x000000;
	else
		e.img_tab[e.y][e.x] = ft_fractol_colorize(e);
}

void	ft_fractol_clover(t_env e)
{
	e.x = -1;
	while (++e.x < e.x_img)
	{
		e.y = -1;
		while (++e.y < e.y_img)
		{
			e.z_r = (e.x / e.zoom + e.x1) * e.zoom;
			e.z_i = (e.y / e.zoom + e.y1) * e.zoom;
			e.j = -1;
			e.absv = 1;
			while ((e.absv > 0.000001) && ++e.j < e.iter_max)
			{
				e.tmp = e.z_r;
				e.tmp2 = e.z_i;
				e.r4 = (e.z_r * e.z_r + e.z_i * e.z_i)
				* (e.z_r * e.z_r + e.z_i * e.z_i);
				e.z_r = (2 * e.tmp * e.r4 + e.z_r * e.z_r - e.z_i * e.z_i)
				/ (3 * e.r4);
				e.z_i = 2 * e.tmp2 * (e.r4 - e.tmp) / (3 * e.r4);
				e.absv = (e.z_r - e.tmp) * (e.z_r - e.tmp) + (e.z_i - e.tmp2)
				* (e.z_i - e.tmp2);
			}
			ft_fractol_newton_clover_if(e);
		}
	}
}

void	ft_fractol_newton(t_env e)
{
	e.x = -1;
	while (++e.x < e.x_img)
	{
		e.y = -1;
		while (++e.y < e.y_img)
		{
			e.z_r = (e.x / e.zoom + e.x1);
			e.z_i = (e.y / e.zoom + e.y1);
			e.j = -1;
			e.absv = 1;
			while ((e.absv > 0.000001) && ++e.j < e.iter_max)
			{
				e.tmp = e.z_r;
				e.tmp2 = e.z_i;
				e.r4 = (e.z_r * e.z_r + e.z_i * e.z_i)
				* (e.z_r * e.z_r + e.z_i * e.z_i);
				e.z_r = (2 * e.tmp * e.r4 + e.z_r * e.z_r - e.z_i * e.z_i)
				/ (3 * e.r4);
				e.z_i = 2 * e.tmp2 * (e.r4 - e.tmp) / (3 * e.r4);
				e.absv = (e.z_r - e.tmp) * (e.z_r - e.tmp) + (e.z_i - e.tmp2)
				* (e.z_i - e.tmp2);
			}
			ft_fractol_newton_clover_if(e);
		}
	}
}

void	ft_fractol_burningship(t_env e)
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
				e.z_i = 2 * fabs(e.z_i * e.tmp) + e.c_i;
			}
			if (e.j == e.iter_max)
				e.img_tab[e.y][e.x] = 0x000000;
			else
				e.img_tab[e.y][e.x] = ft_fractol_colorize(e);
		}
	}
}

void	ft_fractol_helios(t_env e)
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
			while ((e.z_r * e.z_r + e.z_i * e.z_i) < 4 && ++e.j < e.iter_max)
			{
				e.tmp = e.z_r;
				e.z_r = 2 * (e.z_r) / 3 - (e.z_r * e.z_r - e.z_i * e.z_i) /
				(e.z_r * e.z_r + e.z_i * e.z_i) / (e.z_r * e.z_r + e.z_i
				* e.z_i) / 3;
				e.z_i = 2 * e.z_i / 3 + 2 * e.z_i * e.tmp / (e.tmp * e.tmp +
				e.z_i * e.z_i) / (e.tmp * e.tmp + e.z_i * e.z_i) / 3;
			}
			if (e.j == e.iter_max)
				e.img_tab[e.y][e.x] = 0x000000;
			else
				e.img_tab[e.y][e.x] = ft_fractol_colorize(e);
		}
	}
}
