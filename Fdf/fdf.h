/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwispmot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/02 17:49:44 by nwispmot          #+#    #+#             */
/*   Updated: 2019/03/02 17:49:59 by nwispmot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "mlx.h"
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include "libft/libft.h"
# define BUFF_SIZE 10000
# include <math.h>

typedef struct s_coordinates
{
    double x;
    double y;
    double z;
    int color;
}              t_coor;

typedef struct s_mcoor
{
    t_coor **mass;
    t_coor **begin;
    void *mlx_ptr;
    void *win_ptr;
    int height;
    int width;
    int win_h;
    int win_w;
    char **map;
    int mult;
    int bemult;
    int beplace_w;
    int beplace_h;
    int place_w;
    int place_h;
    int *image;
    double sico;
    double x0;
    double y0;

}              t_fdf;

double ft_abs(double value);
int keys(int key, t_fdf *fdf);
int keys2(int key, t_fdf *fdf);
void validation(t_fdf *fdf, char **temp);
t_fdf *coordinates(int fd);
void bresenham(t_fdf *fdf, double x0, double y0, double x1, double y1);
void print(t_fdf *fdf);
void begin(t_fdf *fdf, int pr);
void x_rotation(t_fdf *fdf);
void y_rotation(t_fdf *fdf);
void z_rotation(t_fdf *fdf);
void scale(t_fdf *fdf, int key);
void move_x(t_fdf *fdf, int key);
void move_y(t_fdf *fdf, int key);
void iso(t_fdf *fdf);

#endif
