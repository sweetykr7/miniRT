/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phong_lighting.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinwoole <indibooks@naver.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 10:37:15 by sooyokim          #+#    #+#             */
/*   Updated: 2022/11/14 12:25:01 by jinwoole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "trace.h"

t_bool	in_shadow(t_object *objs, t_ray light_ray, double light_len)
{
	t_hit_record	rec;

	rec.tmin = 0;
	rec.tmax = light_len;
	if (hit(objs, &light_ray, &rec))
		return (TRUE);
	return (FALSE);
}

t_color3	point_light_get(t_scene *scene, t_light *light)
{
	t_color3	diffuse;
	t_vec3		light_dir;
	t_color3	specular;
	double		brightness;
	t_ray		light_ray;

	light_dir = vminus(light->origin, scene->rec.p);
	light_ray = ray(vplus(scene->rec.p, vmult(scene->rec.normal, EPSILON)), \
																light_dir);
	if (in_shadow(scene->world, light_ray, vlength(light_dir)))
		return (color3(0, 0, 0));
	light_dir = vunit(light_dir);
	diffuse = diffuse_color(scene, light, light_dir);
	specular = specular_color(scene, light, light_dir);
	brightness = light->bright_ratio * LUMEN;
	return (vmult(vplus(vplus(scene->ambient, diffuse), specular), brightness));
}

t_color3	phong_lighting(t_scene *scene)
{
	t_color3		light_color;
	t_object_light	*lights;

	light_color = color3(0, 0, 0);
	lights = scene->light;
	while (lights)
	{
		if (lights->type == LIGHT_POINT)
			light_color = vplus(light_color, point_light_get(scene, \
													lights->element));
		lights = lights->next;
	}
	light_color = vplus(light_color, scene->ambient);
	return (vmin(vmult_(light_color, scene->rec.albedo), \
								color3(255, 255, 255)));
}
