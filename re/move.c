/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwispmot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/15 18:00:27 by nwispmot          #+#    #+#             */
/*   Updated: 2019/03/15 18:00:29 by nwispmot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	move_x(t_fdf *fdf, int key)
{
	if (key == 124)
		fdf->place_w += 8;
	if (key == 123)
		fdf->place_w -= 8;
	print(fdf);
}

void	move_y(t_fdf *fdf, int key)
{
	if (key == 125)
		fdf->place_h += 8;
	if (key == 126)
		fdf->place_h -= 8;
	print(fdf);
}

void	scale(t_fdf *fdf, int key)
{
	if (key == 78)
	{
		fdf->mult--;
		if (fdf->mult < 0)
			fdf->mult = 0;
	}
	if (key == 69)
		fdf->mult++;
	print(fdf);
}
