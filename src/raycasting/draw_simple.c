/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_simple.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleiria- <lleiria-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 10:42:35 by ubuntu            #+#    #+#             */
/*   Updated: 2023/09/28 17:28:44 by lleiria-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"


// unsigned int	tex_color(int i, int tex_x, int tex_y)
// {
// 	int				offset;
// 	char			*tex_pixel;
// 	unsigned int	color;
	
// 	if (i < 0 || i > 3)
// 		return (0);
// 	if (tex_x < 0 || tex_x > vars()->tex[i].wid || tex_y < 0 || tex_y >= vars()->tex[i].hei)
// 		return (0);
// // Calcular o deslocamento para o pixel na textura com base em 'tex_x' e 'tex_y'
// 	offset = (tex_y * vars()->tex[i].line_length) + (tex_x * (vars()->tex[i].bits_per_pixel / 8));
// 	tex_pixel = vars()->tex[i].addr + offset;
// 	color = *(unsigned int *)tex_pixel;
// 	return (color);
// }

// void draw_tex(int x, int side)
// {
// 	int	color;
// 	int	tex_x;
// 	int	tex_y;
// 	int	tex_index;

// 	tex_index = select_wall(side);

// 	int tex_x; // Coordenada de textura X
//     int tex_y; // Coordenada de textura Y
//     int color;

//     if (side == 0)
//         tex_x = (int)(vars()->tex[i].wid * (vars()->play->pos_y + vars()->play->perp_wall_dist * vars()->play->ray_d_y));
//     else
//         tex_x = (int)(vars()->tex[i].wid * (vars()->play->pos_x + vars()->play->perp_wall_dist * vars()->play->ray_d_x));
    
//     // Calcular a coordenada de textura Y (pode ser necessária uma escala)
//     tex_y = ... // Calcule a coordenada de textura Y com base na altura da parede
    
//     // Verificar limites de textura para evitar problemas de acesso inválido
//     if (tex_x < 0)
//         tex_x = 0;
//     if (tex_x >= vars()->tex[i].wid)
//         tex_x = vars()->tex[i].wid - 1;
//     if (tex_y < 0)
//         tex_y = 0;
//     if (tex_y >= vars()->tex[i].hei)
//         tex_y = vars()->tex[i].hei - 1;

//     // Obter a cor da textura usando as coordenadas de textura
//     color = tex_color(i, tex_x, tex_y);

//     // Preencher a coluna vertical com a cor da textura
//     int y = vars()->graph->draw_start;
//     while (y < vars()->graph->draw_end)
//     {
//         my_mlx_pixel_put(x, y, color);
//         y++;
//     }
// }

void	start_draw(int x, int side)
{
	int	color;

	color = DARK_RED;
	vars()->graph->line_height = (int)(WIN_HEI / vars()->play->perp_wall_dist);
	vars()->graph->draw_start = -vars()->graph->line_height / 2 + WIN_HEI / 2;
	if (vars()->graph->draw_start < 0)
		vars()->graph->draw_start = 0;
	vars()->graph->draw_end = vars()->graph->line_height / 2 + WIN_HEI / 2;
	if (vars()->graph->draw_end >= WIN_HEI)
		vars()->graph->draw_end = WIN_HEI - 1;
	if (side == 0)
		color /= 2;
	put_stripe(x, color);
}


void	put_stripe(int x, int color)
{
	int	y;

	y = vars()->graph->draw_start;
	while (y < vars()->graph->draw_end)
	{
		my_mlx_pixel_put(x, y, color);
		y++;
	}
}

void	my_mlx_pixel_put(int x, int y, int color)
{
	char	*dst;

	dst = vars()->img->addr + (y * vars()->img->line_length + x \
		* (vars()->img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}
