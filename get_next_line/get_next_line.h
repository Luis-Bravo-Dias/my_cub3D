/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpereira <fpereira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 12:46:54 by lleiria-          #+#    #+#             */
/*   Updated: 2023/10/09 15:29:07 by fpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

# define BUFFER_SIZE 1

char	*get_next_line(int fd);
char	*ft_strchr2(const char *str, int c);
size_t	ft_strlen2(const char	*str);
void	*ft_memcpy2(void	*dest, const void *src, size_t n);
char	*ft_strdup2(const char *s1);
char	*ft_strjoin2(char const *s1, char const *s2);

#endif