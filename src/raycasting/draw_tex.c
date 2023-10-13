/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_tex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleiria- <lleiria-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 17:28:00 by lleiria-          #+#    #+#             */
/*   Updated: 2023/10/13 16:38:06 by lleiria-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	put_tex(int x, int side, t_input *vars)
{
	vars->tex_i = select_wall(side);
	if (side == 0)
		vars->graph->wall_x = vars->play->pos_y \
			+ vars->play->perp_wall_dist * vars->play->ray_d_y;
	else
		vars->graph->wall_x = vars->play->pos_x \
			+ vars->play->perp_wall_dist * vars->play->ray_d_x;
	vars->graph->wall_x -= floor((vars->graph->wall_x));
	tex_coord(x, side, vars);
}

void	start_draw_tex(int x, int side)
{
	vars()->graph->line_height = (int)(WIN_HEI / vars()->play->perp_wall_dist);
	vars()->graph->pitch = 100;
	vars()->graph->draw_start = -vars()->graph->line_height / 2 \
		+ WIN_HEI / 2 + vars()->graph->pitch;
	if (vars()->graph->draw_start < 0)
		vars()->graph->draw_start = 0;
	vars()->graph->draw_end = vars()->graph->line_height / 2 \
		+ WIN_HEI / 2 + vars()->graph->pitch;
	if (vars()->graph->draw_end >= WIN_HEI)
		vars()->graph->draw_end = WIN_HEI - 1;
	put_tex(x, side, vars());
}
