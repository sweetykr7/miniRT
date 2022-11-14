/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_create.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinwoole <indibooks@naver.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 12:17:05 by sooyokim          #+#    #+#             */
/*   Updated: 2022/11/14 13:03:34 by jinwoole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"

t_object	*object(t_object_type type, t_object_value *element, \
													t_color3 albedo)
{
	t_object	*new;

	new = (t_object *)malloc(sizeof(t_object));
	if (!new)
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

t_object_value	*scylinder(t_point3 center, t_vec3 dir, double diameter, \
															double height)
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
