/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyokim <sooyokim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 11:28:56 by sooyokim          #+#    #+#             */
/*   Updated: 2022/11/14 14:38:47 by sooyokim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "minirt.h"
#include "structures.h"
#include "utils.h"
#include "scene.h"
#include "trace.h"
#include "parsing.h"

void	scene_set(t_list *e, t_scene *scene)
{
	t_point3	p3;
	t_point3	c3;
	t_vec3		v3;

	p3 = point3(e->ori[0], e->ori[1], e->ori[2]);
	v3 = vec3(e->vec[0], e->vec[1], e->vec[2]);
	c3 = color3(e->rgb[0], e->rgb[1], e->rgb[2]);
	if (e->id == C)
	{
		scene->canvas = canvas(800, 600, 1.0);
		scene->camera = camera(&scene->canvas, p3, e->fov, v3);
	}
	else if (e->id == A)
		scene->ambient = vmult(c3, e->ratio);
	else if (e->id == L)
		scene->light = object_light(LIGHT_POINT, \
								light_point(p3, c3, e->ratio), color3(0, 0, 0));
	else if (e->id == SP)
		oadd(&scene->world, object(SP, sphere(p3, e->diameter), c3));
	else if (e->id == CY)
		oadd(&scene->world, \
					object(CY, scylinder(p3, v3, e->diameter, e->height), c3));
	else if (e->id == PL)
		oadd(&scene->world, object(PL, splane(p3, v3), c3));
}

t_scene	*scene_init(t_list *d)
{
	t_scene		*scene;
	int			i;

	i = 0;
	scene = (t_scene *)malloc(sizeof(t_scene));
	if (!scene)
		ft_error("Malloc failure");
	while (i < ft_lstsize(d))
	{
		scene_set(ft_lstselect(d, i), scene);
		printf("<%d>\n", i);
		i++;
	}
	scene->total_obj_cnt = ft_lstsize(d) - 3;
	scene->mode = CAMERA_MODE;
	scene->object_mode = OBJECT_POSITION;
	scene->object_cnt = 0;
	return (scene);
}

int	main(int ac, const char **av)
{
	t_mlx		*mlx;
	t_scene		*scene;
	t_list		*data;

	if (ac != 2)
		ft_error("Put 1 argument\n");
	data = map_init(av[1]);
	scene = scene_init(data);
	mlx = init_mlx(scene);
	ft_lstfree(data);
	mlx->scene = scene;
	render(mlx, scene);
	mlx_key_hook(mlx->win_ptr, hook_key, mlx);
	mlx_hook(mlx->win_ptr, 17, 0, terminate_minirt, mlx);
	mlx_loop(mlx->mlx_ptr);
	return (0);
}
