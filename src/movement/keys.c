/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpereira <fpereira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 22:29:17 by nvideira          #+#    #+#             */
/*   Updated: 2023/10/17 17:02:40 by fpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

// void	test_key(int keycode)
// {
// 	if (keycode == D_KEY)
// 	{
// 		if (vars()->key->d)
// 			printf("D key pressed\n");
// 		else
// 			printf("D key released\n");
// 	}
// 	else if (keycode == A_KEY)
// 	{
// 		if (vars()->key->a)
// 			printf("A key pressed\n");
// 		else
// 			printf("A key released\n");
// 	}
// 	else if (keycode == W_KEY)
// 	{
// 		if (vars()->key->w)
// 			printf("W key pressed\n");
// 		else
// 			printf("W key released\n");
// 	}
// 	else if (keycode == S_KEY)
// 	{
// 		if (vars()->key->s)
// 			printf("S key pressed\n");
// 		else
// 			printf("S key released\n");
// 	}
// 	else if (keycode == LEFT_KEY)
// 	{
// 		if (vars()->key->left)
// 			printf("Left key pressed\n");
// 		else
// 			printf("Left key released\n");
// 	}
// 	else if (keycode == RIGHT_KEY)
// 	{
// 		if (vars()->key->right)
// 			printf("Right key pressed\n");
// 		else
// 			printf("Right key released\n");
// 	}
// }

int	key_press(int keycode)
{
	if (keycode == ESC_KEY)
		ft_close();
	else if (keycode == D_KEY)
		vars()->key->d = 1;
	else if (keycode == A_KEY)
		vars()->key->a = 1;
	else if (keycode == W_KEY)
		vars()->key->w = 1;
	else if (keycode == S_KEY)
		vars()->key->s = 1;
	else if (keycode == LEFT_KEY)
		vars()->key->left = 1;
	else if (keycode == RIGHT_KEY)
		vars()->key->right = 1;
	raycast_main(vars());
	return (0);
}

int	key_release(int keycode)
{
	if (keycode == D_KEY)
		vars()->key->d = 0;
	else if (keycode == A_KEY)
		vars()->key->a = 0;
	else if (keycode == W_KEY)
		vars()->key->w = 0;
	else if (keycode == S_KEY)
		vars()->key->s = 0;
	else if (keycode == LEFT_KEY)
		vars()->key->left = 0;
	else if (keycode == RIGHT_KEY)
		vars()->key->right = 0;
	return (0);
}

void	fps_count(void)
{
	vars()->chrono->old_time = vars()->chrono->time;
	vars()->chrono->time = clock();
	vars()->chrono->frame_time = (double)(vars()->chrono->time \
		- vars()->chrono->old_time) / CLOCKS_PER_SEC;
	vars()->chrono->move_speed = vars()->chrono->frame_time * 8000.0;
	vars()->chrono->rot_speed = vars()->chrono->frame_time * 5000.0;
}
