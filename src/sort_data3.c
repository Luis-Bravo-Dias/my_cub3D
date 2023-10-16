/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_data3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpereira <fpereira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 16:04:55 by fpereira          #+#    #+#             */
/*   Updated: 2023/10/16 16:07:07 by fpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	sort_checks(char map_line, int option)
{
	if (option == 1)
	{
		if (map_line && (map_line == 1 || map_line == 0
				|| map_line == ' ' || map_line == '\t'))
			return (1);
		if (map_line != '1' && map_line != '0' && map_line != '\n')
		{
			if (map_line == 'N' || map_line == 'S'
				|| map_line == 'W' || map_line == 'E'
				|| map_line == 'F' || map_line == 'C')
				vars()->six_elems++;
		}
		return (0);
	}
	if (option == 2)
	{
		if (map_line == 'N' || map_line == 'S'
			|| map_line == 'W' || map_line == 'E')
			return (1);
		return (0);
	}
	return (0);
}

int	sort_check_elems(char *map_line, char **tmp)
{
	if (vars()->six_elems != 6)
	{
		if (map_line)
			free(map_line);
		if (tmp)
			free_matrix(tmp);
		return (msg_error("\e[1;91mError\nWrong number of elements\n\e[0m"));
	}
	return (0);
}

char	*assign_dup(char *map_line, int map_flag)
{
	if (map_flag == 1 && vars()->lines > 0)
	{
		vars()->lines--;
		return (ft_strdup_cub(map_line, map_flag));
	}
	else if (map_line[0] != '\n' && vars()->lines > 0)
	{
		vars()->lines--;
		return (ft_strdup_cub(map_line, map_flag));
	}
	return (NULL);
}

int	invalid_image_case(char *map_line, char **tmp)
{
	if (map_line)
		free(map_line);
	free_matrix(tmp);
	return (msg_error("\e[1;91mError\nInvalid images.\n\e[0m"));
}
