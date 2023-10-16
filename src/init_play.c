/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_play.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleiria- <lleiria-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 17:22:58 by lleiria-          #+#    #+#             */
/*   Updated: 2023/10/16 17:26:32 by lleiria-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	n_play(void)
{
	vars()->play->dir_x = 0;
	vars()->play->dir_y = -1;
	vars()->play->plane_x = -0.66;
	vars()->play->plane_y = 0;
}

void	s_play(void)
{
	vars()->play->dir_x = 0;
	vars()->play->dir_y = 1;
	vars()->play->plane_x = 0.66;
	vars()->play->plane_y = 0;
}

void	e_play(void)
{
	vars()->play->dir_x = 1;
	vars()->play->dir_y = 0;
	vars()->play->plane_x = 0;
	vars()->play->plane_y = 0.66;
}

void	w_play(void)
{
	vars()->play->dir_x = -1;
	vars()->play->dir_y = 0;
	vars()->play->plane_x = 0;
	vars()->play->plane_y = -0.66;
}

void	define_dir_values(void)
{
	if (vars()->st_dir == 'N')
		n_play();
	else if (vars()->st_dir == 'S')
		s_play();
	else if (vars()->st_dir == 'E')
		e_play();
	else if (vars()->st_dir == 'W')
		w_play();
}
