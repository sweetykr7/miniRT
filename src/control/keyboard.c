/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyokim <sooyokim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 11:29:06 by sooyokim          #+#    #+#             */
/*   Updated: 2022/11/08 19:02:42 by sooyokim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "keys.h"
#include <stdlib.h>
#include "mlx.h"
#include "libft.h"

void	change_object_mode(t_scene *scene)
{
	if (!scene->object_mode)
	{
		scene->object_mode = OBJECT_ROTATE;
		ft_putstr("change to [OBJECT ROTATE MODE]\n");
	}
	else
	{
		scene->object_mode = OBJECT_POSITION;
		ft_putstr("change to [OBJECT POSITION MODE]\n");
	}
}

void	change_object(int key, t_scene *scene)
{
	if (key == K_R)
	{
		ft_putstr("change to next [OBJECT]\n");
		if (scene->object_cnt < scene->total_obj_cnt - 1)
			scene->object_cnt++;
		else
			scene->object_cnt = 0;
	}
	else if (key == K_E)
	{
		ft_putstr("change to previous [OBJECT]\n");
		if (scene->object_cnt == 0)
			scene->object_cnt = scene->total_obj_cnt - 1;
		else
			scene->object_cnt--;
	}
}

void	change_mode(t_scene *scene)
{
	if (!scene->mode)
	{
		scene->mode = OBJECT_MODE;
		ft_putstr("change to [OBJECT MODE]\n");
	}
	else
	{
		scene->mode = CAMERA_MODE;
		ft_putstr("change to [CAMERA MODE]\n");
	}
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

int	hook_key(int key, t_mlx *mlx)
{
	if (key == K_ESC)
		terminate_minirt(mlx);
	if (mlx->scene->mode == CAMERA_MODE)
		camera_control(key, mlx);
	else
	{
		if (key == K_G)
			change_object_mode(mlx->scene);
		else if (key == K_E || key == K_R)
			change_object(key, mlx->scene);
		else
			object_control(key, mlx);
	}
	if (key == K_T)
		change_mode(mlx->scene);
	return (0);
}
