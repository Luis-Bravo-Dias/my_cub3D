/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpereira <fpereira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 16:09:34 by lleiria-          #+#    #+#             */
/*   Updated: 2023/10/11 15:50:31 by fpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"



int	is_not_alright(void)
{
	if (vars()->no == NULL || vars()->so == NULL || vars()->we == NULL
		|| vars()->ea == NULL || vars()->f < 0 || vars()->c < 0)
		return (msg_error("\e[1;91mError\nwrong number of elements\n\e[0m"));
	return (0);
}

int	is_not_color(char **rgb)
{
	int i;
	int	j;
	
	i = 0;
	while (rgb[i])
	{
		j = 0;
		if (!ft_strlen(rgb[i]) || (rgb[i][0] == '0' && ft_strlen(rgb[i]) > 1))
		{
			printf("rgb = %s|\n", rgb[i]);
			printf("strlen(rgb) = %zu\n", ft_strlen(rgb[i]));
			printf("test1\n");
			return (1);
		}
		while(rgb[i][j])
		{
			if (rgb[i][j] < '0' || rgb[i][j] > '9')
			{
				printf("test2\n");
				return (1);
			}	
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
	int g;
	int b;

	i = 0;
	while (rgb[i])
		i++;
			printf("color\n");

	if (i != 3)
	{
		free_matrix(rgb);
		return (-1);
	}
		printf("color\n");

	if (is_not_color(rgb))
	{
		free_matrix(rgb);
		return (-1);
	}
	r = ft_atoi(rgb[0]);
	g = ft_atoi(rgb[1]);
	b = ft_atoi(rgb[2]);
	free_matrix(rgb);
	printf("color = r[%d] g[%d] b[%d]\n", r, g, b);
	if (r > 255 || g > 255 || b > 255)
		return (-1);
	return((r << 16) + (g << 8) + b);
	
}

void	is_element(char *line)
{
	if (!ft_strncmp(line, "NO ", 3) && vars()->no == NULL)
		vars()->no = ft_strdup(line + 3);
	else if (!ft_strncmp(line, "SO ", 3) && vars()->so == NULL)
		vars()->so = ft_strdup(line + 3);
	else if (!ft_strncmp(line, "WE ", 3) && vars()->we == NULL)
		vars()->we = ft_strdup(line + 3);
	else if (!ft_strncmp(line, "EA ", 3) && vars()->ea == NULL)
		vars()->ea = ft_strdup(line + 3);
	else if (!ft_strncmp(line, "F ", 2) && vars()->f == -2)
		vars()->f = get_color(ft_split(line + 2, ','));
	else if (!ft_strncmp(line, "C ", 2) && vars()->c == -2)
		vars()->c = get_color(ft_split(line + 2, ','));
}

int	put_elems(char **tmp)
{
	int	i;

	i = -1;
	//printf("Tmp: %s\n", tmp[0]);
	if (tmp && !tmp[0])
	{
		free(tmp);
		return (msg_error(strerror(errno)));
	}
	vars()->lines = matrix_size(tmp) - 6;
	while (++i <= 5)
		is_element(tmp[i]);
	printf("ceiling = %d, floor = %d\n", vars()->c, vars()->f);
	if (is_not_alright())
	{
		free_matrix(tmp);
		return (msg_error("\e[1;91mError\nElements can't be stored\n\e[0m"));
	}
	vars()->map = malloc(sizeof(char **) * (vars()->lines + 1));
	if (!vars()->map)
		return (msg_error(strerror(errno)));
	vars()->map[vars()->lines] = NULL;
	while (tmp[i] && i < vars()->lines + 6)
	{
		vars()->map[i - 6] = ft_strdup(tmp[i]);
		i++;
	}
	free_matrix(tmp);
	return (0);
}

void	initialize_matrix(char **tmp)
{
	int	i;

	i = -1;
	printf("Lines: %d\n", vars()->lines);
	if (vars()->lines == 0)
		tmp[0] = NULL;
	while (++i <= vars()->lines)
		tmp[i] = NULL;
	//tmp = NULL;
}

int	sort_data(char *file)
{
	int		fd;
	int		i;
	int		six_elems;
	char	**tmp;
	char	*map_line;

	six_elems = 0;
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (msg_error(strerror(errno)));
	vars()->lines = file_lines(file);
	tmp = malloc(sizeof(char *) * (vars()->lines + 1));
	initialize_matrix(tmp);
	i = -1;
	map_line = get_next_line(fd);
	while (map_line)
	{
		if (map_line[0] != '1' && map_line[0] != '0' && map_line[0] != '\n')
			if (map_line[0] == 'N' || map_line[0] == 'S' || map_line[0] == 'W' || map_line[0] == 'E'
				|| map_line[0] == 'F' || map_line[0] == 'C')
				six_elems++;
		if (map_line[0] == 'N' || map_line[0] == 'S' || map_line[0] == 'W' || map_line[0] == 'E')
			if (check_image(map_line))
			{
				if (map_line)
					free(map_line);
				free_matrix(tmp);
				return (msg_error(strerror(errno)));
			}
		if (map_line[0] != '\n' && vars()->lines > 0)
		{
			tmp[++i] = ft_strdup_cub(map_line);
			vars()->lines--;
		}
		free(map_line);
		map_line = get_next_line(fd);
	}
	if (six_elems != 6)
	{
		if (map_line)
			free(map_line);
		if (tmp)
			free_matrix(tmp);
		return (msg_error(strerror(errno)));
	}
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
