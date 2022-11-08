/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyokim <sooyokim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 15:09:34 by sooyokim          #+#    #+#             */
/*   Updated: 2022/11/08 18:58:43 by sooyokim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "utils.h"
#include "scene.h"
#include "keys.h"

t_object	*get_current_object(t_scene *scene)
{
	t_object	*res;
	size_t		cnt;

	cnt = 0;
	res = scene->world;
	while (cnt < scene->object_cnt)
	{
		res = res->next;
		cnt++;
	}
	return (res);
}

void	get_object_value(t_scene *scene, double *x, double *y, double *z)
{
	t_object	*obj;

	obj = get_current_object(scene);
	if (scene->object_mode == OBJECT_POSITION)
	{
		*x = obj->element->center.x;
		*y = obj->element->center.y;
		*z = obj->element->center.z;
	}
	else
	{
		*x = obj->element->dir.x;
		*y = obj->element->dir.y;
		*z = obj->element->dir.z;
	}
}

void	object_setting(t_scene *scene, double x, double y, double z)
{
	t_object	*obj;

	obj = get_current_object(scene);
	if (scene->object_mode == OBJECT_POSITION)
	{
		obj->element->center.x = x;
		obj->element->center.y = y;
		obj->element->center.z = z;
	}
	else
	{
		obj->element->dir.x = x;
		obj->element->dir.y = y;
		obj->element->dir.z = z;
	}
}

void	object_move(t_scene *scene, t_mlx *mlx, char option)
{	
	double		temp_x;
	double		temp_y;
	double		temp_z;
	double		offset;

	// printf("test : %f\n", scene->world->element->center.x);
	get_object_value(scene, &temp_x, &temp_y, &temp_z);
	offset = MOVE_OFFSET;
	if (option == 'u')
		temp_y += offset;
	if (option == 'd')
		temp_y -= offset;
	if (option == 'l')
		temp_x -= offset;
	if (option == 'r')
		temp_x += offset;
	if (option == 'q')
		temp_z -= offset;
	if (option == 'w')
		temp_z += offset;
	object_setting(scene, temp_x, temp_y, temp_z);
	render(mlx, scene);
}

void	object_control(int key, t_mlx *mlx)
{
	if (mlx->scene->object_mode == OBJECT_POSITION)
	{
		if (key == K_UP)
			object_move(mlx->scene, mlx, 'u');
		if (key == K_DOWN)
			object_move(mlx->scene, mlx, 'd');
		if (key == K_LEFT)
			object_move(mlx->scene, mlx, 'l');
		if (key == K_RIGHT)
			object_move(mlx->scene, mlx, 'r');
		if (key == K_Q)
			object_move(mlx->scene, mlx, 'q');
		if (key == K_W)
			object_move(mlx->scene, mlx, 'w');
	}
	else
		object_rotate(key, mlx);
}
