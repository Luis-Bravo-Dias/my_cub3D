/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_data3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleiria- <lleiria-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 16:37:09 by lleiria-          #+#    #+#             */
/*   Updated: 2023/10/12 16:39:46 by lleiria-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	is_not_color(char **rgb)
{
	int	i;
	int	j;

	i = 0;
	while (rgb[i])
	{
		j = 0;
		if (!ft_strlen(rgb[i]) || (rgb[i][0] == '0' && ft_strlen(rgb[i]) > 1))
			return (1);
		while (rgb[i][j])
		{
			if (rgb[i][j] < '0' || rgb[i][j] > '9')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	get_color(char **rgb)
{
	int	i;
	int	r;
	int	g;
	int	b;

	i = 0;
	while (rgb[i])
		i++;
	if (i != 3)
	{
		free_matrix(rgb);
		return (-1);
	}
	if (is_not_color(rgb))
	{
		free_matrix(rgb);
		return (-1);
	}
	r = ft_atoi(rgb[0]);
	g = ft_atoi(rgb[1]);
	b = ft_atoi(rgb[2]);
	free_matrix(rgb);
	if (r > 255 || g > 255 || b > 255)
		return (-1);
	return ((r << 16) + (g << 8) + b);
}