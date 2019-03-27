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

void    ft_mult(t_fdf *fdf)
{
    int twin;
    int tmp;
    int mult;

    tmp = fdf->width - 1;
    if (fdf->height - 1 > tmp)
        tmp = fdf->height - 1;
    twin = fdf->win_w;
    if (fdf->win_h > twin)
        twin = fdf->height;
    mult = ((twin / 100) * 50) / tmp;
    fdf->mult = mult;
    fdf->bemult = mult;
}

int isnum(char *temp)
{
	int i;

	i = 0;
	if (temp[i] >= '0' && temp[i] <= '9')
		i++;
	else
		return(1);
	while (temp[i] != '\0' && temp[i] != ',')
	{
		if (temp[i] >= '0' && temp[i] <= '9')
			i++;
		else
			return (1);
	}
		return(0);
}

void    validation(t_fdf *fdf, char **temp)
{
    int width;
    int i;

    i = 0;
	if(!temp)
		exit(0);
    width = 0;
    while(temp[width] != NULL)
        width++;
    if (fdf->width != width)
    {
        ft_putstr("Invalid file width\n");
        exit(0);
    }
    while (temp[i] != NULL)
	{
    	if(isnum(temp[i]) == 1)
		{
			ft_putstr("Invalid file number\n");
			exit(0);
		}
    	i++;
	}
}

char    *buffer(int fd)
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
    if (ret < 0 || temp[0] == '\0' || temp[1] == '\0')
    {
    	printf("%d\n", ret);
		ft_putstr("Invalid file\n");
		exit(0);
	}
    return(temp);
}

void    ft_init(t_fdf *fdf, int nu)
{
    if(nu == 0)
    {
        fdf->height = 0;
        fdf->width = 0;
        fdf->win_h = 1000;
        fdf->win_w = 1000;
        fdf->mlx_ptr = mlx_init();
        fdf->win_ptr = mlx_new_window(fdf->mlx_ptr, fdf->win_w, fdf->win_h, "FDF");
        fdf->img_ptr = mlx_new_image(fdf->mlx_ptr, fdf->win_w, fdf->win_h);
        fdf->img = (int*)mlx_get_data_addr(fdf->img_ptr, &fdf->bpp, &fdf->size_line, &fdf->endian);
        mlx_hook(fdf->win_ptr, 2, 0, keys, fdf);
    }
    if (nu == 1)
    {
        fdf->place_w = (fdf->win_w - (fdf->width - 1) * fdf->mult) / 2;
        fdf->place_h = (fdf->win_h - (fdf->height - 1) * fdf->mult) / 2;
        fdf->beplace_h = fdf->place_h;
        fdf->beplace_w = fdf->place_w;
    }
}

int validcolor(t_fdf *fdf, int i, char *temp)
{
	while (temp[i])
	{
		if ((temp[i] >= '0' && temp[i] <= '9') || (temp[i] >= 'A' && temp[i] <= 'F') ||
			(temp[i] >= 'a' && temp[i] <= 'f'))
			i++;
		else
			return (1);
	}
	return (0);
}

void    ft_color(t_fdf *fdf, char *temp, int x, int y)
{
    int i;
    char *color;

    i = 0;
    while(temp[i])
    {
        if (temp[i] == ',')
        {
            if(temp[i + 1] == '0' && temp[i + 2] == 'x')
            {
				i += 3;
            	if(validcolor(fdf, i, temp) == 1)
            	{
					fdf->mass[y][x].color = 0x00FFFF;
					return;
				}
                color = ft_strsub(temp, i, ft_strlen(temp) - i);
                fdf->mass[y][x].color = ft_atoi_base(color, 16);
                return;
            }
        }
        i++;
    }
    fdf->mass[y][x].color = 0x00FFFF;
}

void    coordinates(int fd, t_fdf *fdf) //-
{
    int x;
    int y;
    char *buf;
    char **temp;

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
    ft_mult(fdf);

    while (y < fdf->height)
    {
        x = 0;
        if (!(fdf->mass[y] = (t_coor*)malloc(sizeof(t_coor) * fdf->width)))
            exit(0);
        if (!(fdf->begin[y] = (t_coor*)malloc(sizeof(t_coor) * fdf->width)))
            exit(0);
        validation(fdf, temp);
        while (x < fdf->width)
        {
            fdf->mass[y][x].x = x;
            fdf->mass[y][x].y = y;
            fdf->mass[y][x].z = ft_atoi(temp[x]);
            ft_color(fdf, temp[x], x, y);
            fdf->begin[y][x].x = x;
            fdf->begin[y][x].y = y;
            fdf->begin[y][x].z = ft_atoi(temp[x]);
            x++;
        }
        y++;
        ft_strdel(temp);
        temp = ft_strsplit(fdf->map[y], ' ');
    }
    ft_init(fdf, 1);
}