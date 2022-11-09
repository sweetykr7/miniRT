/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyokim <sooyokim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 12:05:04 by sooyokim          #+#    #+#             */
/*   Updated: 2022/11/09 12:06:11 by sooyokim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TRACE_H
# define TRACE_H

# include "structures.h"
# include "utils.h"

t_ray		ray(t_point3 orig, t_vec3 dir);
t_point3	ray_at(t_ray *ray, double t);
t_color3	ray_color(t_scene *scene);

t_bool		hit(t_object *obj, t_ray *ray, t_hit_record *rec);
t_bool		hit_obj(t_object *obj, t_ray *ray, t_hit_record *rec);
t_bool		hit_sphere(t_object *world, t_ray *ray, t_hit_record *rec);
t_bool		hit_cylinder(t_object *cy_obj, t_ray *ray, t_hit_record *rec);

t_ray		ray_primary(t_camera *cam, double u, double v);

t_bool		hit_sphere(t_object *world, t_ray *ray, t_hit_record *rec);
t_bool		hit_plane(t_object *pl_obj, t_ray *ray, t_hit_record *rec);
int			hit_cylinder_side(t_object *cy_obj, t_ray *ray, t_hit_record *rec);
void		set_face_normal(t_ray *r, t_hit_record *rec);

t_light		*light_point(t_point3 light_origin, t_color3 light_color, \
														double bright_ratio);
t_color3	phong_lighting(t_scene *scene);
t_color3	point_light_get(t_scene *scene, t_light *light);
t_bool		in_shadow(t_object *objs, t_ray light_ray, double light_len);

#endif