/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwispmot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/11 18:20:59 by nwispmot          #+#    #+#             */
/*   Updated: 2019/03/11 18:21:02 by nwispmot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void print(t_fdf *fdf)
{
    int x;
    int y;

    x = 0;
    y = 0;
    while (y < fdf->height - 1)
    {
        while (x < fdf->width - 1)
        {
            bresenham(fdf, fdf->mass[y][x].x * fdf->mult + fdf->place_w, fdf->mass[y][x].y * fdf->mult + fdf->place_h,
                      fdf->mass[y][x + 1].x * fdf->mult + fdf->place_w,
                      fdf->mass[y][x + 1].y * fdf->mult + fdf->place_h);
            bresenham(fdf, fdf->mass[y][x].x * fdf->mult + fdf->place_w, fdf->mass[y][x].y * fdf->mult + fdf->place_h,
                      fdf->mass[y + 1][x].x * fdf->mult + fdf->place_w,
                      fdf->mass[y + 1][x].y * fdf->mult + fdf->place_h);
            x++;
        }
        bresenham(fdf, fdf->mass[y][x].x * fdf->mult + fdf->place_w, fdf->mass[y][x].y * fdf->mult + fdf->place_h,
                  fdf->mass[y + 1][x].x * fdf->mult + fdf->place_w, fdf->mass[y + 1][x].y * fdf->mult + fdf->place_h);
        x = 0;
        y++;
    }
    while (x < fdf->width - 1)
    {
        bresenham(fdf, fdf->mass[y][x].x * fdf->mult + fdf->place_w, fdf->mass[y][x].y * fdf->mult + fdf->place_h,
                  fdf->mass[y][x + 1].x * fdf->mult + fdf->place_w, fdf->mass[y][x + 1].y * fdf->mult + fdf->place_h);
        x++;
    }
}

void begin(t_fdf *fdf)
{
    int x;
    int y;

    x = 0;
    y = 0;
    while (y < fdf->height)
    {
        while (x < fdf->width)
        {
            fdf->mass[y][x].x = fdf->begin[y][x].x;
            fdf->mass[y][x].y = fdf->begin[y][x].y;
            fdf->mass[y][x].z = fdf->begin[y][x].z;
            x++;
        }
        x = 0;
        y++;
    }
}