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

void print(t_fdf *fdf) //-
{
    int x;
    int y;

    ft_bzero(fdf->img, fdf->win_h * fdf->win_w * 4);
    mlx_clear_window((fdf)->mlx_ptr, (fdf)->win_ptr);
    y = 0;
    while (y < fdf->height - 1)
    {
    	x = 0;
        while (x < fdf->width - 1)
        {
            bresenham(fdf, fdf->mass[y][x].x * fdf->mult + fdf->place_w, fdf->mass[y][x].y * fdf->mult + fdf->place_h,
                      fdf->mass[y][x + 1].x * fdf->mult + fdf->place_w,
                      fdf->mass[y][x + 1].y * fdf->mult + fdf->place_h, x, y);
            bresenham(fdf, fdf->mass[y][x].x * fdf->mult + fdf->place_w, fdf->mass[y][x].y * fdf->mult + fdf->place_h,
                      fdf->mass[y + 1][x].x * fdf->mult + fdf->place_w,
                      fdf->mass[y + 1][x].y * fdf->mult + fdf->place_h, x, y);
            x++;
        }
        bresenham(fdf, fdf->mass[y][x].x * fdf->mult + fdf->place_w, fdf->mass[y][x].y * fdf->mult + fdf->place_h,
                  fdf->mass[y + 1][x].x * fdf->mult + fdf->place_w, fdf->mass[y + 1][x].y * fdf->mult + fdf->place_h, x ,y);
        y++;
    }
    x = 0;
    while (x < fdf->width - 1)
    {
        bresenham(fdf, fdf->mass[y][x].x * fdf->mult + fdf->place_w, fdf->mass[y][x].y * fdf->mult + fdf->place_h,
                  fdf->mass[y][x + 1].x * fdf->mult + fdf->place_w, fdf->mass[y][x + 1].y * fdf->mult + fdf->place_h, x, y);
        x++;
    }
    mlx_put_image_to_window(fdf->mlx_ptr, fdf->win_ptr, fdf->img_ptr, 0, 0);
    fdf->sico = 0.1;
}

void begin(t_fdf *fdf, int pr)
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
            fdf->place_h = fdf->beplace_h;
            fdf->place_w = fdf->beplace_w;
            fdf->mult = fdf->bemult;
            x++;
        }
        x = 0;
        y++;
    }
    ft_bzero(fdf->img, fdf->win_h * fdf->win_h * 4);
    mlx_clear_window((fdf)->mlx_ptr, (fdf)->win_ptr);
    if (pr == 1)
        print(fdf);
}