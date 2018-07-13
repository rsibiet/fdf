/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_up_down.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsibiet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/27 19:13:07 by rsibiet           #+#    #+#             */
/*   Updated: 2016/02/01 13:45:52 by rsibiet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"

void	rotate_map(t_param *p, int key)
{
	if (key == 2)
		(p->omega) += 0.1;
	if (key == 5)
		(p->omega) -= 0.1;
	if (key == 15)
		(p->alpha) += 0.1;
	if (key == 3)
		(p->alpha) -= 0.1;
	if (key == 2 || key == 5 || key == 15 || key == 3)
	{
		p->a1 = cos(p->omega);
		p->a2 = sin(p->omega);
		p->b1 = cos(p->alpha);
		p->b2 = sin(p->alpha);
	}
}

void	zoom_map(t_param *p, int key)
{
	if (key == 69)
		(p->zoom)++;
	else if (key == 78)
		(p->zoom)--;
	if (p->zoom < 1)
		p->zoom = 1;
}

void	move_map(t_param *p, int key)
{
	if (key == 91)
		p->pos_y -= 10;
	else if (key == 84)
		p->pos_y += 10;
	else if (key == 86)
		p->pos_x -= 10;
	else if (key == 88)
		p->pos_x += 10;
}

int		ft_create_color(t_param *p)
{
	int		col;

	if (p->m[p->ym][p->x] == 0 || p->off_color == 1)
		col = 16777215;
	else if (p->up < 0)
	{
		col = 16777215 + (514 * p->m[p->ym][p->x] * p->up);
		if (col < 16711680)
			col = 16711680;
	}
	else
	{
		col = 16777215 - 131074 * p->m[p->ym][p->x] * p->up;
		if (col < 65280)
			col = 65280;
	}
	return (col);
}

void	put_up_down(t_param *p, int keycode)
{
	p->ym = 0;
	if (keycode == 13)
		(p->up)++;
	else if (keycode == 1)
		(p->up)--;
}
