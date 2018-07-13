/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_fdf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsibiet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/26 11:42:51 by rsibiet           #+#    #+#             */
/*   Updated: 2016/02/01 13:51:19 by rsibiet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"

int		key_funct(int keycode, t_param *p)
{
	if (keycode == 53)
		exit(EXIT_SUCCESS);
	mlx_clear_window(p->mlx, p->win);
	p->i = 0;
	create_legend(p, 0, 0, 0);
	put_up_down(p, keycode);
	move_map(p, keycode);
	zoom_map(p, keycode);
	rotate_map(p, keycode);
	if (keycode == 82)
		p->off_color *= -1;
	draw_fdf(p, 0, 0, 0);
	return (0);
}

void	draw_fdf(t_param *p, int ax, int ay, int tp)
{
	char	*c;

	c = NULL;
	ft_fill_m(p, 0, c);
	p->ym = -1;
	if (p->siz_win[0] > p->siz_win[1])
		tp = p->siz_win[1];
	else
		tp = p->siz_win[0];
	while ((p->ym)++ < p->y_size - 1)
	{
		while (p->x < p->x_size)
		{
			ax = p->pos_x + p->siz_win[0] * p->x_size / 3.5 + (p->a1 * p->x -
				p->ym * p->a2) * p->siz_win[0] / 1.7 * p->zoom / 10;
			ay = p->pos_y + p->siz_win[1] * p->y_size / 2.5 -
				p->m[p->ym][p->x] * p->up * tp / 10 + p->b1 * p->x
				+ p->b2 * p->ym * tp / 1.7 * p->zoom / 10;
			trace_line(p, ax, ay, tp);
			(p->x)++;
		}
		p->x = 0;
	}
}

int		expose_hook(t_param *p)
{
	create_legend(p, 0, 0, 0);
	draw_fdf(p, 0, 0, 0);
	return (0);
}

char	**ft_read_file(int fd, char *file, int nb_line, int *ret)
{
	char	*line;
	char	**map;

	line = NULL;
	while ((*ret == get_next_line(fd, &line)) > 0)
	{
		nb_line++;
		ft_strdel(&line);
	}
	if (close(fd) == -1)
		fdf_error(file);
	map = (char **)malloc(sizeof(char *) * (nb_line + 1));
	nb_line = 0;
	if ((fd = open(file, O_RDONLY)) == -1)
		fdf_error(file);
	while ((*ret == get_next_line(fd, &map[nb_line])) > 0)
		nb_line++;
	*ret = nb_line;
	if (close(fd) == -1)
		fdf_error(file);
	map[nb_line] = ft_strdup("\0");
	return (map);
}

int		main(int ac, char **av)
{
	t_param	p;
	int		fd;
	int		ret;

	ret = 1;
	if (ac != 2)
	{
		ft_putendl("no map read.");
		return (0);
	}
	if ((fd = open(av[1], O_RDONLY)) == -1)
		fdf_error(av[1]);
	p.map = ft_read_file(fd, av[1], 0, &ret);
	p.y_size = ret;
	init_param(&p, av[1]);
	control_map(&p);
	p.mlx = mlx_init();
	p.win = mlx_new_window(p.mlx, p.siz_win[0] * p.x_size,
		p.siz_win[1] * p.y_size, "mlx 42");
	mlx_expose_hook(p.win, expose_hook, &p);
	mlx_key_hook(p.win, key_funct, &p);
	mlx_loop(p.mlx);
	free(p.m);
	ft_strdel(&(p.name));
	return (0);
}
