/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyokim <sooyokim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 11:29:06 by sooyokim          #+#    #+#             */
/*   Updated: 2022/11/08 14:29:24 by sooyokim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "keys.h"
#include <stdlib.h>
#include "mlx.h"

void	change_object_mode(t_scene *scene)
{
	if (!scene->object_mode)
		scene->object_mode = OBJECT_ROTATE;
	else
		scene->object_mode = OBJECT_POSITION;
}

void	change_mode(t_scene *scene)
{
	if (!scene->mode)
		scene->mode = OBJECT_MODE;
	else
		scene->mode = CAMERA_MODE;
}

void	camera_control(int key, t_mlx *mlx)
{	
	if (key == K_UP)
		camera_move(mlx->scene, mlx, 'u');
	if (key == K_DOWN)
		camera_move(mlx->scene, mlx, 'd');
	if (key == K_LEFT)
		camera_move(mlx->scene, mlx, 'l');
	if (key == K_RIGHT)
		camera_move(mlx->scene, mlx, 'r');
	if (key == K_Q)
		camera_move(mlx->scene, mlx, 'q');
	if (key == K_W)
		camera_move(mlx->scene, mlx, 'w');
}

void	object_control(int key, t_mlx *mlx)
{
	// if (key == K_UP)
	// 	object_move(mlx->scene, mlx, 'u');
	// if (key == K_DOWN)
	// 	object_move(mlx->scene, mlx, 'd');
	// if (key == K_LEFT)
	// 	object_move(mlx->scene, mlx, 'l');
	// if (key == K_RIGHT)
	// 	object_move(mlx->scene, mlx, 'r');
	// if (key == K_Q)
	// 	object_move(mlx->scene, mlx, 'q');
	// if (key == K_W)
	// 	object_move(mlx->scene, mlx, 'w');

	if (key == K_UP)
		camera_move(mlx->scene, mlx, 'u');
	if (key == K_DOWN)
		camera_move(mlx->scene, mlx, 'd');
	if (key == K_LEFT)
		camera_move(mlx->scene, mlx, 'l');
	if (key == K_RIGHT)
		camera_move(mlx->scene, mlx, 'r');
	if (key == K_Q)
		camera_move(mlx->scene, mlx, 'q');
	if (key == K_W)
		camera_move(mlx->scene, mlx, 'w');
}

int	hook_key(int key, t_mlx *mlx)
{
	if (key == K_ESC)
		terminate_minirt(mlx);
	if (mlx->scene->mode == CAMERA_MODE)
		camera_control(key, mlx);
	else
		object_control(key, mlx);
	if (key == K_G)
		change_object_mode(mlx->scene);
	if (key == K_T)
		change_mode(mlx->scene);
	return (0);
}
