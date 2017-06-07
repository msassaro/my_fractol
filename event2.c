/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msassaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 14:18:14 by msassaro          #+#    #+#             */
/*   Updated: 2016/03/02 14:18:15 by msassaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_fractol_color_change(t_env *e)
{
	e->color_index += 1;
	mlx_clear_window(e->mlx, e->win);
	ft_fractol_parse_graphic(*e);
	mlx_put_image_to_window(e->mlx, e->win, e->img, e->x_ori, e->y_ori);
	ft_fractol_menu(e);
}

void	ft_fractol_move(int key, t_env *e)
{
	if (key == 124)
	{
		e->x1 += 0.01 * e->move_pad;
		e->x2 -= 0.01 * e->move_pad;
	}
	if (key == 123)
	{
		e->x1 -= 0.01 * e->move_pad;
		e->x2 += 0.01 * e->move_pad;
	}
	if (key == 125)
	{
		e->y1 += 0.01 * e->move_pad;
		e->y2 -= 0.01 * e->move_pad;
	}
	if (key == 126)
	{
		e->y1 -= 0.01 * e->move_pad;
		e->y2 += 0.01 * e->move_pad;
	}
	mlx_clear_window(e->mlx, e->win);
	ft_fractol_parse_graphic(*e);
	mlx_put_image_to_window(e->mlx, e->win, e->img, e->x_ori, e->y_ori);
	ft_fractol_menu(e);
}

void	ft_fractol_move_pad(int key, t_env *e)
{
	if (key == 6 && e->move_pad <= 50)
		e->move_pad += 1;
	if (key == 7 && e->move_pad > 1)
		e->move_pad -= 1;
	mlx_clear_window(e->mlx, e->win);
	ft_fractol_parse_graphic(*e);
	mlx_put_image_to_window(e->mlx, e->win, e->img, e->x_ori, e->y_ori);
	ft_fractol_menu(e);
}

void	ft_fractol_move_iter(int key, t_env *e)
{
	if (key == 0 && e->iter_max <= 500)
		e->iter_max += 10;
	if (key == 1 && e->iter_max > 15)
		e->iter_max -= 10;
	mlx_clear_window(e->mlx, e->win);
	ft_fractol_parse_graphic(*e);
	mlx_put_image_to_window(e->mlx, e->win, e->img, e->x_ori, e->y_ori);
	ft_fractol_menu(e);
}

void	ft_fractol_reinit(t_env *e)
{
	ft_fractol_init_chooser(e);
	mlx_clear_window(e->mlx, e->win);
	ft_fractol_parse_graphic(*e);
	mlx_put_image_to_window(e->mlx, e->win, e->img, e->x_ori, e->y_ori);
	ft_fractol_menu(e);
}
