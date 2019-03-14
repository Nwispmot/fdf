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

double ft_abs(double value)
{
    if (value < 0)
        value = -value;
    return(value);
}

static void LineLow(t_fdf *fdf, double x0, double y0, double x1, double y1)
{
    double dx;
    double dy;
    double yi;
    double xi;
    double x;
    double y;
    double D;

    dx = x1 - x0;
    dy = y1 - y0;
    yi = 1;
    if (dy < 0)
    {
        yi = -1;
        dy = -dy;
    }
    D = 2 * dy - dx;
    y = y0;

    while(x0 < x1)
    {
        mlx_pixel_put(fdf->mlx_ptr, fdf->win_ptr, x0, y, 0x00ffff);
        if (D > 0)
        {
            y = y + yi;
            D = D - 2 * dx;
        }
        D = D + 2 * dy;
        x0++;
    }
}

static void LineHigh(t_fdf *fdf, double x0, double y0, double x1, double y1)
{
    double dx;
    double dy;
    double yi;
    double xi;
    double x;
    double y;
    double D;

    dx = x1 - x0;
    dy = y1 - y0;
    xi = 1;
    if (dx < 0)
    {
        xi = -1;
        dx = -dx;
    }
    D = 2 * dx - dy;
    x = x0;

    while(y0 < y1)
    {
        mlx_pixel_put(fdf->mlx_ptr, fdf->win_ptr, x, y0, 0x00ffff);
        if (D > 0)
        {
            x = x + xi;
            D = D - 2 * dy;
        }
        D = D + 2 * dx;
        y0++;
    }
}

void bresenham(t_fdf *fdf, double x0, double y0, double x1, double y1)
{
    if (fabs(y1 - y0) < fabs(x1 - x0))
    {
        if (x0 > x1)
            LineLow(fdf, x1, y1, x0, y0);
        else
            LineLow(fdf, x0, y0, x1, y1);
    }
    else
    {
        if (y0 > y1)
            LineHigh(fdf, x1, y1, x0, y0);
        else
            LineHigh(fdf, x0, y0, x1, y1);
    }
}
