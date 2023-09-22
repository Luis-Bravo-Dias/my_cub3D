/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tex_raycast.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <ubuntu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 12:17:35 by ubuntu            #+#    #+#             */
/*   Updated: 2023/05/19 12:11:57 by ubuntu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	tex_raycast(void)
{
	int	hit;
	int	side;

	vars()->play->cam_x = 2 * x / (double)WIN_WID - 1;
	vars()->play->ray_d_x = -vars()->play->dir_x - vars()->play->plane_x \
		* vars()->play->cam_x;
	vars()->play->ray_d_y = vars()->play->dir_y + vars()->play->plane_y \
		* vars()->play->cam_x;
	vars()->play->map_x = (int)vars()->play->pos_x;
	vars()->play->map_y = (int)vars()->play->pos_y;
	if (vars()->play->ray_d_x == 0)
		vars()->play->d_dist_x = DBL_MAX;
	else
		vars()->play->d_dist_x = fabs(1 / vars()->play->ray_d_x);
	if (vars()->play->ray_d_y == 0)
		vars()->play->d_dist_y = DBL_MAX;
	else
		vars()->play->d_dist_y = fabs(1 / vars()->play->ray_d_y);
	hit = 0;
	if (vars()->play->ray_d_x < 0)
	{
		vars()->play->step_x = -1;
		vars()->play->side_dist_x = (vars()->play->pos_x \
			- vars()->play->map_x) * vars()->play->d_dist_x;
	}
	else
	{
		vars()->play->step_x = 1;
		vars()->play->side_dist_x = (vars()->play->map_x + 1.0 \
			- vars()->play->pos_x) * vars()->play->d_dist_x;
	}
	if (vars()->play->ray_d_y < 0)
	{
		vars()->play->step_y = -1;
		vars()->play->side_dist_y = (vars()->play->pos_y \
			- vars()->play->map_y) * vars()->play->d_dist_y;
	}
	else
	{
		vars()->play->step_y = 1;
		vars()->play->side_dist_y = (vars()->play->map_y + 1.0 \
			- vars()->play->pos_y) * vars()->play->d_dist_y;
	}
	while (hit == 0)
	{
		if (vars()->play->side_dist_x < vars()->play->side_dist_y)
		{
			vars()->play->side_dist_x += vars()->play->d_dist_x;
			vars()->play->map_x += vars()->play->step_x;
			side = 0;
		}
		else
		{
			vars()->play->side_dist_y += vars()->play->d_dist_y;
			vars()->play->map_y += vars()->play->step_y;
			side = 1;
		}
		if (vars()->map[vars()->play->map_y][vars()->play->map_x] == '1')
			hit = 1;
	}
	if (side == 0)
		vars()->play->perp_wall_dist = (vars()->play->map_x \
			- vars()->play->pos_x + (1 - vars()->play->step_x) / 2) \
			/ vars()->play->ray_d_x;
	else
		vars()->play->perp_wall_dist = (vars()->play->map_y \
			- vars()->play->pos_y + (1 - vars()->play->step_y) / 2) \
			/ vars()->play->ray_d_y;
	fps_count();
}
