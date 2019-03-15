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
    if (key == 124 || key == 123)
        move_x(fdf, key);
    if (key == 126 || key == 125)
        move_y(fdf, key);
    if (key == 78 || key == 69) //скаляция
        scale(fdf, key);
    if (key == 13)
        x_rotation(fdf);
    if (key == 2)
        y_rotation(fdf);
    if (key == 6)
        z_rotation(fdf);
    if (key == 11)
        begin(fdf, 1);
    if (key == 49)
        iso(fdf);
    return (0);
}