/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyokim <sooyokim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 11:29:30 by sooyokim          #+#    #+#             */
/*   Updated: 2022/11/08 14:20:27 by sooyokim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "utils.h"
#include "scene.h"

t_point3	cam_left_bottom_reset(t_scene *scene)
{
	t_camera	cam;

	cam = scene->camera;
	return (vminus(vminus(vminus(cam.orig, vdivide(cam.horizontal, 2)), \
					vdivide(cam.vertical, 2)), vec3(0, 0, cam.focal_len)));
}

void	camera_move(t_scene *scene, t_mlx *mlx, char option)
{	
	double	temp_x;
	double	temp_y;
	double	temp_z;
	double	offset;

	temp_x = scene->camera.orig.x;
	temp_y = scene->camera.orig.y;
	temp_z = scene->camera.orig.z;
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
	scene->camera = camera(&scene->canvas, vec3(temp_x, temp_y, temp_z));
	render(mlx, scene);
}

void	object_move_setting(t_scene *scene, double *x, double *y, double *z)
{
	if (scene->object_mode == OBJECT_MODE)
	{
		
	}
}

void	object_move(t_scene *scene, t_mlx *mlx, char option)
{	
	double	temp_x;
	double	temp_y;
	double	temp_z;
	double	offset;

	temp_x = scene->camera.orig.x;
	temp_y = scene->camera.orig.y;
	temp_z = scene->camera.orig.z;
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
	scene->camera = camera(&scene->canvas, vec3(temp_x, temp_y, temp_z));
	render(mlx, scene);
}
