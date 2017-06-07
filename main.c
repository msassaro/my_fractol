/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msassaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/23 11:15:17 by msassaro          #+#    #+#             */
/*   Updated: 2016/03/02 14:20:37 by msassaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_fractol_parse_graphic(t_env env)
{
	if (env.fractal == 1)
		ft_fractol_mandelbrot(env);
	else if (env.fractal == 2)
		ft_fractol_julia(env);
	else if (env.fractal == 3)
		ft_fractol_burningship(env);
	else if (env.fractal == 4)
		ft_fractol_newton(env);
	else if (env.fractal == 5)
		ft_fractol_clover(env);
	else if (env.fractal == 6)
		ft_fractol_helios(env);
	else if (env.fractal == 7)
		ft_fractol_jules(env);
	else if (env.fractal == 8)
		ft_fractol_blob(env);
	else
		ft_fractol_error();
}

void	ft_fractol_parse(t_env env)
{
	ft_fractol_envinit(&env);
	ft_fractol_parse_graphic(env);
	mlx_hook(env.win, 2, 0, ft_fractol_keyhook, &env);
	mlx_mouse_hook(env.win, ft_fractol_mousehook, &env);
	if (env.fractal == 2)
		mlx_hook(env.win, 6, (1L << 6), ft_fractol_mousemove, &env);
	mlx_put_image_to_window(env.mlx, env.win, env.img, env.x_ori, env.y_ori);
	ft_fractol_menu(&env);
	mlx_loop(env.mlx);
}

void	ft_fractol_fractal_select_input(t_env *env, char *av)
{
	if (ft_strequ(ft_str_tolower(av), "mandelbrot"))
		env->fractal = 1;
	else if (ft_strequ(ft_str_tolower(av), "julia"))
		env->fractal = 2;
	else if (ft_strequ(ft_str_tolower(av), "bship"))
		env->fractal = 3;
	else if (ft_strequ(ft_str_tolower(av), "newton"))
		env->fractal = 4;
	else if (ft_strequ(ft_str_tolower(av), "clover"))
		env->fractal = 5;
	else if (ft_strequ(ft_str_tolower(av), "helios"))
		env->fractal = 6;
	else if (ft_strequ(ft_str_tolower(av), "jules"))
		env->fractal = 7;
	else if (ft_strequ(ft_str_tolower(av), "blob"))
		env->fractal = 8;
	else
		env->fractal = 0;
}

int		main(int ac, char **av)
{
	t_env	env;

	if (ac == 2)
	{
		ft_fractol_fractal_select_input(&env, av[1]);
		if (env.fractal == 0)
		{
			ft_fractol_error();
			return (0);
		}
		ft_fractol_welecome();
		ft_fractol_parse(env);
	}
	else
		ft_fractol_error();
	return (0);
}
