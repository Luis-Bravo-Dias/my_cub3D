/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpereira <fpereira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 11:44:45 by lleiria-          #+#    #+#             */
/*   Updated: 2023/10/11 17:49:33 by fpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	matrix_size(char **matrix)
{
	int	counter;

	counter = 0;
	while (matrix[counter])
		counter++;
	return (counter);
}

char	*ft_strdup_cub(const char *s1, int map_flag)
{
	char	*p;
	size_t	n;
	size_t	slen;

	slen = ft_strlen(s1);
	//printf("string: %s\nlen: %zu\n\n\n", s1, slen);
	p = (char *)malloc(sizeof(char) * (slen + 1));
	n = 0;
	if (p == NULL)
		return (NULL);
	if (map_flag == 0)
		while (s1[n] != '\0' && s1[n] != '\n')
		{
			p[n] = s1[n];
			n++;
		}
	else if (map_flag == 1)
		while (s1[n] != '\0')
		{
			p[n] = s1[n];
			n++;
		}
	p[n] = '\0';
	printf("string to return: %s", p);
	return (p);
}

int	file_lines(char *file)
{
	int		counter;
	int		fd;
	char	*line;

	counter = 0;
	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		msg_error("\e[1;91mError\nCould not open file.\n\e[0m");
		exit(2);
	}
	line = get_next_line(fd);
	while (line)
	{
		counter++;
		free(line);
		line = get_next_line(fd);
	}
	if (line)
		free(line);
	close(fd);
	return (counter);
}
