/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyokim <sooyokim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 11:29:30 by sooyokim          #+#    #+#             */
/*   Updated: 2022/11/09 11:35:19 by sooyokim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "utils.h"
#include "scene.h"

void	fov_control(t_scene *scene, char option)
{
	if (option == '+')
		scene->canvas.fov = scene->canvas.fov - FOV_GAP;
	if (option == '-')
		scene->canvas.fov = scene->canvas.fov + FOV_GAP;
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
	fov_control(scene, option);
	scene->camera = camera(&scene->canvas, vec3(temp_x, temp_y, temp_z));
	render(mlx, scene);
}
