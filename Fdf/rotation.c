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

void ud_rotation(t_fdf *fdf, int key)
{
    double y0;
    int x;
    int y;

    if (key == 1)
        fdf->sico = 0.1;
    else
        fdf->sico = -0.1;
    x = 0;
    y = 0;

    while (y < fdf->height)
    {
        while (x < fdf->width)
        {
            y0 = fdf->mass[y][x].y - fdf->height / 2;
            fdf->mass[y][x].y = fdf->height/2 + y0 * cos(fdf->sico) + fdf->mass[y][x].z * sin(fdf->sico);
            fdf->mass[y][x].z = -y0 * sin(fdf->sico) + fdf->mass[y][x].z * cos(fdf->sico);
            x++;
        }
        x = 0;
        y++;
    }
    mlx_clear_window((fdf)->mlx_ptr, (fdf)->win_ptr);
    print(fdf);
}

void lr_rotation(t_fdf *fdf, int key)
{
    int x;
    int y;
    double x0;

    if (key == 2)
        fdf->sico = 0.1;
    else
        fdf->sico = -0.1;
    x = 0;
    y = 0;
    while (y < fdf->height)
    {
        while (x < fdf->width)
        {
            x0 = fdf->mass[y][x].x - fdf->width / 2;
            fdf->mass[y][x].x = fdf->width/2 + x0 * cos(fdf->sico) + fdf->mass[y][x].z * sin(fdf->sico);
            fdf->mass[y][x].z = -x0 * sin(fdf->sico) + fdf->mass[y][x].z * cos(fdf->sico);
            x++;
        }
        x = 0;
        y++;
    }
    mlx_clear_window((fdf)->mlx_ptr, (fdf)->win_ptr);
    print(fdf);
}

void z_rotation(t_fdf *fdf, int key)
{
    int x;
    int y;
    double x0;
    double y0;


    if (key == 6)
        fdf->sico = -0.1;
    else
        fdf->sico = 0.1;
    x = 0;
    y = 0;
    x0 = (fdf->win_w / 2);
    y0 = (fdf->win_h / 2);

    while (y < fdf->height)
    {
        while (x < fdf->width)
        {
            x0 = fdf->mass[y][x].x - fdf->width / 2;
            y0 = fdf->mass[y][x].y - fdf->height / 2;
            fdf->mass[y][x].x = fdf->width/2 + x0 * cos(fdf->sico) - y0 * sin(fdf->sico);
            fdf->mass[y][x].y = fdf->height/2 + y0 * cos(fdf->sico) + x0 * sin(fdf->sico);

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
    fdf->place_w += 150;
    print(fdf);
}