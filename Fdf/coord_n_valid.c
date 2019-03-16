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

int ft_del(int tmp)
{
    while (tmp > 9)
        tmp = tmp / 10;
    return(tmp);
}

void ft_mult(t_fdf *fdf)
{
    int tmp;
    int mult;

    tmp = fdf->width;
    if (fdf->height > tmp)
        tmp = fdf->height;
    mult = 30;
    if (tmp > 400)
    {
        mult = 2;
        tmp = 0;
    }
    else if (tmp > 200)
    {
        tmp = ft_del(tmp);
        mult = tmp;
    }
    else if (tmp > 25 && tmp <= 200)
    {
        tmp = ft_del(tmp);
        mult = tmp + 6;
    }
    fdf->mult = mult;
    fdf->bemult = mult;
}

void validation(t_fdf *fdf, char **temp)
{
    int width;

    width = 0;
    while(temp[width] != '\0')
        width++;
    printf("%d\n", fdf->width);
    if (fdf->width != width)
    {
        printf("%d\n", width);
        ft_putstr("Invalid file\n");
        exit(0);
    }
}

char *buffer(int fd)
{
    char buf[BUFF_SIZE + 1];
    char *temp;
    char *del;
    int ret;

    temp = ft_strnew(0);
    while((ret = read(fd, buf, BUFF_SIZE)) > 0)
    {
        buf[ret] = '\0';
        del = temp;
        temp = ft_strjoin(temp, buf);
        free(del);
    }
    return(temp);
}

void ft_init(t_fdf *fdf)
{
    fdf->height = 0;
    fdf->width = 0;
    fdf->win_h = 1000;
    fdf->win_w = 1000;
    ft_mult(fdf);
    fdf->mlx_ptr = mlx_init();
    fdf->win_ptr = mlx_new_window(fdf->mlx_ptr, fdf->win_w, fdf->win_h, "FDF");
    fdf->img_ptr = mlx_new_image(fdf->mlx_ptr, fdf->win_w, fdf->win_h);
    mlx_hook(fdf->win_ptr, 2, 0, keys, fdf);
}

void coordinates(int fd, t_fdf *fdf)
{
    int x;
    int y;
    char *buf;
    char **temp;

    x = 0;
    y = 0;
    buf = buffer(fd);
    fdf->map = ft_strsplit(buf, '\n');
    while (fdf->map[fdf->height] != NULL)
        fdf->height++;
    if(!(fdf->mass = (t_coor**)malloc(sizeof(t_coor) * fdf->height)))
        exit(0);
    if(!(fdf->begin = (t_coor**)malloc(sizeof(t_coor) * fdf->height)))
        exit(0);
    temp = ft_strsplit(fdf->map[0], ' ');
    while(temp[fdf->width] != NULL)
        fdf->width++;

    while (y < fdf->height)
    {
        if (!(fdf->mass[y] = (t_coor*)malloc(sizeof(t_coor) * fdf->width)))
            exit(0);
        if (!(fdf->begin[y] = (t_coor*)malloc(sizeof(t_coor) * fdf->width)))
            exit(0);
        //validation(fdf, temp);
        while (x < fdf->width)
        {
            fdf->mass[y][x].x = x;
            fdf->mass[y][x].y = y;
            fdf->mass[y][x].z = ft_atoi(temp[x]);
            fdf->begin[y][x].x = x;
            fdf->begin[y][x].y = y;
            fdf->begin[y][x].z = ft_atoi(temp[x]);
            x++;
        }
        x = 0;
        y++;
        ft_strdel(temp);
        temp = ft_strsplit(fdf->map[y], ' ');
    }
    fdf->place_w = (fdf->win_w - (fdf->width - 1) * fdf->mult) / 2;
    fdf->place_h = (fdf->win_h - (fdf->height - 1) * fdf->mult) / 2;
    fdf->beplace_h = fdf->place_h;
    fdf->beplace_w = fdf->place_w;
}