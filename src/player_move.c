/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaharkat <yaharkat@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 02:24:29 by yaharkat          #+#    #+#             */
/*   Updated: 2025/01/03 02:50:51 by yaharkat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	handle_movement(t_mlx *mlx, double *new_x, double *new_y, int key)
{
	if (key == KEY_W)
	{
		*new_x += mlx->player->dir_x * MOVE_SPEED;
		*new_y += mlx->player->dir_y * MOVE_SPEED;
	}
	if (key == KEY_S)
	{
		*new_x -= mlx->player->dir_x * MOVE_SPEED;
		*new_y -= mlx->player->dir_y * MOVE_SPEED;
	}
	if (key == KEY_A)
	{
		*new_x -= mlx->player->dir_y * MOVE_SPEED;
		*new_y += mlx->player->dir_x * MOVE_SPEED;
	}
	if (key == KEY_D)
	{
		*new_x += mlx->player->dir_y * MOVE_SPEED;
		*new_y -= mlx->player->dir_x * MOVE_SPEED;
	}
}

void	move_player(t_mlx *mlx, int key)
{
	double	new_x;
	double	new_y;

	new_x = mlx->player->x;
	new_y = mlx->player->y;
	handle_movement(mlx, &new_x, &new_y, key);
	if (new_x >= 0 && new_x < mlx->map->width && new_y >= 0
		&& new_y < mlx->map->height
		&& mlx->map->map[(int)new_y][(int)new_x] != '1')
	{
		mlx->player->x = new_x;
		mlx->player->y = new_y;
	}
}

void	rotate_player(t_mlx *mlx, int direction)
{
	rotate_camera(mlx, ROT_SPEED * direction);
}

int	handle_keypress(int key, t_mlx *mlx)
{
	if (key == KEY_ESC)
		return (close_window(mlx));
	if (key == KEY_W || key == KEY_S || key == KEY_A || key == KEY_D)
		move_player(mlx, key);
	if (key == KEY_LEFT)
		rotate_player(mlx, 1);
	if (key == KEY_RIGHT)
		rotate_player(mlx, -1);
	return (0);
}