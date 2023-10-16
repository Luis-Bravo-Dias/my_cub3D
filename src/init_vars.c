/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_vars.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpereira <fpereira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 17:33:23 by lleiria-          #+#    #+#             */
/*   Updated: 2023/10/16 15:46:21 by fpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	init_color(void)
{
	vars()->c = -2;
	vars()->f = -2;
	vars()->no = NULL;
	vars()->so = NULL;
	vars()->ea = NULL;
	vars()->we = NULL;
}

void	init_keys(void)
{
	printf("teste\n");
	vars()->key = (t_key *)malloc(sizeof(t_key));
	vars()->key->d = 0;
	vars()->key->a = 0;
	vars()->key->w = 0;
	vars()->key->s = 0;
	vars()->key->left = 0;
	vars()->key->right = 0;
}

void	init_graph(void)
{
	vars()->graph->line_height = 0;
	vars()->graph->draw_start = 0;
	vars()->graph->draw_end = 0;
	vars()->graph->pitch = 0;
	vars()->graph->wall_x = 0.0;
	vars()->graph->tex_x = 0;
	vars()->graph->tex_y = 0;
	vars()->graph->step = 0.0;
	vars()->graph->tex_pos = 0.0;
	vars()->graph->color = 0;
}

void	init_vars(void)
{
	vars()->play = (t_player *)malloc(sizeof(t_player));
	vars()->chrono = (t_time *)malloc(sizeof(t_time));
	vars()->graph = (t_graph *)malloc(sizeof(t_graph));
	find_player();
	define_dir_values();
	vars()->tex_i = -1;
	vars()->play->cam_x = 0;
	vars()->play->ray_d_x = 0;
	vars()->play->ray_d_y = 0;
	vars()->play->side_dist_x = 0;
	vars()->play->side_dist_y = 0;
	vars()->play->d_dist_x = 0;
	vars()->play->d_dist_y = 0;
	vars()->play->step_x = 0;
	vars()->play->step_y = 0;
	vars()->play->side = 0;
	vars()->play->perp_wall_dist = 0;
	vars()->play->hit = 0;
	vars()->play->side = 0;
	vars()->play->map_x = 0;
	vars()->play->map_y = 0;
	vars()->chrono->time = 0;
	vars()->chrono->old_time = 0;
	vars()->six_elems = 0;
	init_graph();
}
