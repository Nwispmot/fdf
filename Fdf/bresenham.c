/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwispmot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/07 17:38:26 by nwispmot          #+#    #+#             */
/*   Updated: 2019/03/07 17:38:55 by nwispmot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

typedef struct	s_var
{
	double dx;
	double dy;
	double yi;
	double xi;
	double x;
	double y;
	double D;
}				t_v;

static void LineLow(t_fdf *fdf, double x0, double y0, double x1, double y1, int cx, int cy)
{
	t_v v;

	v.dx = x1 - x0;
	v.dy = y1 - y0;
	v.yi = 1;
	if (v.dy < 0)
	{
		v.yi = -1;
		v.dy = -v.dy;
	}
	v.D = 2 * v.dy - v.dx;
	v.y = y0;

	while (x0 < x1)
	{
		if (v.y >= 0 && x0 >= 0 && v.y < fdf->win_h && x0 < fdf->win_h)
			fdf->img[(int)x0 + (int)v.y * fdf->win_w] = fdf->mass[cy][cx].color;
		if (v.D > 0)
		{
			v.y = v.y + v.yi;
			v.D = v.D - 2 * v.dx;
		}
		v.D = v.D + 2 * v.dy;
		x0++;
	}
}

static void LineHigh(t_fdf *fdf, double x0, double y0, double x1, double y1, int cx, int cy)
{
	t_v v;

	v.dx = x1 - x0;
	v.dy = y1 - y0;
	v.xi = 1;
	if (v.dx < 0)
	{
		v.xi = -1;
		v.dx = -v.dx;
	}
	v.D = 2 * v.dx - v.dy;
	v.x = x0;

	while (y0 < y1)
	{
		if (y0 >= 0 && v.x >= 0 && y0 < fdf->win_h && v.x < fdf->win_h)
			fdf->img[(int)v.x + (int)y0 * fdf->win_w] = fdf->mass[cy][cx].color;
		if (v.D > 0) {
			v.x = v.x + v.xi;
			v.D = v.D - 2 * v.dy;
		}
		v.D = v.D + 2 * v.dx;
		y0++;
	}
}

void bresenham(t_fdf *fdf, double x0, double y0, double x1, double y1, int cx, int cy)
{
	if (fabs(y1 - y0) < fabs(x1 - x0)) {
		if (x0 > x1)
			LineLow(fdf, x1, y1, x0, y0, cx, cy);
		else
			LineLow(fdf, x0, y0, x1, y1, cx, cy);
	} else {
		if (y0 > y1)
			LineHigh(fdf, x1, y1, x0, y0, cx, cy);
		else
			LineHigh(fdf, x0, y0, x1, y1, cx, cy);
	}
}
