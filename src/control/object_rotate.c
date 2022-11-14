/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_rotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinwoole <indibooks@naver.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 17:21:42 by sooyokim          #+#    #+#             */
/*   Updated: 2022/11/14 11:56:03 by jinwoole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "utils.h"
#include "scene.h"
#include "keys.h"

void	rotate_z(int angle, t_mlx *mlx)
{
	t_object	*obj;
	double		x1;
	double		y1;
	double		rad;

	obj = get_current_object(mlx->scene);
	x1 = obj->element->dir.x;
	y1 = obj->element->dir.y;
	rad = (angle * 3.1415926) / 180;
	obj->element->dir.x = x1 * cos(rad) - y1 * sin(rad);
	obj->element->dir.y = x1 * sin(rad) + y1 * cos(rad);
	render(mlx, mlx->scene);
}

void	rotate_y(int angle, t_mlx *mlx)
{
	t_object	*obj;
	double		x1;
	double		z1;
	double		rad;

	obj = get_current_object(mlx->scene);
	x1 = obj->element->dir.x;
	z1 = obj->element->dir.z;
	rad = (angle * 3.1415926) / 180;
	obj->element->dir.x = z1 * sin(rad) + x1 * cos(rad);
	obj->element->dir.z = z1 * cos(rad) - x1 * sin(rad);
	render(mlx, mlx->scene);
}

void	rotate_x(int angle, t_mlx *mlx)
{
	t_object	*obj;
	double		y1;
	double		z1;
	double		rad;

	obj = get_current_object(mlx->scene);
	y1 = obj->element->dir.y;
	z1 = obj->element->dir.z;
	rad = (angle * 3.1415926) / 180;
	obj->element->dir.y = y1 * cos(rad) - z1 * sin(rad);
	obj->element->dir.z = y1 * sin(rad) + z1 * cos(rad);
	render(mlx, mlx->scene);
}

void	object_rotate(int key, t_mlx *mlx)
{	
	if (key == K_UP)
		rotate_y(ROTATE_ANGLE, mlx);
	if (key == K_DOWN)
		rotate_y(-1 * ROTATE_ANGLE, mlx);
	if (key == K_LEFT)
		rotate_x(-1 * ROTATE_ANGLE, mlx);
	if (key == K_RIGHT)
		rotate_x(ROTATE_ANGLE, mlx);
	if (key == K_Q)
		rotate_z(-1 * ROTATE_ANGLE, mlx);
	if (key == K_W)
		rotate_z(ROTATE_ANGLE, mlx);
}
