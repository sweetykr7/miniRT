/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyokim <sooyokim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 14:45:48 by sooyokim          #+#    #+#             */
/*   Updated: 2022/11/09 10:38:46 by sooyokim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENE_H
# define SCENE_H

# include "structures.h"
# include "utils.h"

t_canvas		canvas(int width, int height, double fov);
t_camera		camera(t_canvas *canvas, t_point3 origin);

t_object		*object(t_object_type type, t_object_value *element, \
														t_color3 albedo);
t_object_light	*object_light(t_object_type type, t_light *element, t_color3 albedo);
t_object_value	*sphere(t_point3 center, double radius);
t_object_value	*splane(t_point3 center, t_vec3 dir);
t_object_value	*scylinder(t_point3 center, t_vec3 dir, \
										double diameter, double height);

#endif