/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinwoole <indibooks@naver.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 11:28:56 by sooyokim          #+#    #+#             */
/*   Updated: 2022/11/10 15:16:37 by jinwoole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "minirt.h"
#include "structures.h"
#include "utils.h"
#include "scene.h"
#include "trace.h"
#include "parsing.h"

void	set_first_object(t_list *e, int *is_first, t_object *world)
{
	if (e->id == SP)
		world = object(SP, sphere(point3(1, 0, 1), 5), color3(1, 0.5, 0)); // world 에 구1 추가
	else if (e->id == CY)
		world = object(CY, scylinder(point3(10, 1, 2), vec3(0,1/sqrt(2),1/sqrt(2)), 10, 10), color3(10/255, 0, 255/255));
	else if (e->id == PL)
		world = object(PL, splane(point3(0, 0, 5), vec3(0,0,1)), color3(1, 0, 0));
	*is_first = FALSE;
}

void	scene_set(t_list *e, t_scene *scene, int *is_first)
{
	if (e->id == C)
	{
		scene->canvas = canvas(800, 600, (double)(180 - e->fov)/90);
		scene->camera = camera(&scene->canvas, point3(e->origin[0], e->origin[1], e->origin[2]));
	}
	else if (e->id == A)
		scene->ambient = vmult(color3(e->rgb[0] / 255, e->rgb[1] / 255, e->rgb[2] / 255), e->ratio); // 8.4 에서 설명
	else if (e->id == SP)
	{
		oadd(&scene->world, object(SP, sphere(point3(-8, 0, 1), 5), color3(0, 0.5, 0))); // world 에 구2 추가
	}
	

/*	else if (e->id == SP || e->id == PL || e->id == CY && *is_first == TRUE)
		set_first_object(e, is_first, world);
	else if (e->id == SP && *is_first == FALSE)
		oadd(&world, object(SP, sphere(point3(-8, 0, 1), 5), color3(0, 0.5, 0))); // world 에 구2 추가
	else if (e->id == CY && *is_first == FALSE)
		oadd(&world, object(CY, scylinder(point3(10, 1, 2), vec3(0,1/sqrt(2),1/sqrt(2)), 3, 20), color3(10/255, 0, 255/255))); // world 에 원기둥
	else if (e->id == PL && *is_first == FALSE)
 		oadd(&world, object(PL, splane(point3(0, 0, 0), vec3(0,0,1)), color3(1, 1, 1))); // world 에 평면 추가
		 */
}

t_scene	*scene_init(t_list *d)
{
	t_scene		*scene;
//	t_object	*world;
	t_object	*lights;
	int	i;
	double		ka;
	int			is_first;

	i = 0;
	is_first == TRUE;
	if(!(scene = (t_scene *)malloc(sizeof(t_scene))))
		ft_error("Malloc failure");
	scene->world = object(SP, sphere(point3(1, 0, 1), 5), color3(1, 0.5, 0)); // world 에 구1 추가
	while (i < ft_lstsize(d))
	{
		scene_set(ft_lstselect(d, i), scene, &is_first);
		printf("<%d>\n", i);
		i++;
	}

	//oadd(&world, object(SP, sphere(point3(-8, 0, 1), 5), color3(0, 0.5, 0))); // world 에 구2 추가
	oadd(&scene->world, object(CY, scylinder(point3(10, 1, 2), vec3(0,1/sqrt(2),1/sqrt(2)), 3, 20), color3(10/255, 0, 255/255))); // world 에 원기둥
	oadd(&scene->world, object(PL, splane(point3(0, 0, 0), vec3(0,0,1)), color3(1, 1, 1))); // world 에 평면 추가



	int cnt = 6;
	scene->total_obj_cnt = ft_lstsize(d); ///함수에 집어넣어야함. 자동화로
//	scene->world = world;
	lights = object_light(LIGHT_POINT, light_point(point3(20, 3, 30), color3(1, 1, 1), 0.4), color3(0, 0, 0)); // 더미 albedo
	scene->light = lights;
	ka = 0.1; // 8.4 에서 설명
	//scene->ambient = vmult(color3(1,1,1), ka); // 8.4 에서 설명
	scene->mode = CAMERA_MODE;
	scene->object_mode = OBJECT_POSITION;
	scene->object_cnt = 0;
	// scene->cur_obj = scene->world;
	return (scene);
}


int	main(int ac, const char **av)
{
	t_mlx		*mlx;
	t_scene		*scene;
	t_list		*data;

	if (ac != 2)
		ft_error("Put 1 argument\n");
	printf("%s\n", av[1]);
	data = map_init(av[1], scene);
	//parsing 영역
	scene = scene_init(data);

	printf("%f\n",scene->camera.viewport_h);

	mlx = init_mlx(av, scene);
	mlx->scene = scene;
	render(mlx, scene);
	mlx_key_hook(mlx->win_ptr, hook_key, mlx);
	mlx_hook(mlx->win_ptr, 17, 0, terminate_minirt, mlx);
	mlx_loop(mlx->mlx_ptr);
	return (0);
}
