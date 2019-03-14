/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwispmot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/11 20:51:59 by nwispmot          #+#    #+#             */
/*   Updated: 2019/03/11 20:52:03 by nwispmot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void x_rotation(t_fdf *fdf)
{
    double tmp;
    int x;
    int y;

    x = 0;
    y = 0;
    while (y < fdf->height)
    {
        while (x < fdf->width)
        {
            tmp = fdf->mass[y][x].y;
            fdf->mass[y][x].y = fdf->mass[y][x].y * cos(fdf->sico) + fdf->mass[y][x].z * sin(fdf->sico);
            fdf->mass[y][x].z = -tmp * sin(fdf->sico) + fdf->mass[y][x].z * cos(fdf->sico);
            x++;
        }
        x = 0;
        y++;
    }
}

void y_rotation(t_fdf *fdf)
{
    double tmp;
    int x;
    int y;

    x = 0;
    y = 0;
    while (y < fdf->height)
    {
        while (x < fdf->width)
        {
            tmp = fdf->mass[y][x].x;
            fdf->mass[y][x].x = fdf->mass[y][x].x * cos(fdf->sico) + fdf->mass[y][x].z * sin(fdf->sico);
            fdf->mass[y][x].z = -tmp * sin(fdf->sico) + fdf->mass[y][x].z * cos(fdf->sico);
            x++;
        }
        x = 0;
        y++;
    }
}

void z_rotation(t_fdf *fdf)
{
    double tmp;
    int x;
    int y;

    x = 0;
    y = 0;
    while (y < fdf->height)
    {
        while (x < fdf->width)
        {
            tmp = fdf->mass[y][x].x;
            fdf->mass[y][x].x = fdf->mass[y][x].x * cos(fdf->sico) - fdf->mass[y][x].y * sin(fdf->sico);
            fdf->mass[y][x].y = tmp * sin(fdf->sico) + fdf->mass[y][x].y * cos(fdf->sico);
            x++;
        }
        x = 0;
        y++;
    }
}