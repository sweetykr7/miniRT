/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinwoole <indibooks@naver.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 10:30:02 by sooyokim          #+#    #+#             */
/*   Updated: 2022/11/14 12:39:33 by jinwoole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"

t_point3	vqudplus(t_point3 o, t_vec3 a, t_vec3 b, t_vec3 c)
{
	t_point3	init;

	init.x = o.x + a.x + b.x + c.x;
	init.y = o.y + a.y + b.y + c.y;
	init.z = o.z + a.z + b.z + c.z;
	return (init);
}

t_camera	camera(t_canvas *canvas, t_point3 orig, int fov, t_vec3 vec)
{
	t_camera	cam;
	t_vec3		cross_val[2];
	t_vec3		half_vec[2];
	t_vec3		basis_vec;

	cam.focal_len = 1.0;
	cam.orig = orig;
	cam.fov = fov;
	cam.vec = vec;
	if (vec.x == 0 && vec.y == 1 && vec.z == 0)
		basis_vec = vec3(0, 0, 1);
	else if (vec.x == 0 && vec.y == -1 && vec.z == 0)
		basis_vec = vec3(0, 0, -1);
	else
		basis_vec = vec3(0, 1, 0);
	cam.viewport_w = tan((double)fov / 2 * M_PI / 180) * 2;
	cam.viewport_h = cam.viewport_w * canvas->height / canvas->width;
	cross_val[0] = vunit(vcross(vec, basis_vec));
	cam.horizontal = vmult(cross_val[0], cam.viewport_w);
	cross_val[1] = vunit(vcross(cam.horizontal, vec));
	cam.vertical = vmult(cross_val[1], cam.viewport_h);
	half_vec[0] = vdivide(cam.horizontal, -2);
	half_vec[1] = vdivide(cam.vertical, -2);
	cam.left_bottom = vqudplus(cam.orig, half_vec[0], half_vec[1], vec);
	return (cam);
}
