/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raghonya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 17:42:47 by raghonya          #+#    #+#             */
/*   Updated: 2023/02/25 17:42:49 by raghonya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	close_window(t_mlx *mlx)
{
	(void)mlx;
	exit(0);
}

int	close_map(int key, t_mlx *mlx)
{
	static int	count;
	char		*s;

	if (key == 53)
	{
		mlx_destroy_window(mlx->mlx, mlx->win);
		exit(0);
	}
	else if (key == 119)
		to_up(mlx, &count);
	else if (key == 100)
		to_right(mlx, &count);
	else if (key == 115)
		to_down(mlx, &count);
	else if (key == 97)
		to_left(mlx, &count);
	ft_printf ("%d\n", key);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->w.icon, 0, 0);
	s = ft_itoa(count);
	mlx_string_put(mlx->mlx, mlx->win, 0, 10, 0x00FF0000, s);
	free(s);
	return (0);
}

int	main(int argc, char **argv)
{
	t_mlx		mlx;

	universal_func(argc == 1, "No map, please add *.ber file in arguments\n");
	universal_func(argc > 2, "Many arguments, please stop it!!!\n");
	mlx.map = map_check(argv[1], &(mlx.count));
	create_map(&mlx);
	mlx_string_put(mlx.mlx, mlx.win, 0, 10, 0x00FF0000, "0");
	mlx_hook(mlx.win, 2, 1L<<0, &close_map, &mlx);
	mlx_hook(mlx.win, 17, 0, &close_window, &mlx);
	mlx_loop(mlx.mlx);
	return (0);
}
