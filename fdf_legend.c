/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_legend.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsibiet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/28 15:34:15 by rsibiet           #+#    #+#             */
/*   Updated: 2016/02/01 14:03:56 by rsibiet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"

void	create_legend_2(t_param *p, int i, int j)
{
	j += 20;
	i -= 105;
	mlx_string_put(p->mlx, p->win, i, j, 0x0033C1B1,
		"z up : 'w'.");
	j += 20;
	mlx_string_put(p->mlx, p->win, i, j, 0x0033C1B1,
		"z down : 's'.");
	j += 20;
	mlx_string_put(p->mlx, p->win, i, j, 0x0033C1B1,
		"Zoom : '+' & '-'.");
	j += 20;
	mlx_string_put(p->mlx, p->win, i, j, 0x0033C1B1,
		"Move : 2, 4, 6, 8.");
	j += 20;
	mlx_string_put(p->mlx, p->win, i, j, 0x0033C1B1,
		"Rotation : d, g, r, f.");
	j += 20;
	mlx_string_put(p->mlx, p->win, i, j, 0x0033C1B1,
		"color off / on : 0.");
}

void	create_legend(t_param *p, int x, int y, int i)
{
	int		j;

	x = p->x_size * p->siz_win[0];
	y = p->y_size * p->siz_win[1];
	i = x - 280;
	j = 160;
	while (i++ < (x - 11))
		mlx_pixel_put(p->mlx, p->win, i, j, 0x0033C1B1);
	while (j-- > 11)
		mlx_pixel_put(p->mlx, p->win, i, j, 0x0033C1B1);
	while (i-- > (x - 280))
		mlx_pixel_put(p->mlx, p->win, i, j, 0x0033C1B1);
	while (j++ < 160)
		mlx_pixel_put(p->mlx, p->win, i, j, 0x0033C1B1);
	i += 5;
	j = 15;
	mlx_string_put(p->mlx, p->win, i, j, 0x0033C1B1, "Map name :");
	i += 110;
	mlx_string_put(p->mlx, p->win, i, j, 0x0033C1B1, p->name);
	create_legend_2(p, i, j);
}
