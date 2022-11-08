/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_sphere.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyokim <sooyokim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 14:56:45 by sooyokim          #+#    #+#             */
/*   Updated: 2022/11/08 14:56:54 by sooyokim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structures.h"
#include "utils.h"
#include "trace.h"

//hit_sphere는 관련 정보를 hit_record에 저장하고 TRUE & FALSE를 반환하므로,
//double    hit_sphere(t_sphere *sp, t_ray *ray)를 아래와 같이 변경
//typedef int t_bool; TRUE or FALSE를 return하는 함수를 표현하기 위해 t_bool 사용
t_bool      hit_sphere(t_object *sp_obj, t_ray *ray, t_hit_record *rec)
{
	t_vec3  oc; //방향벡터로 나타낸 구의 중심.
	//a, b, c는 각각 t에 관한 2차 방정식의 계수
	double  a;
	double  half_b;
	double  c;
	double  discriminant; //판별식
	double  sqrtd;
	double  root;

	t_object_value *sp;
	sp = sp_obj->element;
	oc = vminus(ray->orig, sp->center);
	a = vlength2(ray->dir);
	half_b = vdot(oc, ray->dir);
	c = vlength2(oc) - sp->radius2;
	discriminant = half_b * half_b - a * c;

	if (discriminant < 0)
		return (FALSE);
	sqrtd = sqrt(discriminant);
	//두 실근(t) 중 tmin과 tmax 사이에 있는 근이 있는지 체크, 작은 근부터 체크.
	root = (-half_b - sqrtd) / a;
	if (root < rec->tmin || rec->tmax < root)
	{
		root = (-half_b + sqrtd) / a;
		if (root < rec->tmin || rec->tmax < root)
			return (FALSE);
	}
	rec->t = root;
	rec->p = ray_at(ray, root);
	rec->normal = vdivide(vminus(rec->p, sp->center), sp->radius); // 정규화된 법선 벡터.
	set_face_normal(ray, rec); // rec의 법선벡터와 광선의 방향벡터를 비교해서 앞면인지 뒷면인지 t_bool 값으로 저장.
	rec->albedo = sp_obj->albedo;
	return (TRUE);
}
