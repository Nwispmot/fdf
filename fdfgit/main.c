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

int	main(int argc, char **argv)
{
	int		fd;
	t_fdf	*fdf;

	if (argc != 2)
	{
		ft_putstr("Usage : ./fdf <filename> [ case_size z_size ]\n");
		return (0);
	}
	if (!(fdf = (t_fdf *)malloc(sizeof(t_fdf))))
		exit(0);
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
		ft_putstr("read error\n");
		return (0);
	}
	ft_init(fdf, 0);
	coordinates(fd, fdf);
	print(fdf);
	mlx_loop(fdf->mlx_ptr);
	exit(0);
}
