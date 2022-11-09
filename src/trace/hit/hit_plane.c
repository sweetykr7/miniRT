/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_plane.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyokim <sooyokim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 09:43:32 by sooyokim          #+#    #+#             */
/*   Updated: 2022/11/09 13:50:20 by sooyokim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structures.h"
#include "utils.h"
#include "trace.h"

t_bool	hit_plane(t_object *pl_obj, t_ray *ray, t_hit_record *rec)
{
	t_object_value	*pl;
	double			root;
	double			denominator;
	double 			numrator; // float쓸지 double 쓸지 파악 필요, 원래 float였음

	pl = pl_obj->element;
	denominator = vdot(ray->dir, pl->dir);
	if (fabs(denominator) < EPSILON) // 분모의 값이 0보다 작거나 같을 경우 충돌하지 않는다.
		return (FALSE);
	numrator = vdot(vminus(pl->center, ray->orig), pl->dir);
	root = numrator / denominator;
	if (root < rec->tmin || rec->tmax < root)
		return (FALSE);
	rec->t = root;
	rec->p = ray_at(ray, root);
	rec->normal = pl->dir;
	// set_face_normal(ray, rec); //필요한지 확인 필요함, 앞면인지 뒷면인지 확인하는 것임
	rec->albedo = pl_obj->albedo;
	return (TRUE);
}
