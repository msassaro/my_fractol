/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msassaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/23 11:20:04 by msassaro          #+#    #+#             */
/*   Updated: 2016/02/23 11:32:37 by msassaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "libft/includes/libft.h"
# include "libft/includes/ft_printf.h"
# include "mlx/mlx.h"
# include <math.h>

typedef struct	s_env
{
	char		*name;
	void		*mlx;
	void		*win;
	void		*img;
	int			*tab;
	int			**img_tab;
	int			fractal;
	int			color_index;
	int			x_ori;
	int			y_ori;
	int			move_pad;
	int			iter_pad;
	double		x1;
	double		x2;
	double		y1;
	double		y2;
	double		x_img;
	double		y_img;
	double		zoom;
	double		zoom_init;
	int			iter_max;
	double		c_r;
	double		c_i;
	double		z_r;
	double		z_i;
	double		tmp;
	double		tmp2;
	double		r4;
	double		absv;
	int			x;
	int			y;
	int			j;
	int			bits;
	int			size;
	int			end;
	double		mouse_x;
	double		mouse_y;
}				t_env;

/*
** user_x.c
*/

void			ft_fractol_choices();
void			ft_fractol_error();
void			ft_fractol_welecome();
void			ft_fractol_menu(t_env *env);

/*
** event_1.c
*/

void			ft_fractol_iter_mode(t_env *env);
void			ft_fractol_zoom_in(t_env *env, int x, int y);
void			ft_fractol_zoom_out(t_env *env, int x, int y);
int				ft_fractol_keyhook(int key, void *param);
int				ft_fractol_mousehook(int click, int x, int y, void *param);

/*
** event_2.c
*/

void			ft_fractol_color_change(t_env *env);
void			ft_fractol_move(int key, t_env *env);
void			ft_fractol_move_pad(int key, t_env *env);
void			ft_fractol_move_iter(int key, t_env *env);
void			ft_fractol_reinit(t_env *env);

/*
** event_2.c
*/

int				ft_fractol_mousemove(int x, int y, void *param);

/*
** mandelbrot_julia_jules_blob.c
*/

void			ft_fractol_mandelbrot(t_env e);
void			ft_fractol_julia(t_env e);
void			ft_fractol_jules(t_env e);
void			ft_fractol_blob(t_env e);

/*
** envinit_color.c
*/

int				ft_fractol_colorize(t_env env);
int				**ft_fractol_img_tab_create(t_env env);
void			ft_fractol_init_chooser(t_env *env);
void			ft_fractol_envinit(t_env *e);

/*
** main.c
*/

void			ft_fractol_menu(t_env *env);
void			ft_fractol_parse_graphic(t_env env);
void			ft_fractol_parse(t_env env);

/*
** init_fract.c
*/

void			ft_fractol_init_burningship(t_env *env);
void			ft_fractol_init_mandelbrot(t_env *env);
void			ft_fractol_init_name_select(t_env *env);
void			ft_fractol_init_iter_select(t_env *env);
void			ft_fractol_init_fractal(t_env *env);

/*
** clover_newton_bship_helios.c
*/

void			ft_fractol_newton_clover_if(t_env e);
void			ft_fractol_clover(t_env e);
void			ft_fractol_newton(t_env e);
void			ft_fractol_burningship(t_env e);
void			ft_fractol_helios(t_env e);

#endif
