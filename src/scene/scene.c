/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinwoole <indibooks@naver.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 10:30:02 by sooyokim          #+#    #+#             */
/*   Updated: 2022/11/13 15:49:28 by jinwoole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"

t_vec3	vec_once_add_point(t_point3 o, t_vec3 a, \
								t_vec3 b, t_vec3 c)
{
	t_vec3	init;

	init.x = o.x + a.x + b.x + c.x;
	init.y = o.y + a.y + b.y + c.y;
	init.z = o.z + a.z + b.z + c.z;
	return (init);
}


t_camera	camera(t_canvas *canvas, t_point3 orig, int fov, t_vec3 vec)
{
	t_camera	cam;
	t_vec3	cross_val[2];
	t_vec3	half_vec[2];
	t_vec3	basis_vec;

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

	cam.viewport_w = tan((double)fov / 2 * M_PI / 180) * 2; //여긴 mlx를 위한 공간이다.
	//원래는 2로 치고 했다.
	cam.viewport_h = cam.viewport_w * canvas->height / canvas->width;


	cross_val[0] = vunit(vcross(vec, basis_vec)); //x축 단위벡터
	cam.horizontal = vmult(cross_val[0], cam.viewport_w);
	cross_val[1] = vunit(vcross(cam.horizontal, vec)); //y축 단위벡터
	cam.vertical = vmult(cross_val[1], cam.viewport_h);
	half_vec[0] = vdivide(cam.horizontal, -2);
	half_vec[1] = vdivide(cam.vertical, -2);
	
	cam.left_bottom = vec_once_add_point(cam.orig, half_vec[0], half_vec[1], vec);

//	cam.horizontal = vec3(cam.viewport_w, 0, 0);
//	cam.vertical = vec3(0, cam.viewport_h, 0);
//	cam.left_bottom = vminus(vminus(vminus(cam.orig, vdivide(cam.horizontal, \
//						2)), vdivide(cam.vertical, 2)), vec3(0, 0, cam.focal_len));
	return (cam);
}



/*t_camera	camera(t_canvas *canvas, t_point3 orig, int fov)
{
	t_camera	cam;

	cam.focal_len = 1.0;
	cam.orig = orig;
	cam.fov = fov;

	cam.viewport_w = tan((double)fov / 2 * M_PI / 180) * 2; //여긴 mlx를 위한 공간이다.
	//원래는 2로 치고 했다.
	cam.viewport_h = cam.viewport_w * canvas->height / canvas->width;

	cam.horizontal = vec3(cam.viewport_w, 0, 0);
	cam.vertical = vec3(0, cam.viewport_h, 0);
	cam.left_bottom = vminus(vminus(vminus(cam.orig, vdivide(cam.horizontal, \
						2)), vdivide(cam.vertical, 2)), vec3(0, 0, cam.focal_len));
	return (cam);
}*/
