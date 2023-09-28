/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_tex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleiria- <lleiria-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 17:28:00 by lleiria-          #+#    #+#             */
/*   Updated: 2023/09/28 18:01:38 by lleiria-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

int	select_wall(int side)
{
	if (side == 0)
	{
		if (vars()->play->ray_d_x < 0)
			return (2);
		else
			return (3);
	}
	else
	{
		if (vars()->play->ray_d_y < 0)
			return (0);
		else
			return (1);
	}
}

void	put_tex(int x, int side)
{
	int	tex_index;

	tex_index = select_wall(side);
    if (side == 0)
        vars()->graph->wallX = vars()->play->pos_y
            + vars()->play->perp_wall_dist * vars()->play->ray_d_y;
    else
        vars()->graph->wallX = vars()->play->pos_x
            + vars()->play->perp_wall_dist * vars()->play->ray_d_x;
    vars()->graph->wallX -= floor((vars()->graph->wallX));
}

void	start_draw_tex(int x, int side)
{
	int	color;
	(void)side;

	color = DARK_RED;
	vars()->graph->line_height = (int)(WIN_HEI / vars()->play->perp_wall_dist);
	int pitch = 100;
	vars()->graph->draw_start = -vars()->graph->line_height / 2 + WIN_HEI / 2 + pitch;
	if (vars()->graph->draw_start < 0)
		vars()->graph->draw_start = 0;
	vars()->graph->draw_end = vars()->graph->line_height / 2 + WIN_HEI / 2 + pitch;
	if (vars()->graph->draw_end >= WIN_HEI)
		vars()->graph->draw_end = WIN_HEI - 1;
	// if (side == 0)
	// 	color /= 2;
	put_tex(x, color);
}