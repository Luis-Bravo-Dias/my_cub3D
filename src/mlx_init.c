/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleiria- <lleiria-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 14:35:32 by ubuntu            #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2023/10/06 17:49:37 by lleiria-         ###   ########.fr       */
=======
/*   Updated: 2023/10/09 14:38:11 by fpereira         ###   ########.fr       */
>>>>>>> fpereira-test
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void init_color(void)
{
	vars()->c = -2;
	vars()->f = -2;
	vars()->no = NULL;
	vars()->so = NULL;
	vars()->ea = NULL;
	vars()->we = NULL;
}

void	define_dir_values(void)
{
	if (vars()->st_dir == 'N')
	{
		vars()->play->dir_x = 0;
		vars()->play->dir_y = -1;
		vars()->play->plane_x = -0.66;
		vars()->play->plane_y = 0;
	}
	else if (vars()->st_dir == 'S')
	{
		vars()->play->dir_x = 0;
		vars()->play->dir_y = 1;
		vars()->play->plane_x = 0.66;
		vars()->play->plane_y = 0;
	}
	else if (vars()->st_dir == 'E')
	{
		vars()->play->dir_x = 1;
		vars()->play->dir_y = 0;
		vars()->play->plane_x = 0;
		vars()->play->plane_y = 0.66;
	}
	else if (vars()->st_dir == 'W')
	{
		vars()->play->dir_x = -1;
		vars()->play->dir_y = 0;
		vars()->play->plane_x = 0;
		vars()->play->plane_y = -0.66;
	}
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

void	init_graph()
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
	//vars()->img = (t_img *)malloc(sizeof(t_img));
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
	init_graph();
}
void init_tex(void)
{
	int i;
	
	i = 0;
	while (i <= 3)
	{
		vars()->tex[i].addr = NULL;
		vars()->tex[i].hei = 0;
		vars()->tex[i].wid = 0;
		vars()->tex[i].bits_per_pixel = 0;
		vars()->tex[i].line_length = 0;
		vars()->tex[i].endian = 0;
		i++;
	}

}

void load_tex(void)
{
	init_tex();
	vars()->tex[0].img = mlx_xpm_file_to_image(vars()->mlx, vars()->no,
		&vars()->tex[0].wid, &vars()->tex[0].hei);
	printf("%s %p\n", vars()->no, vars()->tex[0].img);
	vars()->tex[0].addr = mlx_get_data_addr(vars()->tex[0].img,
		&vars()->tex[0].bits_per_pixel, &vars()->tex[0].line_length, &vars()->tex[0].endian);
	vars()->tex[1].img = mlx_xpm_file_to_image(vars()->mlx, vars()->so,
		&vars()->tex[1].wid, &vars()->tex[1].hei);
	vars()->tex[1].addr = mlx_get_data_addr(vars()->tex[1].img,
		&vars()->tex[1].bits_per_pixel, &vars()->tex[1].line_length, &vars()->tex[1].endian);
	vars()->tex[2].img = mlx_xpm_file_to_image(vars()->mlx, vars()->we,
		&vars()->tex[2].wid, &vars()->tex[2].hei);
	vars()->tex[2].addr = mlx_get_data_addr(vars()->tex[2].img,
		&vars()->tex[2].bits_per_pixel, &vars()->tex[2].line_length, &vars()->tex[2].endian);
	vars()->tex[3].img = mlx_xpm_file_to_image(vars()->mlx, vars()->ea,
		&vars()->tex[3].wid, &vars()->tex[3].hei);
	vars()->tex[3].addr = mlx_get_data_addr(vars()->tex[3].img,
		&vars()->tex[3].bits_per_pixel, &vars()->tex[3].line_length, &vars()->tex[3].endian);
}


void    init_cub(void)
{
	init_vars();
	init_keys();
	// load_imgs();
	vars()->img = (t_img *)malloc(sizeof(t_img));
    vars()->mlx = mlx_init();
	load_tex();
    vars()->window = mlx_new_window(vars()->mlx, WIN_WID, WIN_HEI, "Cub3D");
}
