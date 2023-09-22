/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleiria- <lleiria-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 17:12:18 by ubuntu            #+#    #+#             */
/*   Updated: 2023/07/13 16:08:15 by lleiria-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

t_input	*vars(void)
{
	static t_input	vars;

	return (&vars);
}

void	liberate(void)
{
	free_array(vars()->no);
	free_array(vars()->so);
	free_array(vars()->we);
	free_array(vars()->ea);
	free_array(vars()->f);
	free_array(vars()->c);
	free_matrix(vars()->map);
}

int	main(int ac, char **av)
{
	if (ac != 2)
		printf("\e[1;91mError\nwrong number of arguments\n\e[0m");
	if (sort_data(av[1]) || check_map())
	{
		liberate();
		return (1);
	}
	init_cub();
	mlx_hook(vars()->window, 17, 0, ft_close, NULL);
	mlx_hook(vars()->window, 2, 1L << 0, key_press, NULL);
	mlx_hook(vars()->window, 3, 1L << 1, key_release, NULL);
	raycast_main();
	liberate();
	return (0);
}
