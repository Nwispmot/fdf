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
    double x0;
    double y0;
    int x;
    int y;

    x = 0;
    y = 0;
    x0 = fdf->place_w;
    y0 = fdf->place_h;

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
    mlx_clear_window((fdf)->mlx_ptr, (fdf)->win_ptr);
    print(fdf);
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
    mlx_clear_window((fdf)->mlx_ptr, (fdf)->win_ptr);
    print(fdf);
}

void z_rotation(t_fdf *fdf)
{
    double tmp;
    int x;
    int y;
    double x0;
    double y0;

    x = 0;
    y = 0;
    x0 = (fdf->win_w / 2);
    y0 = (fdf->win_h / 2);

    while (y < fdf->height)
    {
        while (x < fdf->width)
        {
            tmp = fdf->mass[y][x].x;
            fdf->mass[y][x].x = fdf->mass[y][x].x * cos(fdf->sico) - fdf->mass[y][x].y * sin(fdf->sico);
            fdf->mass[y][x].y = tmp * sin(fdf->sico) + fdf->mass[y][x].y * cos(fdf->sico) ;
            x++;
        }
        x = 0;
        y++;
    }
    mlx_clear_window((fdf)->mlx_ptr, (fdf)->win_ptr);
    print(fdf);
}

void iso(t_fdf *fdf)
{
    double pre_x;
    double pre_y;
    int x;
    int y;

    x = 0;
    y = 0;
    begin(fdf, 0);
    while (y < fdf->height)
    {
        while (x < fdf->width)
        {
            pre_x = fdf->mass[y][x].x;
            pre_y = fdf->mass[y][x].y;
            fdf->mass[y][x].x = (pre_x -pre_y) * cos(0.523599);
            fdf->mass[y][x].y = -fdf->mass[y][x].z + (pre_x + pre_y) * sin(0.523599);
            x++;
        }
        x = 0;
        y++;
    }
    print(fdf);
}