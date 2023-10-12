/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_data2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleiria- <lleiria-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 12:39:20 by fpereira          #+#    #+#             */
/*   Updated: 2023/10/12 16:35:38 by lleiria-         ###   ########.fr       */
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

void	initialize_matrix(char **tmp)
{
	int	i;

	i = -1;
	printf("Lines: %d\n", vars()->lines);
	if (vars()->lines == 0)
		tmp[0] = NULL;
	while (++i <= vars()->lines)
		tmp[i] = NULL;
}
int	is_not_alright(void)
{
	if (vars()->no == NULL || vars()->so == NULL || vars()->we == NULL
		|| vars()->ea == NULL || vars()->f < 0 || vars()->c < 0)
		return (msg_error("\e[1;91mError\nwrong number of elements\n\e[0m"));
	return (0);
}