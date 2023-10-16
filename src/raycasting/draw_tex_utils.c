/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_tex_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleiria- <lleiria-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 16:37:38 by lleiria-          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2023/10/16 18:37:10 by lleiria-         ###   ########.fr       */
=======
/*   Updated: 2023/10/16 17:58:45 by lleiria-         ###   ########.fr       */
>>>>>>> 56d792690744c90446ec5cab0b0a5cfcaf862a39
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

unsigned int	get_tex_col(t_img tex, int x, int y)
{
	unsigned int	color;

	color = *((unsigned int *)((tex.addr) + (y * tex.line_length + (x \
		* (tex.bits_per_pixel / 8)))));
	return (color);
}

void	x_of_tex(t_input *vars, int side)
{
	vars->graph->tex_x = (int)(vars->graph->wall_x \
		* vars->tex[vars->tex_i].wid); 
	if (side == 0 && vars->play->ray_d_x > 0)
		vars->graph->tex_x = vars->tex[vars->tex_i].wid \
			- vars->graph->tex_x - 1;
	if (side == 1 && vars->play->ray_d_y < 0)
		vars->graph->tex_x = vars->tex[vars->tex_i].wid \
			- vars->graph->tex_x - 1;
	vars->graph->step = 1.0 \
		* vars->tex[vars->tex_i].hei / vars->graph->line_height;
	vars->graph->tex_pos = (vars->graph->draw_start - vars->graph->pitch \
		- WIN_HEI / 2 + vars->graph->line_height / 2) * vars->graph->step;
}

void	draw_wall(t_input *vars, int x, int y, int side)
{
	vars->graph->tex_y = (int)vars->graph->tex_pos \
		& (vars->tex[vars->tex_i].hei - 1);
	vars->graph->tex_pos += vars->graph->step;
	vars->graph->color = get_tex_col(vars->tex[vars->tex_i], \
	vars->graph->tex_x, vars->graph->tex_y);
	if (side == 1)
		vars->graph->color = (vars->graph->color >> 1) & 8355711;
	my_mlx_pixel_put(x, y, vars->graph->color);
}

void	tex_coord(int x, int side, t_input	*vars)
{
	int	y;

	if (vars->st_dir == 'N' || vars->st_dir == 'S')
		x = WIN_WID - x;
	printf("x = %d\n", x);
	x_of_tex(vars, side);
	y = 0;
	while (y < vars->graph->draw_start)
	{
		my_mlx_pixel_put(x, y, vars->c);
		y++;
	}
	while (y < vars->graph->draw_end)
	{
		draw_wall(vars, x, y, side);
		y++;
	}
	while (y < WIN_HEI)
	{
		my_mlx_pixel_put(x, y, vars->f);
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
