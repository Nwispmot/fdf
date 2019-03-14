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

int main(int argc, char **argv)
{
    int fd;
    t_fdf *fdf;
    int i;

    i = 0;
    fd = open(argv[1], O_RDONLY);
    if (argc != 2)
    {
        ft_putstr("Usage : ./fdf <filename> [ case_size z_size ]\n");
        return (0);
    }
    if (fd < 0)
    {
        ft_putstr("error\n");
        return (0);
    }
    fdf = coordinates(fd);
    fdf->place_w = (fdf->win_w - (fdf->width - 1) * fdf->mult) / 2;
    fdf->place_h = (fdf->win_h - (fdf->height - 1) * fdf->mult) / 2;
    fdf->mlx_ptr = mlx_init();
    fdf->win_ptr = mlx_new_window(fdf->mlx_ptr, fdf->win_w, fdf->win_h, "FDF");
    print(fdf);
    mlx_hook(fdf->win_ptr, 2, 0, keys, fdf);
    mlx_loop(fdf->mlx_ptr);
}
