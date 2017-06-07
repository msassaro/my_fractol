/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_init_color.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msassaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 14:18:08 by msassaro          #+#    #+#             */
/*   Updated: 2016/03/02 14:19:35 by msassaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		ft_fractol_colorize(t_env env)
{
	int		color;
	int		r;
	int		g;
	int		b;

	r = env.color_index * 0x00FF0000 * env.j * 5 / env.iter_max;
	g = env.color_index * 0x0000FF00 * env.j * 56 / env.iter_max;
	b = env.color_index * 0x000000FF * env.j * 256 / env.iter_max;
	color = r + g + b;
	return (color);
}

int		**ft_fractol_img_tab_create(t_env env)
{
	int		**img_tab;
	int		i;

	i = 0;
	img_tab = (int**)malloc(sizeof(int*) * ((int)env.y_img + 1));
	while (i < (int)env.y_img)
	{
		img_tab[i] = &env.tab[i * (int)env.x_img];
		i++;
	}
	return (img_tab);
}

void	ft_fractol_init_chooser(t_env *env)
{
	if (env->fractal == 1)
		ft_fractol_init_mandelbrot(env);
	else if (env->fractal == 3)
		ft_fractol_init_burningship(env);
	else if (env->fractal == 2 || env->fractal == 4 || env->fractal == 5
	|| env->fractal == 6 || env->fractal == 7 || env->fractal == 8)
		ft_fractol_init_fractal(env);
	else
		ft_fractol_error();
}

void	ft_fractol_envinit(t_env *e)
{
	ft_fractol_init_chooser(e);
	e->mlx = mlx_init();
	e->win = mlx_new_window(e->mlx, e->x_img, e->y_img,
			ft_strjoin("Represented Fractal: ", e->name));
	e->color_index = 1;
	e->x_ori = 0;
	e->y_ori = 0;
	e->move_pad = 5;
	e->iter_pad = 30;
	e->img = mlx_new_image(e->mlx, e->x_img, e->y_img);
	e->tab = (int*)mlx_get_data_addr(e->img, &e->bits, &e->size, &e->end);
	e->img_tab = ft_fractol_img_tab_create(*e);
}
