/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwispmot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/07 17:38:26 by nwispmot          #+#    #+#             */
/*   Updated: 2019/03/28 20:18:21 by nwispmot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		linelow(t_fdf *fdf)
{
	t_v v;

	v.dx = fdf->x1 - fdf->x0;
	v.dy = fdf->y1 - fdf->y0;
	v.yi = 1;
	if (v.dy < 0 && (v.yi = -1))
	{
		v.dy = -v.dy;
	}
	v.d = 2 * v.dy - v.dx;
	v.y = fdf->y0;
	while (fdf->x0 <= fdf->x1)
	{
		if (v.y >= 0 && fdf->x0 >= 0 && v.y < fdf->win_h
		&& fdf->x0 < fdf->win_h)
			fdf->img[(int)fdf->x0 + (int)v.y * fdf->win_w] = fdf->mass
					[fdf->cy][fdf->cx].color;
		if (v.d > 0)
		{
			v.y = v.y + v.yi;
			v.d = v.d - 2 * v.dx;
		}
		v.d = v.d + 2 * v.dy;
		fdf->x0++;
	}
}

static void		linehigh(t_fdf *fdf)
{
	t_v v;

	v.dx = fdf->x1 - fdf->x0;
	v.dy = fdf->y1 - fdf->y0;
	v.xi = 1;
	if (v.dx < 0 && (v.xi = -1))
		v.dx = -v.dx;
	v.d = 2 * v.dx - v.dy;
	v.x = fdf->x0;
	while (fdf->y0 <= fdf->y1)
	{
		if (fdf->y0 >= 0 && v.x >= 0 && fdf->y0 < fdf->win_h
		&& v.x < fdf->win_h)
			fdf->img[(int)v.x + (int)fdf->y0 * fdf->win_w] = fdf->mass
					[fdf->cy][fdf->cx].color;
		if (v.d > 0)
		{
			v.x = v.x + v.xi;
			v.d = v.d - 2 * v.dy;
		}
		v.d = v.d + 2 * v.dx;
		fdf->y0++;
	}
}

void			bresenham(t_fdf *fdf)
{
	if (fabs(fdf->y1 - fdf->y0) < fabs(fdf->x1 - fdf->x0))
	{
		if (fdf->x0 > fdf->x1)
		{
			ft_swap_d(&fdf->x0, &fdf->x1);
			ft_swap_d(&fdf->y0, &fdf->y1);
			linelow(fdf);
		}
		else
			linelow(fdf);
	}
	else
	{
		if (fdf->y0 > fdf->y1)
		{
			ft_swap_d(&fdf->x0, &fdf->x1);
			ft_swap_d(&fdf->y0, &fdf->y1);
			linehigh(fdf);
		}
		else
			linehigh(fdf);
	}
}
