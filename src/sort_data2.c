/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_data2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpereira <fpereira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 12:39:20 by fpereira          #+#    #+#             */
/*   Updated: 2023/10/06 14:37:23 by fpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	rev_strstr(char *str, char *find)
{
	int	i;
	int	j;

	i = ft_strlen(str) - 2;
	j = ft_strlen(find) - 1;
	while (i >= 0 && j >= 0)
	{
		if (str[i] != find[j])
			return (1);
		i--;
		j--;
	}
	return (0);
}

char	*ft_strdupcub(const char *s1)
{
	char	*p;
	size_t	n;
	size_t	slen;

	slen = ft_strlen(s1);
	p = (char *)malloc(sizeof(char) * (slen + 1));
	n = 0;
	if (p == NULL)
		return (NULL);
	while (s1 && (s1[n] != '\0' && s1[n] != '\n'))
	{
		p[n] = s1[n];
		n++;
	}
	p[n] = '\0';
	return (p);
}

int	check_image(char *element)
{
	int		fd;
	char	*tmp;
	
	tmp = ft_strchr(element, ' ');
	tmp++;
	if (rev_strstr(tmp, ".xpm"))
		return (1);
	tmp = ft_strdupcub(tmp);
	fd = open(tmp, O_RDONLY);
	free(tmp);
	if (fd < 0)
		return (1);
	close(fd);
	return (0);
}
