/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwispmot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/28 14:57:45 by nwispmot          #+#    #+#             */
/*   Updated: 2019/02/28 14:57:49 by nwispmot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int keys(int key, t_fdf *fdf)
{
    if (key == 53)
        exit(0);
    if (key == 124)
    {
        mlx_clear_window((fdf)->mlx_ptr, (fdf)->win_ptr);
        fdf->place_w += 5;
        print(fdf);
    }
    if (key == 123)
    {
        mlx_clear_window((fdf)->mlx_ptr, (fdf)->win_ptr);
        fdf->place_w -= 5;
        print(fdf);
    }
    if (key == 126)
    {
        mlx_clear_window((fdf)->mlx_ptr, (fdf)->win_ptr);
        fdf->place_h -= 5;
        print(fdf);
    }
    if (key == 125)
    {
        mlx_clear_window((fdf)->mlx_ptr, (fdf)->win_ptr);
        fdf->place_h += 5;
        print(fdf);
    }
    if (key == 78)
    {
        mlx_clear_window((fdf)->mlx_ptr, (fdf)->win_ptr);
        fdf->mult--;
        if(fdf->mult < 0)
            fdf->mult = 0;
        print(fdf);
    }
    if (key == 69)
    {
        mlx_clear_window((fdf)->mlx_ptr, (fdf)->win_ptr);
        fdf->mult++;
        print(fdf);
    }
    if (key == 13)
    {
        mlx_clear_window((fdf)->mlx_ptr, (fdf)->win_ptr);
        x_rotation(fdf);
        print(fdf);
    }
    if (key == 2)
    {
        mlx_clear_window((fdf)->mlx_ptr, (fdf)->win_ptr);
        y_rotation(fdf);
        print(fdf);
    }
    if (key == 0)
    {
        mlx_clear_window((fdf)->mlx_ptr, (fdf)->win_ptr);
        z_rotation(fdf);
        print(fdf);
    }
    return (0);
}