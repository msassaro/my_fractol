/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_fract.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msassaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 14:18:17 by msassaro          #+#    #+#             */
/*   Updated: 2016/03/02 14:18:18 by msassaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_fractol_init_burningship(t_env *env)
{
	env->x1 = -1.8;
	env->x2 = 1.2;
	env->y1 = -1.5;
	env->y2 = 0.6;
	env->zoom = 200;
	env->zoom_init = 200;
	env->name = "BURNING SHIP";
	env->x_img = (env->x2 - env->x1) * env->zoom;
	env->y_img = (env->y2 - env->y1) * env->zoom;
	env->iter_max = 50;
}

void	ft_fractol_init_mandelbrot(t_env *env)
{
	env->x1 = -2.1;
	env->x2 = 0.6;
	env->y1 = -1.2;
	env->y2 = 1.2;
	env->zoom = 200;
	env->zoom_init = 200;
	env->name = "MANDELBROT";
	env->x_img = (env->x2 - env->x1) * env->zoom;
	env->y_img = (env->y2 - env->y1) * env->zoom;
	env->iter_max = 20;
}

void	ft_fractol_init_name_select(t_env *env)
{
	if (env->fractal == 2)
		env->name = "JULIA";
	else if (env->fractal == 4)
		env->name = "NEWTON";
	else if (env->fractal == 5)
		env->name = "CLOVER";
	else if (env->fractal == 6)
		env->name = "HELIOS";
	else if (env->fractal == 7)
		env->name = "JULES";
	else if (env->fractal == 8)
		env->name = "BLOB";
}

void	ft_fractol_init_iter_select(t_env *env)
{
	if (env->fractal == 2)
		env->iter_max = 50;
	else if (env->fractal == 4)
		env->iter_max = 50;
	else if (env->fractal == 5)
		env->iter_max = 50;
	else if (env->fractal == 6)
		env->iter_max = 50;
	else if (env->fractal == 7)
		env->iter_max = 30;
	else if (env->fractal == 8)
		env->iter_max = 20;
}

void	ft_fractol_init_fractal(t_env *env)
{
	env->x1 = -1.5;
	env->x2 = 1.5;
	env->y1 = -1.5;
	env->y2 = 1.5;
	env->mouse_x = 0;
	env->mouse_y = 0;
	env->zoom = 200;
	env->zoom_init = 200;
	ft_fractol_init_name_select(env);
	env->x_img = (env->x2 - env->x1) * env->zoom;
	env->y_img = (env->y2 - env->y1) * env->zoom;
	ft_fractol_init_iter_select(env);
}
