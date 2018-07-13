/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsibiet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/26 13:47:39 by rsibiet           #+#    #+#             */
/*   Updated: 2016/01/28 18:00:48 by rsibiet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"

void	error_lenght_map(void)
{
	ft_putendl("Found wrong line length. Exiting.");
	exit(EXIT_FAILURE);
}

void	fdf_error(char *c)
{
	ft_putstr("fdf : ");
	ft_putstr(c);
	perror(" ");
	exit(EXIT_FAILURE);
}
