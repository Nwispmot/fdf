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

void	assignment(t_fdf *fdf, int x, int y, char c)
{
	if (c == 'x')
	{
		fdf->x0 = fdf->mass[y][x].x * fdf->mult + fdf->place_w;
		fdf->y0 = fdf->mass[y][x].y * fdf->mult + fdf->place_h;
		fdf->x1 = fdf->mass[y][x + 1].x * fdf->mult + fdf->place_w;
		fdf->y1 = fdf->mass[y][x + 1].y * fdf->mult + fdf->place_h;
		fdf->cx = x;
		fdf->cy = y;
	}
	else if (c == 'y')
	{
		fdf->x0 = fdf->mass[y][x].x * fdf->mult + fdf->place_w;
		fdf->y0 = fdf->mass[y][x].y * fdf->mult + fdf->place_h;
		fdf->x1 = fdf->mass[y + 1][x].x * fdf->mult + fdf->place_w;
		fdf->y1 = fdf->mass[y + 1][x].y * fdf->mult + fdf->place_h;
		fdf->cx = x;
		fdf->cy = y;
	}
	bresenham(fdf);
}

void	print(t_fdf *fdf)
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
			assignment(fdf, x, y, 'x');
			assignment(fdf, x, y, 'y');
			x++;
		}
		assignment(fdf, x, y, 'y');
		y++;
	}
	x = 0;
	while (x < fdf->width - 1)
	{
		assignment(fdf, x, y, 'x');
		x++;
	}
	mlx_put_image_to_window(fdf->mlx_ptr, fdf->win_ptr, fdf->img_ptr, 0, 0);
}

void	begin(t_fdf *fdf, int pr)
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
