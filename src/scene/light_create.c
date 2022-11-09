/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_create.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinwoole <indibooks@naver.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 12:22:31 by sooyokim          #+#    #+#             */
/*   Updated: 2022/11/09 16:09:47 by jinwoole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"

t_object_light	*object_light(t_object_type type, t_light *element, \
														t_color3 albedo)
{
	t_object_light	*new;

	new = (t_object_light *)malloc(sizeof(t_object_light));
	if (!new)
		return (NULL);
	new->type = type;
	new->element = element;
	new->next = NULL;
	new->albedo = albedo;
	return (new);
}

t_light	*light_point(t_point3 light_origin, t_color3 light_color, \
													double bright_ratio)
{
	t_light	*light;

	light = (t_light *)malloc(sizeof(t_light));
	if (!light)
		return (NULL);
	light->origin = light_origin;
	light->light_color = light_color;
	light->bright_ratio = bright_ratio;
	return (light);
}
