/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinwoole <indibooks@naver.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 10:30:02 by sooyokim          #+#    #+#             */
/*   Updated: 2022/11/13 14:34:26 by jinwoole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"

t_camera	camera(t_canvas *canvas, t_point3 orig, int fov)
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
}
