/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_sphere.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyokim <sooyokim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 14:56:45 by sooyokim          #+#    #+#             */
/*   Updated: 2022/11/10 11:00:47 by sooyokim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structures.h"
#include "utils.h"
#include "trace.h"

double	sp_discriminant(t_object *sp_obj, t_ray *ray, double *half_b, double *a)
{
	t_object_value	*sp;
	double			c;
	double			r;
	double			discriminant;
	t_vec3			delta_p;

	sp = sp_obj->element;
	*a = vlength2(ray->dir);
	*half_b = vdot(vminus(ray->orig, sp->center), ray->dir);
	c = vlength2(vminus(ray->orig, sp->center)) - sp_obj->element->radius2;
	discriminant = (*half_b) * (*half_b) - (*a) * c;
	return (discriminant);
}

t_bool	hit_sphere(t_object *sp_obj, t_ray *ray, t_hit_record *rec)
{
	double	a;
	double	half_b;
	double	c;
	double	discriminant;
	double	root;

	discriminant = sp_discriminant(sp_obj, ray, &half_b, &a);
	if (discriminant < 0)
		return (FALSE);
	root = (-half_b - sqrt(discriminant)) / a;
	if (root < rec->tmin || rec->tmax < root)
	{
		root = (-half_b + sqrt(discriminant)) / a;
		if (root < rec->tmin || rec->tmax < root)
			return (FALSE);
	}
	rec->t = root;
	rec->p = ray_at(ray, root);
	rec->normal = vdivide(vminus(rec->p, sp_obj->element->center), \
													sp_obj->element->radius);
	set_face_normal(ray, rec); // rec의 법선벡터와 광선의 방향벡터를 비교해서 앞면인지 뒷면인지 t_bool 값으로 저장.
	rec->albedo = sp_obj->albedo;
	return (TRUE);
}
