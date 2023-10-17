/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpereira <fpereira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 16:09:34 by lleiria-          #+#    #+#             */
/*   Updated: 2023/10/17 17:02:40 by fpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	is_element(char *line)
{
	char	**rgb_f;
	char	**rgb_c;

	rgb_f = NULL;
	rgb_c = NULL;
	if (!ft_strncmp(line, "NO ", 3) && vars()->no == NULL)
		vars()->no = ft_strdup(line + 3);
	else if (!ft_strncmp(line, "SO ", 3) && vars()->so == NULL)
		vars()->so = ft_strdup(line + 3);
	else if (!ft_strncmp(line, "WE ", 3) && vars()->we == NULL)
		vars()->we = ft_strdup(line + 3);
	else if (!ft_strncmp(line, "EA ", 3) && vars()->ea == NULL)
		vars()->ea = ft_strdup(line + 3);
	else if (!ft_strncmp(line, "F ", 2) && vars()->f == -2)
	{
		rgb_f = ft_split(line + 2, ',');
		vars()->f = get_color(rgb_f);
	}
	else if (!ft_strncmp(line, "C ", 2) && vars()->c == -2)
	{
		rgb_c = ft_split(line + 2, ',');
		vars()->c = get_color(rgb_c);
	}
}

int	check_elems(char **tmp)
{
	int	i;

	i = -1;
	vars()->lines = matrix_size(tmp) - 6;
	while (++i <= 5)
		is_element(tmp[i]);
	i = -1;
	i = 6;
	if (is_not_alright())
	{
		free_matrix(tmp);
		return (msg_error("\e[1;91mError\nElements can't be stored\n\e[0m"));
	}
	vars()->map = malloc(sizeof(char **) * (vars()->lines + 1));
	if (!vars()->map)
		return (msg_error("\e[1;91mError\nCould not allocate map.\n\e[0m"));
	vars()->map[vars()->lines] = NULL;
	while (tmp[i] && i < vars()->lines + 6)
	{
		vars()->map[i - 6] = ft_strdup(tmp[i]);
		i++;
	}
	free_matrix(tmp);
	return (0);
}

int	put_elems(char **tmp)
{
	if (tmp && !tmp[0])
	{
		free(tmp);
		return (msg_error("\e[1;91mError\nEmpty file.\n\e[0m"));
	}
	return (check_elems(tmp));
}

int	sort_data(char *file, int i, int map_flag)
{
	int		fd;
	char	**tmp;
	char	*map_line;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (msg_error("\e[1;91mError\nCould not open file.\n\e[0m"));
	vars()->lines = file_lines(file);
	tmp = malloc(sizeof(char *) * (vars()->lines + 1));
	initialize_matrix(tmp);
	map_line = get_next_line(fd);
	while (map_line && map_flag != 2)
	{
		map_flag = sort_checks(map_line[0], 1, map_flag);
		if (sort_checks(map_line[0], 2, map_flag))
			if (check_image(map_line))
				return (invalid_image_case(map_line, tmp));
		if ((map_flag == 1 || map_line[0] != '\n') && vars()->lines > 0)
			tmp[++i] = assign_dup(map_line, map_flag, tmp);
		free(map_line);
		map_line = get_next_line(fd);
	}
	if (sort_check_elems(map_line, tmp, map_flag))
		return (1);
	return (put_elems(tmp));
}

void	find_player(void)
{
	int	i;
	int	j;

	i = -1;
	while (vars()->map[++i])
	{
		j = -1;
		while (vars()->map[i][++j])
		{
			if (vars()->map[i][j] == 'N' || vars()->map[i][j] == 'S'
				|| vars()->map[i][j] == 'E' || vars()->map[i][j] == 'W')
			{
				vars()->play->pos_x = (double)j + 0.5;
				vars()->play->pos_y = (double)i + 0.5;
				vars()->st_dir = vars()->map[i][j];
				vars()->map[i][j] = '0';
			}
		}
	}
}
