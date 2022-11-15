/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phong_lighting2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyokim <sooyokim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 19:33:29 by sooyokim          #+#    #+#             */
/*   Updated: 2022/11/15 20:26:04 by sooyokim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "trace.h"

t_vec3	reflect(t_vec3 v, t_vec3 n)
{
	return (vminus(vmult(n, vdot(v, n) * 2), v));
}

t_color3	specular_color(t_scene *scene, t_light *light, t_vec3 light_dir)
{
	t_vec3		view_dir;
	t_vec3		reflect_dir;
	double		spec;
	t_color3	specular;

	view_dir = vunit(vmult(scene->ray.dir, -1));
	reflect_dir = reflect(light_dir, scene->rec.normal);
	spec = pow(fmax(vdot(view_dir, reflect_dir), 0.0), KSN);
	specular = vmult(vmult(light->light_color, KS), spec);
	return (specular);
}

t_color3	diffuse_color(t_scene *scene, t_light *light, t_vec3 light_dir)
{
	t_color3	diffuse;
	double		kd;

	kd = fmax(vdot(scene->rec.normal, light_dir), 0.0);
	diffuse = vmult(light->light_color, kd);
	return (diffuse);
}
