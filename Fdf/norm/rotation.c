/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwispmot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/11 20:51:59 by nwispmot          #+#    #+#             */
/*   Updated: 2019/03/25 17:02:42 by nwispmot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ud_rotation(t_fdf *fdf, int key)
{
	double	y0;
	int		x;
	int		y;

	if (key == 13)
		fdf->sico = -0.1;
	y = 0;
	while (y < fdf->height)
	{
		x = 0;
		while (x < fdf->width)
		{
			y0 = fdf->mass[y][x].y - fdf->height / 2;
			fdf->mass[y][x].y = fdf->height / 2 + y0 *
					cos(fdf->sico) + fdf->mass[y][x].z * sin(fdf->sico);
			fdf->mass[y][x].z = -y0 * sin(fdf->sico) +
								fdf->mass[y][x].z * cos(fdf->sico);
			x++;
		}
		y++;
	}
	print(fdf);
}

void	lr_rotation(t_fdf *fdf, int key)
{
	int		x;
	int		y;
	double	x0;

	if (key == 0)
		fdf->sico = -0.1;
	y = 0;
	while (y < fdf->height)
	{
		x = 0;
		while (x < fdf->width)
		{
			x0 = fdf->mass[y][x].x - fdf->width / 2;
			fdf->mass[y][x].x = fdf->width / 2 + x0 *
					cos(fdf->sico) + fdf->mass[y][x].z * sin(fdf->sico);
			fdf->mass[y][x].z = -x0 * sin(fdf->sico) +
					fdf->mass[y][x].z * cos(fdf->sico);
			x++;
		}
		y++;
	}
	print(fdf);
}

void	z_rotation(t_fdf *fdf, int key)
{
	int		x;
	int		y;
	double	x0;
	double	y0;

	if (key == 6)
		fdf->sico = -0.1;
	y = 0;
	while (y < fdf->height)
	{
		x = 0;
		while (x < fdf->width)
		{
			x0 = fdf->mass[y][x].x - fdf->width / 2;
			y0 = fdf->mass[y][x].y - fdf->height / 2;
			fdf->mass[y][x].x = fdf->width / 2 + x0 *
					cos(fdf->sico) - y0 * sin(fdf->sico);
			fdf->mass[y][x].y = fdf->height / 2 + y0 *
					cos(fdf->sico) + x0 * sin(fdf->sico);
			x++;
		}
		y++;
	}
	print(fdf);
}

void	iso(t_fdf *fdf)
{
	double	pre_x;
	double	pre_y;
	int		x;
	int		y;

	y = 0;
	begin(fdf, 0);
	while (y < fdf->height)
	{
		x = 0;
		while (x < fdf->width)
		{
			pre_x = fdf->mass[y][x].x;
			pre_y = fdf->mass[y][x].y;
			fdf->mass[y][x].x = (pre_x - pre_y) * cos(0.523599);
			fdf->mass[y][x].y = -fdf->mass[y][x].z +
					(pre_x + pre_y) * sin(0.523599);
			x++;
		}
		y++;
	}
	fdf->place_w += 150;
	print(fdf);
}
