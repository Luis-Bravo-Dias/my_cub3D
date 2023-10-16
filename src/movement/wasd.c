/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wasd.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleiria- <lleiria-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 12:40:43 by ubuntu            #+#    #+#             */
/*   Updated: 2023/10/16 18:14:16 by lleiria-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	move_play(void)
{
	double	new_dir_x;
	double	new_dir_y;

	new_dir_x = ((-vars()->play->dir_x * vars()->key->w) \
			- (vars()->play->dir_y * vars()->key->a) \
			- (-vars()->play->dir_x * vars()->key->s) \
			+ (vars()->play->dir_y * vars()->key->d)) / (16 * 2);
	new_dir_y = ((vars()->play->dir_y * vars()->key->w) \
			- (vars()->play->dir_x * vars()->key->a) \
			- (vars()->play->dir_y * vars()->key->s) \
			+ (vars()->play->dir_x * vars()->key->d)) / (16 * 2);
	// printf("pos:\n x[%f]y[%f]\n,mov:\n x[%f]y[%f]\n",vars()->play->dir_x, vars()->play->dir_y, new_dir_x, new_dir_y);
	if (vars()->map[(int)(vars()->play->pos_y)][(int)(vars()->play->pos_x \
		+ new_dir_x)] == '0')
		vars()->play->pos_x += new_dir_x;
	if (vars()->map[(int)(vars()->play->pos_y \
		+ vars()->play->dir_y)][(int)(vars()->play->pos_x)] == '0')
		vars()->play->pos_y += new_dir_y;
}

void	horizontal_rot(t_player *p, double angle)
{
	double	old_dir;
	double	old_plane;

	if (angle == 0)
		return ;
	angle = -angle;
	printf("angle = %f\n", angle);
	old_dir = p->dir_x;
	old_plane = p->plane_x;
	

	printf("looking at x[%f]y[%f]\n", p->dir_x, p->dir_y);
	p->dir_x = p->dir_x * cos(angle) - p->dir_y * sin(angle);
	p->dir_y = old_dir * sin(angle) + p->dir_y * cos(angle);
	p->plane_x = p->plane_x * cos(angle) - p->plane_y * sin(angle);
	p->plane_y = old_plane * sin(angle) + p->plane_y * cos(angle);
	printf("looking at x[%f]y[%f] after moving\n", p->dir_x, p->dir_y);
}
