/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwispmot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 20:08:30 by nwispmot          #+#    #+#             */
/*   Updated: 2019/03/28 20:08:36 by nwispmot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_malloc(t_fdf *fdf, int y, int c)
{
	if (c == 1)
	{
		if (!(fdf->mass = (t_coor **)malloc(sizeof(t_coor) * fdf->height)))
			exit(0);
		if (!(fdf->begin = (t_coor **)malloc(sizeof(t_coor) * fdf->height)))
			exit(0);
	}
	if (c == 2)
	{
		if (!(fdf->mass[y] = (t_coor *)malloc(sizeof(t_coor) * fdf->width)))
			exit(0);
		if (!(fdf->begin[y] = (t_coor *)malloc(sizeof(t_coor) * fdf->width)))
			exit(0);
	}
}

void	coords_n_copy(t_fdf *fdf, int x, int y, char *temp)
{
	fdf->mass[y][x].x = x;
	fdf->mass[y][x].y = y;
	fdf->mass[y][x].z = ft_atoi(temp);
	ft_color(fdf, temp, x, y);
	fdf->begin[y][x].x = x;
	fdf->begin[y][x].y = y;
	fdf->begin[y][x].z = ft_atoi(temp);
}

void	count(t_fdf *fdf)
{
	while (fdf->map[fdf->height] != NULL)
		fdf->height++;
	ft_malloc(fdf, 0, 1);
	fdf->temp = ft_strsplit(fdf->map[0], ' ');
	while (fdf->temp[fdf->width] != NULL)
		fdf->width++;
}
