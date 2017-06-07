/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   user_x.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msassaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 14:18:30 by msassaro          #+#    #+#             */
/*   Updated: 2016/03/02 14:21:13 by msassaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_fractol_choices(void)
{
	ft_printf("	{yellow}available inputs:{eoc}\n");
	ft_printf("{blue}+---------------+---------------+\n|{eoc}");
	ft_printf("     {green}JULIA{eoc}     ");
	ft_printf("{blue}|{eoc}   {green}MANDELBROT{eoc}  {blue}|{eoc}\n");
	ft_printf("{blue}+---------------+---------------+\n|{eoc}");
	ft_printf("     {green}BSHIP{eoc}     ");
	ft_printf("{blue}|{eoc}     {green}NEWTON{eoc}    {blue}|{eoc}\n");
	ft_printf("{blue}+---------------+---------------+\n|{eoc}");
	ft_printf("     {green}JULES{eoc}     ");
	ft_printf("{blue}|{eoc}     {green}HELIOS{eoc}    {blue}|{eoc}\n");
	ft_printf("{blue}+---------------+---------------+\n|{eoc}");
	ft_printf("     {green}CLOVER{eoc}    ");
	ft_printf("{blue}|{eoc}      {green}BLOB{eoc}     {blue}|{eoc}\n");
	ft_printf("{blue}+---------------+---------------+\n{eoc}");
}

void	ft_fractol_error(void)
{
	ft_printf("{red}/-------------------------------\\\n");
	ft_printf(" 	{underline}ERROR TO FRACTOL{reset}\n");
	ft_printf("{red}\\-------------------------------/\n\n");
	ft_printf("	{underline}ERROR{reset} ");
	ft_printf("{yellow}detected\n\n	Please choose\n	below{eoc}\n\n");
	ft_fractol_choices();
	exit(0);
}

void	ft_fractol_welecome(void)
{
	ft_printf("{green}/-------------------------------\\\n");
	ft_printf("	{underline}WELECOME TO FRACTOL{reset}\n");
	ft_printf("{green}\\-------------------------------/{eoc}\n\n");
	ft_printf("{blue}	    CONTROLS:\n");
	ft_printf("	------------------\n");
	ft_printf("    ESC		QUIT program\n");
	ft_printf("    c		change color\n");
	ft_printf("    Arrows	MOVE\n");
	ft_printf("    z/x		+/- move pad\n");
	ft_printf("    mouse	zoom in/out(+scroll)\n");
	ft_printf("    a/s		+/- iter\n");
	ft_printf("    r		re-initialize fractal\n");
	ft_printf("	------------------{eoc}\n\n");
	ft_fractol_choices();
}

void	ft_fractol_menu(t_env *env)
{
	char	*zoom;
	char	*move_pad;
	char	*iter;

	zoom = ft_itoa(env->zoom / env->zoom_init);
	move_pad = ft_itoa(env->move_pad);
	iter = ft_itoa(env->iter_max);
	mlx_string_put(env->mlx, env->win, 0, 0, 0x990000,
			ft_strjoin("zoom:", zoom));
	mlx_string_put(env->mlx, env->win, 0, 15, 0x990000,
			ft_strjoin("[z/x]move pad:", move_pad));
}
