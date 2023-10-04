/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wasd.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpereira <fpereira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 12:40:43 by ubuntu            #+#    #+#             */
/*   Updated: 2023/10/04 15:37:28 by fpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	move_play(void)
{
	vars()->play->pos_x += ((-vars()->play->dir_x * vars()->key->w) \
			+ (vars()->play->dir_y * vars()->key->a) - (-vars()->play->dir_x * vars()->key->s) \
			- (vars()->play->dir_y * vars()->key->d)) / (16 * 2);
	vars()->play->pos_y += ((vars()->play->dir_y * vars()->key->w) \
			+ (vars()->play->dir_x * vars()->key->a) - (vars()->play->dir_y * vars()->key->s) \
			- (vars()->play->dir_x * vars()->key->d))  / (16 * 2);
}

void	horizontal_rot(t_player *p, double angle)
{
	double	old_dir;
	double	old_plane;

	if (angle == 0)
		return ;
	// p->angle += angle;
	// if (p->angle < 0)
	// 	p->angle = 2 * PI + p->angle;
	// else if (p->angle > 2 * PI)
	// 	p->angle -= 2 * PI;
	old_dir = p->dir_x;
	old_plane = p->plane_x;
	p->dir_x = p->dir_x * cos(angle) - p->dir_y * sin(angle);
	p->dir_y = old_dir * sin(angle) + p->dir_y * cos(angle);
	p->plane_x = p->plane_x * cos(angle) - p->plane_y * sin(angle);
	p->plane_y = old_plane * sin(angle) + p->plane_y * cos(angle);
}

/*void	move_play(double new_dir_x, double new_dir_y)
{
	if (vars()->map[(int)(vars()->play->pos_y)][(int)(vars()->play->pos_x + new_dir_x
 			* vars()->chrono->move_speed)] == '0')
		vars()->play->pos_x += new_dir_x * vars()->chrono->move_speed;
	if (vars()->map[(int)(vars()->play->pos_y + new_dir_y * vars()->chrono->move_speed)][(int)(vars()->play->pos_x)] == '0')
		vars()->play->pos_y += new_dir_y * vars()->chrono->move_speed;
}

// w - s , a - d
// M_PI = 180
// M_PI_2 = 90
// M_PI_4 = 45	
double	find_angle(int ws, int ad)
{
	double angle;
	
	if (ws == 1 && ad == 0)
		angle = 0;
	else if (ws == -1 && ad == 0)
		angle = M_PI;
	else if (ws == 0 && ad == 1)
		angle = -M_PI_2;
	else if (ws == 0 && ad == -1)
		angle = M_PI_2;
	else if (ws == 1 && ad == 1)
		angle = -M_PI_4;
	else if (ws == 1 && ad == -1)
		angle = M_PI_4;
	else if (ws == -1 && ad == 1)
		angle = -M_PI_2 - M_PI_4;
	else //if (ws == -1 && ad == -1)
		angle = M_PI_2 + M_PI_4;
	return (angle);
}

void 	lets_move(int ws, int ad)
{
	double	angle;
	double	new_dir_x;
	double	new_dir_y;
	
	if (ws || ad)
	{
		angle = find_angle(ws, ad);
		new_dir_x = vars()->play->dir_x * cos(angle) - vars()->play->dir_y * sin(angle);
		new_dir_y = vars()->play->dir_x * sin(angle) + vars()->play->dir_y * cos(angle);
		move_play(new_dir_x, new_dir_y);
	}
	
}*/

// void	move_fwd(void)
// {
// 	vars()->key->w = 1;
// 	if (vars()->map[(int)((vars()->play->pos_y))] \
// 			[(int)(vars()->play->pos_x - vars()->play->dir_x \
// 			* vars()->chrono->move_speed)] == '0')
// 		vars()->play->pos_x -= vars()->play->dir_x * vars()->chrono->move_speed;
// 	if (vars()->map[(int)(vars()->play->pos_y + vars()->play->dir_y \
// 			* vars()->chrono->move_speed)][(int)(vars()->play->pos_x)] == '0')
// 		vars()->play->pos_y += vars()->play->dir_y * vars()->chrono->move_speed;
// }

// void	move_bwd(void)
// {
// 	vars()->key->s = 1;
// 	if (vars()->map[(int)((vars()->play->pos_y))] \
// 			[(int)((vars()->play->pos_x + vars()->play->dir_x \
// 			* vars()->chrono->move_speed))] == '0')
// 		vars()->play->pos_x += vars()->play->dir_x * vars()->chrono->move_speed;
// 	if (vars()->map[(int)(vars()->play->pos_y - vars()->play->dir_y \
// 			* vars()->chrono->move_speed)][(int)(vars()->play->pos_x)] == '0')
// 		vars()->play->pos_y -= vars()->play->dir_y * vars()->chrono->move_speed;
// }

// void	move_lsw(void)
// {
// 	vars()->key->a = 1;
// 	if (vars()->map[(int)((vars()->play->pos_y))] \
// 			[(int)((vars()->play->pos_x + vars()->play->plane_x \
// 			* vars()->chrono->move_speed))] == '0')
// 		vars()->play->pos_x += vars()->play->plane_x \
// 			* vars()->chrono->move_speed;
// 	if (vars()->map[(int)(vars()->play->pos_y - vars()->play->plane_y \
// 			* vars()->chrono->move_speed)][(int)(vars()->play->pos_x)] == '0')
// 		vars()->play->pos_y -= vars()->play->plane_y \
// 			* vars()->chrono->move_speed;
// }

// void	move_rsw(void)
// {
// 	vars()->key->d = 1;
// 	if (vars()->map[(int)((vars()->play->pos_y))] \
// 			[(int)((vars()->play->pos_x - vars()->play->plane_x \
// 			* vars()->chrono->move_speed))] == '0')
// 		vars()->play->pos_x -= vars()->play->plane_x \
// 			* vars()->chrono->move_speed;
// 	if (vars()->map[(int)(vars()->play->pos_y + vars()->play->plane_y \
// 			* vars()->chrono->move_speed)][(int)(vars()->play->pos_x)] == '0')
// 		vars()->play->pos_y += vars()->play->plane_y \
// 			* vars()->chrono->move_speed;
// }
