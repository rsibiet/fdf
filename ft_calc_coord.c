/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calc_coord.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsibiet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/26 16:28:37 by rsibiet           #+#    #+#             */
/*   Updated: 2016/02/01 13:49:20 by rsibiet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"

void	ft_fill_m(t_param *p, int tp, char *c)
{
	while (p->ym <= p->y_size)
	{
		while (p->map[p->ym][p->xm] != '\0')
		{
			while (p->map[p->ym][p->xm] == ' ' && p->map[p->ym][p->xm] != '\0')
				(p->xm)++;
			tp = p->xm;
			while (p->map[p->ym][p->xm] != ' ' && p->map[p->ym][p->xm] != '\0')
				(p->xm)++;
			c = (char *)malloc(sizeof(char) * (p->xm - tp + 1));
			while (tp++ < p->xm)
			{
				c[p->i] = p->map[p->ym][tp - 1];
				(p->i)++;
			}
			c[p->i] = '\0';
			p->i = 0;
			p->m[p->ym][p->x] = ft_atoi(c);
			(p->x)++;
			ft_strdel(&c);
		}
		p->x = 0;
		p->xm = 0;
		(p->ym)++;
	}
}

void	define_size_win(t_param *p)
{
	p->siz_win[0] = 1;
	while (p->x_size * p->siz_win[0] <= 800)
		(p->siz_win[0])++;
	p->siz_win[1] = 1;
	while (p->y_size * p->siz_win[1] <= 800)
		(p->siz_win[1])++;
}

void	control_map(t_param *p)
{
	int		tp;

	while (p->ym < p->y_size)
	{
		tp = 0;
		while (p->map[p->ym][p->xm] != '\0')
		{
			while (p->map[p->ym][p->xm] == ' ' && p->map[p->ym][p->xm] != '\0')
				(p->xm)++;
			if (p->map[p->ym][p->xm] != '\0')
				tp++;
			while (p->map[p->ym][p->xm] != ' ' && p->map[p->ym][p->xm] != '\0')
				(p->xm)++;
		}
		if (p->ym > 0 && p->x_size != tp)
			error_lenght_map();
		p->x_size = tp;
		p->xm = 0;
		(p->ym)++;
	}
	p->ym = 0;
	while ((p->ym)++ <= p->y_size)
		p->m[p->ym - 1] = (int *)malloc(sizeof(int) * p->x_size);
	p->ym = 0;
	define_size_win(p);
}

void	map_name(t_param *p, char *c, int i, int j)
{
	int		tp;

	tp = 0;
	i = ft_strlen(c);
	j = i;
	while (i > 0 && c[i - 1] != '/')
		i--;
	if (j - i > 15)
	{
		tp = 1;
		i = j - 15;
	}
	p->name = ft_strnew(j - i);
	j = 0;
	while (c[i] != '\0' && j < 12)
	{
		p->name[j] = c[i];
		i++;
		j++;
	}
	if (c[i] != '\0' && j == 12)
	{
		while (j++ < 14)
			p->name[j - 1] = '.';
	}
}

void	init_param(t_param *p, char *c)
{
	p->m = (int **)malloc(sizeof(int *) * p->y_size);
	p->xm = 0;
	p->ym = 0;
	p->i = 0;
	p->x = 0;
	p->up = 1;
	p->pos_x = 0;
	p->pos_y = 0;
	p->zoom = 10;
	p->off_color = -1;
	map_name(p, c, 0, 0);
	p->alpha = 0.9;
	p->omega = -0.5;
	p->a1 = cos(p->omega);
	p->a2 = sin(p->omega);
	p->b1 = cos(p->alpha);
	p->b2 = sin(p->alpha);
}
