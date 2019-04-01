/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwispmot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 20:07:56 by nwispmot          #+#    #+#             */
/*   Updated: 2019/03/28 20:08:10 by nwispmot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	isnum(char *temp)
{
	int i;

	i = 0;
	if (temp[i] == '-')
		i++;
	if (temp[i] >= '0' && temp[i] <= '9')
		i++;
	else
		return (1);
	while (temp[i] != '\0' && temp[i] != ',')
	{
		if (temp[i] >= '0' && temp[i] <= '9')
			i++;
		else
			return (1);
	}
	return (0);
}

void		validation(t_fdf *fdf, char **temp)
{
	int width;
	int i;

	i = 0;
	if (!temp)
		exit(0);
	width = 0;
	while (temp[width] != NULL)
		width++;
	if (fdf->width != width)
	{
		ft_putstr("Invalid file (width)\n");
		exit(0);
	}
	while (temp[i] != NULL)
	{
		if (isnum(temp[i]) == 1)
		{
			ft_putstr("Invalid file (number)\n");
			exit(0);
		}
		i++;
	}
}

int			validcolor(int i, char *temp)
{
	while (temp[i])
	{
		if ((temp[i] >= '0' && temp[i] <= '9') ||
		(temp[i] >= 'A' && temp[i] <= 'F') ||
			(temp[i] >= 'a' && temp[i] <= 'f'))
			i++;
		else
			return (1);
	}
	return (0);
}
