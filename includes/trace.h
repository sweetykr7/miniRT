#ifndef TRACE_H
# define TRACE_H
// trace/ray/

# include "structures.h"
# include "utils.h"

t_ray       ray(t_point3 orig, t_vec3 dir);
t_point3    ray_at(t_ray *ray, double t);
/* * * * 추가 * * * */
t_color3    ray_color(t_scene *scene);
// t_color3    ray_color(t_ray *ray, t_object *world);


// trace/hit/
t_bool      hit(t_object *obj, t_ray *ray, t_hit_record *rec);
t_bool      hit_obj(t_object *obj, t_ray *ray, t_hit_record *rec);
t_bool      hit_sphere(t_object *world, t_ray *ray, t_hit_record *rec);
t_bool      hit_cylinder(t_object *cy_obj, t_ray *ray, t_hit_record *rec);


/* * * * 추가 끝 * * * */
t_ray       ray_primary(t_camera *cam, double u, double v);
// t_color3    ray_color(t_ray *ray, t_sphere *sphere);

// trace/hit/
t_bool		hit_sphere(t_object *world, t_ray *ray, t_hit_record *rec);
t_bool		hit_plane(t_object *pl_obj, t_ray *ray, t_hit_record *rec);
void		set_face_normal(t_ray *r, t_hit_record *rec);

t_light		*light_point(t_point3 light_origin, t_color3 light_color, double bright_ratio);

t_color3	phong_lighting(t_scene *scene);
t_color3	point_light_get(t_scene *scene, t_light *light);
t_bool		in_shadow(t_object *objs, t_ray light_ray, double light_len);

int			hit_cylinder_side(t_object *cy_obj, t_ray *ray, t_hit_record *rec);

#endif