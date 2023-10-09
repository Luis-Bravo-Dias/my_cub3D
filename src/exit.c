/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpereira <fpereira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 11:03:46 by lleiria-          #+#    #+#             */
/*   Updated: 2023/10/09 15:16:58 by fpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	free_array(char *str)
{
	if (str && *str)
		free(str);
}

void	free_matrix(char **matrix)
{
	int	i;

	i = 0;
	if (matrix)
	{
		while (matrix[i])
		{
			free_array(matrix[i]);
			i++;
		}
		free(matrix);
	}
}

int	msg_error(char *message)
{
	ft_putendl_fd(message, 2);
	return (1);
}

void free_map(void)
{
	int	i;

	i = -1;
	while (++i < vars()->lines)
		free(vars()->map[i]);
	free(vars()->map);
}

void free_elements(void)
{
	int	i;

	i = -1;
	free(vars()->no);
	free(vars()->so);
	free(vars()->we);
	free(vars()->ea);
	while (++i <= 3)
		mlx_destroy_image(vars()->mlx, vars()->tex[i].img);
}

int	ft_close(void)
{
	free_map();
	free_elements();
	mlx_destroy_window(vars()->mlx, vars()->window);
	mlx_destroy_display(vars()->mlx);
	free(vars()->mlx);
	free(vars()->img);
	free(vars()->key);
	free(vars()->graph);
	free(vars()->chrono);
	free(vars()->play);
	exit(0);
	return (0);
}