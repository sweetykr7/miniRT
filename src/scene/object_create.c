#include "scene.h"

t_object    *object(t_object_type type, t_object_value *element, t_color3 albedo)
{
    t_object    *new;

    if (!(new = (t_object *)malloc(sizeof(t_object))))
        return (NULL);
    new->type = type;
    new->element = element;
    new->next = NULL;
    new->albedo = albedo;
    return (new);
}

t_object_light    *object_light(t_object_type type, t_light *element, t_color3 albedo)
{
    t_object_light    *new;

    if (!(new = (t_object_light *)malloc(sizeof(t_object_light))))
        return (NULL);
    new->type = type;
    new->element = element;
    new->next = NULL;
    new->albedo = albedo;
    return (new);
}

t_object_value	*sphere(t_point3 center, double radius)
{
	t_object_value	*sp;

	sp = (t_object_value *)malloc(sizeof(t_object_value));
	if (!sp)
		return (NULL);
	sp->center = center;
	sp->radius = radius;
	sp->radius2 = radius * radius;
	return (sp);
}

t_object_value	*splane(t_point3 center, t_vec3 dir)
{
	t_object_value	*pl;

	pl = (t_object_value *)malloc(sizeof(t_object_value));
	if (!pl)
		return (NULL);
	pl->center = center;
	pl->dir = dir;
	return (pl);
}


t_object_value	*scylinder(t_point3 center, t_vec3 dir, double diameter, double height)
{
	t_object_value	*cy;

	cy = (t_object_value *)malloc(sizeof(t_object_value));
	if (!cy)
		return (NULL);
	cy->center = center;
	cy->dir = dir;
	cy->diameter = diameter;
	cy->height = height;
	return (cy);
}

t_light     *light_point(t_point3 light_origin, t_color3 light_color, double bright_ratio)
{
    t_light *light;

    if(!(light = (t_light *)malloc(sizeof(t_light))))
        return (NULL);
    light->origin = light_origin;
    light->light_color = light_color;
    light->bright_ratio = bright_ratio;
    return (light);
}