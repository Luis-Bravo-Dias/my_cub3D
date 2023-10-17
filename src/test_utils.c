/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpereira <fpereira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 17:11:39 by ubuntu            #+#    #+#             */
/*   Updated: 2023/10/17 17:02:40 by fpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	print_matrix(char **matrix)
{
	int	i;

	i = 0;
	printf("  0123456789abcdefghijklmnopqrstuvwxyz\n");
	while (matrix[i])
	{
		printf("%x:%s\n", i, matrix[i]);
		i++;
	}
}
