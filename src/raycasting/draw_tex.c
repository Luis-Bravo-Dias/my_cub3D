/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_tex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpereira <fpereira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 17:28:00 by lleiria-          #+#    #+#             */
/*   Updated: 2023/10/04 15:40:54 by fpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

unsigned int	get_tex_col(t_img tex, int x, int y)
{
	return(*((unsigned int*)((tex.addr) + (y * tex.line_length + (x \
		* (tex.bits_per_pixel / 8))))));
}


void	tex_coord(int x, int side)
{
	int	y;
	
	vars()->graph->tex_x = (int)(vars()->graph->wall_x
		* vars()->tex[vars()->tex_i].wid); 
	if (side == 0 && vars()->play->ray_d_x > 0)
		vars()->graph->tex_x = vars()->tex[vars()->tex_i].wid
			- vars()->graph->tex_x - 1;
	if (side == 1 && vars()->play->ray_d_y < 0)
		vars()->graph->tex_x = vars()->tex[vars()->tex_i].wid
			- vars()->graph->tex_x - 1;
	vars()->graph->step = 1.0 \
		* vars()->tex[vars()->tex_i].hei / vars()->graph->line_height;
	vars()->graph->tex_pos = (vars()->graph->draw_start - vars()->graph->pitch
		- WIN_HEI / 2 + vars()->graph->line_height / 2) * vars()->graph->step;
	y = 0;
	while (y < vars()->graph->draw_end)
	{
		vars()->graph->tex_y = (int)vars()->graph->tex_pos
			& (vars()->tex[vars()->tex_i].hei - 1);
		vars()->graph->tex_pos += vars()->graph->step;
		vars()->graph->color = get_tex_col(vars()->tex[vars()->tex_i], vars()->graph->tex_x, vars()->graph->tex_y);
		//vars()->graph->color = vars()->tex[vars()->tex_i].hei \
		// 	* vars()->graph->tex_y + vars()->graph->tex_x;
		if (side == 1)
			vars()->graph->color = (vars()->graph->color>> 1) & 8355711;
		my_mlx_pixel_put(x, y, vars()->graph->color);
		// vars()->graph->buffer[y][x] = vars()->graph->color;
		y++;
	}
}

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
	vars()->tex_i = select_wall(side);
    if (side == 0)
        vars()->graph->wall_x = vars()->play->pos_y
            + vars()->play->perp_wall_dist * vars()->play->ray_d_y;
    else
        vars()->graph->wall_x = vars()->play->pos_x
            + vars()->play->perp_wall_dist * vars()->play->ray_d_x;
    vars()->graph->wall_x -= floor((vars()->graph->wall_x));
	tex_coord(x, side);
}

void	start_draw_tex(int x, int side)
{
	// int	color;

	// color = DARK_RED;
	vars()->graph->line_height = (int)(WIN_HEI / vars()->play->perp_wall_dist);
	vars()->graph->pitch = 100;
	vars()->graph->draw_start = -vars()->graph->line_height / 2 + WIN_HEI / 2 + vars()->graph->pitch;
	if (vars()->graph->draw_start < 0)
		vars()->graph->draw_start = 0;
	vars()->graph->draw_end = vars()->graph->line_height / 2 + WIN_HEI / 2 + vars()->graph->pitch;
	if (vars()->graph->draw_end >= WIN_HEI)
		vars()->graph->draw_end = WIN_HEI - 1;
	// if (side == 0)
	// 	color /= 2;
	put_tex(x, side);
}