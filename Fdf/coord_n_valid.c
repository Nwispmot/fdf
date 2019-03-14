/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coord_n_valid.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwispmot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 21:31:11 by nwispmot          #+#    #+#             */
/*   Updated: 2019/03/05 21:31:14 by nwispmot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int ft_mult(t_fdf *fdf)
{
    int mult;

    if (fdf->width > fdf->height)
        mult = fdf->win_w / fdf->width - 10;
    else
        mult = fdf->win_w / fdf->height - 10;
    if (mult > 30)
        mult = 30;
    return (mult);
}

void validation(t_fdf *fdf, char **temp)
{
    int width;

    width = 0;
    while(temp[width] != NULL)
        width++;
    if (fdf->width != width)
    {
        ft_putstr("Invalid file\n");
        exit(0);
    }
}

t_fdf *coordinates(int fd)
{
    char buf[BUFF_SIZE + 1];
    int ret;
    int x;
    int y;
    char **temp;
    t_fdf *fdf;
    int i=-1;

    x = 0;
    y = 0;
    if(!(fdf = (t_fdf*)malloc(sizeof(t_fdf))))
        exit(0);
    fdf->height = 0;
    fdf->width = 0;
    ret = read(fd, buf, BUFF_SIZE);
    buf[ret] = '\0';
    fdf->map = ft_strsplit(buf, '\n');
    while (fdf->map[fdf->height] != NULL)
        fdf->height++;
    if(!(fdf->mass = (t_coor**)malloc(sizeof(t_coor) * fdf->height)))
        exit(0);
    temp = ft_strsplit(fdf->map[0], ' ');
    while(temp[fdf->width] != NULL)
        fdf->width++;

    while (y < fdf->height)
    {
        if (!(fdf->mass[y] = (t_coor*)malloc(sizeof(t_coor) * fdf->width)))
            exit(0);
        //validation(fdf, temp);
        while (x < fdf->width)
        {
            fdf->mass[y][x].x = x;
            fdf->mass[y][x].y = y;
            fdf->mass[y][x].z = ft_atoi(temp[x]);
            x++;
        }
        x = 0;
        y++;
        free(temp);
        temp = ft_strsplit(fdf->map[y], ' ');
    }
    fdf->win_h = 1000;
    fdf->win_w = 1000;
    fdf->mult = ft_mult(fdf);
    fdf->place_w = (fdf->win_w - (fdf->width - 1) * fdf->mult) / 2;
    fdf->place_h = (fdf->win_h - (fdf->height - 1) * fdf->mult) / 2;

    return(fdf);
}