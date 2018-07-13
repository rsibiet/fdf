/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsibiet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/26 11:43:50 by rsibiet           #+#    #+#             */
/*   Updated: 2016/02/01 13:44:20 by rsibiet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FDF_H
# define FT_FDF_H

# include "libft.h"
# include <unistd.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <fcntl.h>
# include <math.h>
# include <stdlib.h>
# include <stdio.h>
# include "./MinilibX/mlx.h"

/*
** map = map to read & display
** x_size, y_size = size of m[ym][x]
** xm, ym = coord read on map
** m -> m[ym][x] = z;
*/

typedef struct	s_param
{
	char		*name;
	char		**map;
	void		*mlx;
	void		*win;
	int			x_size;
	int			y_size;
	int			xm;
	int			ym;
	int			i;
	int			x;
	int			**m;
	int			up;
	int			pos_x;
	int			pos_y;
	int			zoom;
	float		alpha;
	float		omega;
	float		a1;
	float		a2;
	float		b1;
	float		b2;
	int			off_color;
	int			siz_win[2];
}				t_param;

/*
** Fonctions in ft_init_fdf file
*/

int				key_funct(int keycode, t_param *p);
void			draw_fdf(t_param *p, int ax, int ay, int tp);
int				expose_hook(t_param *p);
char			**ft_read_file(int fd, char *file, int nb_line, int *ret);

/*
** Fonctions in fdf_error file
*/

void			error_lenght_map(void);
void			fdf_error(char *c);

/*
** Fonctions in ft_calc_coord file
*/

void			ft_fill_m(t_param *p, int tp, char *c);
void			define_size_win(t_param *p);
void			control_map(t_param *p);
void			map_name(t_param *p, char *c, int i, int j);
void			init_param(t_param *p, char *c);

/*
** Fonctions in fdf_trace_lines file
*/

void			trace_yref(t_param *p, int ax, int ay, int n[2]);
void			trace_xref(t_param *p, int ax, int ay, int n[2]);
void			trace_line2(t_param *p, int ax, int ay, int tp);
void			trace_line(t_param *p, int ax, int ay, int tp);

/*
** Fonctions in fdf_up_down file
*/

void			rotate_map(t_param *p, int key);
void			zoom_map(t_param *p, int key);
void			move_map(t_param *p, int key);
int				ft_create_color(t_param *p);
void			put_up_down(t_param *p, int keycode);

/*
** Fonctions in fdf_legend file
*/

void			create_legend_2(t_param *p, int i, int j);
void			create_legend(t_param *p, int x, int y, int i);

#endif
