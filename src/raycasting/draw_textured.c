/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_textured.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvideira <nvideira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 17:31:18 by ubuntu            #+#    #+#             */
/*   Updated: 2023/05/23 00:07:26 by nvideira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	load_imgs(void)
{
	vars()->n_img.img = mlx_xpm_file_to_image(vars()->mlx,
		vars()->no,	&vars()->n_img.wid, &vars()->n_img.hei);
	vars()->n_img.addr = mlx_get_data_addr(vars()->n_img.img,
		&vars()->n_img.bits_per_pixel, &vars()->n_img.line_length,
		&vars()->n_img.endian);
	vars()->w_img.img = mlx_xpm_file_to_image(vars()->mlx,
		vars()->we,	&vars()->w_img.wid, &vars()->w_img.hei);
	vars()->w_img.addr = mlx_get_data_addr(vars()->w_img.img,
		&vars()->w_img.bits_per_pixel, &vars()->w_img.line_length,
		&vars()->w_img.endian);
	vars()->e_img.img = mlx_xpm_file_to_image(vars()->mlx,
		vars()->ea,	&vars()->e_img.wid, &vars()->e_img.hei);
	vars()->e_img.addr = mlx_get_data_addr(vars()->e_img.img,
		&vars()->e_img.bits_per_pixel, &vars()->e_img.line_length,
		&vars()->e_img.endian);
	vars()->s_img.img = mlx_xpm_file_to_image(vars()->mlx,
		vars()->so,	&vars()->s_img.wid, &vars()->s_img.hei);
	vars()->s_img.addr = mlx_get_data_addr(vars()->s_img.img,
		&vars()->s_img.bits_per_pixel, &vars()->s_img.line_length,
		&vars()->s_img.endian);
}

void	draw_tex(int side)
{
    double	wall_x;
	int		tex_x;
	double	tex_pos;
	int 	y;
	int		tex_y;

	if (side == 0)
		wall_x = vars()->play->pos_y + vars()->play->perp_wall_dist * vars()->play->ray_d_y;
	else
    	wall_x = vars()->play->pos_x + vars()->play->perp_wall_dist * vars()->play->ray_d_x;
	wall_x -= floor(wall_x); 

	tex_x = (int)(wall_x * double(TEX_RES));
	if(side == 0 && vars()->play->ray_d_x > 0)
		tex_x = TEX_RES - tex_x - 1;
	if(side == 1 && vars()->play->ray_d_y < 0)
		tex_x = TEX_RES - tex_x - 1;
	y = vars()->graph->draw_start;
	vars()->play->step = 1.0 * TEX_RES / vars()->play->line_height;
	tex_pos = (vars()->graph->draw_start - WIN_HEI / 2 + vars()->play->line_height / 2) * vars()->play->step;
	while (y < vars()->graph->draw_end)
	{
		tex_y = (int)tex_pos & (TEX_RES - 1);
		tex_pos += vars()->play->step;
		//Uint32 color = texture[texNum][texHeight * texY + texX]; --> nao aplicavel ao nosso programa
		////make color darker for y-sides: R, G and B byte each divided through two with a "shift" and an "and"
		//if(side == 1) color = (color >> 1) & 8355711;
		//buffer[y][x] = color;
		y++;
	}
}



/*

draw_wall do lucas    |
                      V
void	draw_wall(t_rloop *tudao, t_draw *draw, t_all *all, int y)
{
	draw->tex_y = (int)draw->texpos & (all->tex[tudao->side].img_height - 1);
	draw->texpos += draw->step;
	draw->color = *(get_img_pixel(&(all->tex[tudao->side]), \
	draw->tex_x, draw->texpos));
	if (tudao->side == NO || tudao->side == SO)
		draw->color = mlx_get_color_value(all->mlx.mlx,
				(int)((draw->color & 0x0000FF) * 0.70)
				| (int)(((draw->color >> 8) & 0x0000FF) * 0.70) << 8
				| (int)((draw->color >> 16) * 0.70) << 16);
	my_mlx_pixel_put(&(all->mlx.img), SCREENW - draw->x - 1, y, draw->color);
}
*/
