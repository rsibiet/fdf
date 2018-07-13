/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_trace_lines.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsibiet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/27 13:57:19 by rsibiet           #+#    #+#             */
/*   Updated: 2016/02/01 13:36:48 by rsibiet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"

void	trace_yref(t_param *p, int ax, int ay, int n[2])
{
	int		color;
	int		xfinal;
	float	divx;
	float	divy;

	p->i = 0;
	color = ft_create_color(p);
	if ((n[1] - ay) < 0)
	{
		ft_switch(&ax, &n[0]);
		ft_switch(&ay, &n[1]);
	}
	divx = ft_abs(n[0] - ax);
	divy = n[1] - ay--;
	while (n[1] - ay++ > 0)
	{
		(p->i)++;
		if (ax - n[0] < 0)
			xfinal = ax + (divx / divy * p->i);
		else
			xfinal = ax - (divx / divy * p->i);
		if (xfinal >= 0 && xfinal <= p->x_size * p->siz_win[0] &&
			ay >= 0 && ay <= p->y_size * p->siz_win[1])
			mlx_pixel_put(p->mlx, p->win, xfinal, ay, color);
	}
}

void	trace_xref(t_param *p, int ax, int ay, int n[2])
{
	int		color;
	int		yfinal;
	float	divx;
	float	divy;

	p->i = 0;
	color = ft_create_color(p);
	if ((n[0] - ax) < 0)
	{
		ft_switch(&ax, &n[0]);
		ft_switch(&ay, &n[1]);
	}
	divx = n[0] - ax--;
	divy = ft_abs(n[1] - ay);
	while (n[0] - ax++ > 0)
	{
		(p->i)++;
		if (ay - n[1] < 0)
			yfinal = ay + (divy / divx * p->i);
		else
			yfinal = ay - (divy / divx * p->i);
		if (ax >= 0 && ax <= p->x_size * p->siz_win[0] &&
			yfinal >= 0 && yfinal <= p->y_size * p->siz_win[1])
			mlx_pixel_put(p->mlx, p->win, ax, yfinal, color);
	}
}

void	trace_line2(t_param *p, int ax, int ay, int tp)
{
	int		n[2];

	if (p->ym < p->y_size - 1)
	{
		n[0] = p->pos_x + p->siz_win[0] * p->x_size / 3.5 + (p->a1 * p->x
			- ((p->ym + 1) * p->a2)) * p->siz_win[0] / 1.7 * p->zoom / 10;
		n[1] = p->pos_y + p->siz_win[1] * p->y_size / 2.5 -
			p->m[p->ym + 1][p->x] * p->up * tp / 10 + p->b1 *
			p->x + p->b2 * (p->ym + 1) * tp / 1.7 * p->zoom / 10;
		if (ft_abs(n[0] - ax) > ft_abs(n[1] - ay))
			trace_xref(p, ax, ay, n);
		else
			trace_yref(p, ax, ay, n);
	}
}

void	trace_line(t_param *p, int ax, int ay, int tp)
{
	int		n[2];

	if (p->x < p->x_size - 1)
	{
		n[0] = p->pos_x + p->siz_win[0] * p->x_size / 3.5 + (p->a1 *
			(p->x + 1) - p->ym * p->a2) * p->siz_win[0] / 1.7 * p->zoom / 10;
		n[1] = p->pos_y + p->siz_win[1] * p->y_size / 2.5 -
			p->m[p->ym][p->x + 1] * p->up * tp / 10 + p->b1
			* (p->x + 1) + p->b2 * p->ym * tp / 1.7 * p->zoom / 10;
		if (ft_abs(n[0] - ax) > ft_abs(n[1] - ay))
			trace_xref(p, ax, ay, n);
		else
			trace_yref(p, ax, ay, n);
	}
	trace_line2(p, ax, ay, tp);
}
