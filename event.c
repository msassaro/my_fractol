/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msassaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 14:18:11 by msassaro          #+#    #+#             */
/*   Updated: 2016/03/02 14:18:14 by msassaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		ft_fractol_mousemove(int x, int y, void *param)
{
	t_env	*e;

	e = (t_env*)param;
	if (x <= e->x_img && y <= e->y_img
			&& x >= -e->x_img && y >= -e->y_img)
	{
		e->mouse_x = x * 0.001;
		e->mouse_y = y * 0.001;
		mlx_clear_window(e->mlx, e->win);
		ft_fractol_parse_graphic(*e);
		mlx_put_image_to_window(e->mlx, e->win, e->img,
				e->x_ori, e->y_ori);
		ft_fractol_menu(e);
	}
	return (0);
}

int		ft_fractol_keyhook(int key, void *param)
{
	t_env	*env;

	env = (t_env*)param;
	if (key == 53)
	{
		mlx_destroy_window(env->mlx, env->win);
		exit(0);
	}
	if (key == 8)
		ft_fractol_color_change(env);
	if (key == 123 || key == 124 || key == 125 || key == 126)
		ft_fractol_move(key, env);
	if (key == 6 || key == 7)
		ft_fractol_move_pad(key, env);
	if (key == 0 || key == 1)
		ft_fractol_move_iter(key, env);
	if (key == 15)
		ft_fractol_reinit(env);
	return (0);
}

void	ft_fractol_zoom_in(t_env *e, int x, int y)
{
	double	new_x;
	double	new_y;
	double	tmp[4];

	new_x = 0;
	new_y = 0;
	tmp[0] = e->x1;
	tmp[1] = e->x2;
	tmp[2] = e->y1;
	tmp[3] = e->y2;
	e->zoom *= 2;
	e->iter_max += 20;
	new_x = e->x1 + x * (e->x2 - e->x1) / e->x_img;
	new_y = e->y1 + y * (e->y2 - e->y1) / e->y_img;
	e->x1 = new_x - (tmp[1] - tmp[0]) / 4;
	e->x2 = new_x + (tmp[1] - tmp[0]) / 4;
	e->y1 = new_y - (tmp[3] - tmp[2]) / 4;
	e->y2 = new_y + (tmp[3] - tmp[2]) / 4;
	mlx_clear_window(e->mlx, e->win);
	ft_fractol_parse_graphic(*e);
	mlx_put_image_to_window(e->mlx, e->win, e->img, e->x_ori, e->y_ori);
	ft_fractol_menu(e);
}

void	ft_fractol_zoom_out(t_env *e, int x, int y)
{
	double	new_x;
	double	new_y;
	double	tmp[4];

	new_x = 0;
	new_y = 0;
	tmp[0] = e->x1;
	tmp[1] = e->x2;
	tmp[2] = e->y1;
	tmp[3] = e->y2;
	e->zoom /= 2;
	e->iter_max -= 20;
	new_x = e->x1 + x * (e->x2 - e->x1) / e->x_img;
	new_y = e->y1 + y * (e->y2 - e->y1) / e->y_img;
	e->x1 = new_x - (tmp[1] - tmp[0]);
	e->x2 = new_x + (tmp[1] - tmp[0]);
	e->y1 = new_y - (tmp[3] - tmp[2]);
	e->y2 = new_y + (tmp[3] - tmp[2]);
	mlx_clear_window(e->mlx, e->win);
	ft_fractol_parse_graphic(*e);
	mlx_put_image_to_window(e->mlx, e->win, e->img, e->x_ori, e->y_ori);
	ft_fractol_menu(e);
}

int		ft_fractol_mousehook(int click, int x, int y, void *param)
{
	t_env	*env;

	env = (t_env*)param;
	if ((click == 1 || click == 4) && x <= env->x_img && x >= 0
			&& y <= env->y_img && y >= 0)
		ft_fractol_zoom_in(env, x, y);
	if ((click == 2 || click == 5) && x <= env->x_img && x >= 0
			&& y <= env->y_img && y >= 0 && env->zoom > env->zoom_init)
		ft_fractol_zoom_out(env, x, y);
	return (0);
}
