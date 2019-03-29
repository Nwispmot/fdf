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
# include <fcntl.h>
# include "libft/libft.h"
# include <math.h>

typedef struct		s_coordinates
{
	double			x;
	double			y;
	double			z;
	int				color;
}					t_coor;

typedef struct		s_var
{
	double			dx;
	double			dy;
	double			yi;
	double			xi;
	double			x;
	double			y;
	double			d;
}					t_v;

typedef struct		s_mcoor
{
	t_coor			**mass;
	t_coor			**begin;
	void			*mlx_ptr;
	void			*win_ptr;
	void			*img_ptr;
	int				height;
	int				width;
	int				win_h;
	int				win_w;
	char			**map;
	char			**temp;
	int				mult;
	int				bemult;
	int				beplace_w;
	int				beplace_h;
	int				place_w;
	int				place_h;
	int				*img;
	int				bpp;
	int				size_line;
	int				endian;
	int				x;
	int				y;
	double			sico;
	double			x0;
	double			y0;
	double			x1;
	double			y1;
	int				cx;
	int				cy;
}					t_fdf;

int					keys(int key, t_fdf *fdf);
int					validcolor(t_fdf *fdf, int i, char *temp);
void				validation(t_fdf *fdf, char **temp);
void				coordinates(int fd, t_fdf *fdf);
void				bresenham(t_fdf *fdf);
void				print(t_fdf *fdf);
void				begin(t_fdf *fdf, int pr);
void				ud_rotation(t_fdf *fd, int key);
void				lr_rotation(t_fdf *fdf, int key);
void				z_rotation(t_fdf *fdf, int key);
void				scale(t_fdf *fdf, int key);
void				move_x(t_fdf *fdf, int key);
void				move_y(t_fdf *fdf, int key);
void				iso(t_fdf *fdf);
void				ft_init(t_fdf *fdf, int nu);
void				validation(t_fdf *fdf, char **temp);
void				ft_malloc(t_fdf *fdf, int y, int c);
void				coords_n_copy(t_fdf *fdf, int x, int y, char *temp);
void				count(t_fdf *fdf);
void				ft_color(t_fdf *fdf, char *temp, int x, int y);

#endif
