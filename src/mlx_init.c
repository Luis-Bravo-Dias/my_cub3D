/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleiria- <lleiria-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 16:20:29 by fpereira          #+#    #+#             */
/*   Updated: 2023/10/13 14:44:22 by lleiria-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	init_tex(void)
{
	int	i;

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

void	load_tex(t_input *vars)
{
	init_tex();
	vars->tex[0].img = mlx_xpm_file_to_image(vars->mlx, \
		vars->no, &vars->tex[0].wid, &vars->tex[0].hei);
	vars->tex[0].addr = mlx_get_data_addr(vars->tex[0].img, \
		&vars->tex[0].bits_per_pixel, &vars->tex[0].line_length, \
		&vars->tex[0].endian);
	vars->tex[1].img = mlx_xpm_file_to_image(vars->mlx, \
		vars->so, &vars->tex[1].wid, &vars->tex[1].hei);
	vars->tex[1].addr = mlx_get_data_addr(vars->tex[1].img, \
		&vars->tex[1].bits_per_pixel, &vars->tex[1].line_length, \
		&vars->tex[1].endian);
	vars->tex[2].img = mlx_xpm_file_to_image(vars->mlx, \
		vars->we, &vars->tex[2].wid, &vars->tex[2].hei);
	vars->tex[2].addr = mlx_get_data_addr(vars->tex[2].img, \
		&vars->tex[2].bits_per_pixel, &vars->tex[2].line_length, \
		&vars->tex[2].endian);
	vars->tex[3].img = mlx_xpm_file_to_image(vars->mlx, \
		vars->ea, &vars->tex[3].wid, &vars->tex[3].hei);
	vars->tex[3].addr = mlx_get_data_addr(vars->tex[3].img, \
		&vars->tex[3].bits_per_pixel, &vars->tex[3].line_length, \
		&vars->tex[3].endian);
}

void	init_cub(void)
{
	void	*window;

	init_vars();
	init_keys();
	vars()->img = (t_img *)malloc(sizeof(t_img));
	vars()->mlx = mlx_init();
	load_tex(vars());
	window = mlx_new_window(vars()->mlx, WIN_WID, WIN_HEI, "Cub3D");
	vars()->window = window;
}
