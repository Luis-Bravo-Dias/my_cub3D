/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_tex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleiria- <lleiria-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 09:59:09 by lleiria-          #+#    #+#             */
/*   Updated: 2023/10/03 16:10:45 by lleiria-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	raycast_main(void)
{
	int	x;

	x = 0;
	lets_move(vars()->key->w - vars()->key->s, vars()->key->a - vars()->key->d);
	vars()->img->img = mlx_new_image(vars()->mlx, WIN_WID, WIN_HEI);
	vars()->img->addr = mlx_get_data_addr(vars()->img->img,	&vars()->img->bits_per_pixel, &vars()->img->line_length, &vars()->img->endian);
	while (x < WIN_WID)
	{
		raycast(x);
		x++;
	}
	
	mlx_put_image_to_window(vars()->mlx, vars()->window, vars()->img->img, 0,
		0);
	mlx_destroy_image(vars()->mlx, vars()->img->img);
	mlx_loop(vars()->mlx);
}

void	raycast(int x)
{
	int	hit;
	int	side;

	//posição da câmera em relação à coluna atual da tela
	vars()->play->cam_x = 2 * x / (double)WIN_WID - 1;
	//ray_d_x e ray_d_y calculam as direções dos raios lançados a partir da câmera
	vars()->play->ray_d_x = -vars()->play->dir_x - vars()->play->plane_x \
		* vars()->play->cam_x;
	vars()->play->ray_d_y = vars()->play->dir_y + vars()->play->plane_y \
		* vars()->play->cam_x;
	//map_x e map_y representam a posição do jogador no mapa do jogo.
	vars()->play->map_x = (int)vars()->play->pos_x;
	vars()->play->map_y = (int)vars()->play->pos_y;
	//As distâncias vars()->play->d_dist_x e vars()->play->d_dist_y são calculadas
	//para representar a distância entre as interseções dos raios com as paredes em cada eixo.
	if (vars()->play->ray_d_x == 0)
		vars()->play->d_dist_x = DBL_MAX;
	else
		vars()->play->d_dist_x = fabs(1 / vars()->play->ray_d_x);
	if (vars()->play->ray_d_y == 0)
		vars()->play->d_dist_y = DBL_MAX;
	else
		vars()->play->d_dist_y = fabs(1 / vars()->play->ray_d_y);
	hit = 0;
	//As próximas seções do código calculam a direção e o passo do raio, bem como
	//as distâncias até a próxima interseção em ambos os eixos
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
	//O loop while é usado para seguir o raio até que ele atinja uma parede (hit == 1). Durante cada iteração,
	//verifica-se se a próxima interseção ocorre no eixo X ou Y e atualiza as coordenadas de acordo.
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
	//o raio atinge uma parede, a distância perpendicular até a parede (vars()->play->perp_wall_dist)
	//é calculada com base na fórmula de distância perpendicular.
	if (side == 0)
		vars()->play->perp_wall_dist = (vars()->play->map_x \
			- vars()->play->pos_x + (1 - vars()->play->step_x) / 2) \
			/ vars()->play->ray_d_x;
	else
		vars()->play->perp_wall_dist = (vars()->play->map_y \
			- vars()->play->pos_y + (1 - vars()->play->step_y) / 2) \
			/ vars()->play->ray_d_y;
	fps_count();
	start_draw(x, side);
}