/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyokim <sooyokim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 11:28:56 by sooyokim          #+#    #+#             */
/*   Updated: 2022/11/10 10:36:30 by sooyokim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "minirt.h"
#include "structures.h"
#include "utils.h"
#include "scene.h"
#include "trace.h"

t_scene	*scene_init(void)
{
	t_scene		*scene;
	t_object	*world;
	t_object_light	*lights;
	double		ka; // 8.4 에서 설명

	// malloc 할당 실패 시, 실습에서는 return NULL로 해두었지만, 적절한 에러 처리가 필요하다.
	if(!(scene = (t_scene *)malloc(sizeof(t_scene))))
		return (NULL);
	scene->canvas = canvas(800, 600, FOV);
	scene->camera = camera(&scene->canvas, point3(0, 0, 20.6));
	// world = object(SP, sphere(point3(0, 0, 1), 5), color3(1, 0.5, 0)); // world 에 구1 추가
	// oadd(&world, object(CY, scylinder(point3(10, 1, 2), vec3(0,1/sqrt(2),1/sqrt(2)), 10, 10), color3(10/255, 0, 255/255))); // world 에 원기둥
	// oadd(&world, object(PL, splane(point3(0, 0, 5), vec3(0,0,1)), color3(1, 0, 0))); // world 에 평면 추가


	world = object(SP, sphere(point3(1, 0, 1), 5), color3(1, 0.5, 0)); // world 에 구1 추가
	oadd(&world, object(SP, sphere(point3(-8, 0, 1), 5), color3(0, 0.5, 0))); // world 에 구2 추가
	oadd(&world, object(CY, scylinder(point3(10, 1, 2), vec3(0,1/sqrt(2),1/sqrt(2)), 3, 20), color3(10/255, 0, 255/255))); // world 에 원기둥
	oadd(&world, object(PL, splane(point3(0, 0, 0), vec3(0,0,1)), color3(1, 1, 1))); // world 에 평면 추가

	int cnt = 4;
	scene->total_obj_cnt = 4; ///함수에 집어넣어야함. 자동화로


	// oadd(&world, object(SP, sphere(point3(0, -1000, 0), 995), color3(1, 1, 1))); // world 에 구3 추가
	// oadd(&world, object(SP, sphere(point3(0, -1000, 0), 999), color3(1, 1, 1))); // world 에 구3 추가
	scene->world = world;
	lights = object_light(LIGHT_POINT, light_point(point3(20, 3, 30), color3(1, 1, 1), 0.4), color3(0, 0, 0)); // 더미 albedo
	scene->light = lights;
	ka = 0.1; // 8.4 에서 설명
	scene->ambient = vmult(color3(1,1,1), ka); // 8.4 에서 설명
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

	//parsing 영역
	scene = scene_init();
	mlx = init_mlx(av, scene);
	mlx->scene = scene;
	render(mlx, scene);
	mlx_key_hook(mlx->win_ptr, hook_key, mlx);
	mlx_hook(mlx->win_ptr, 17, 0, terminate_minirt, mlx);
	mlx_loop(mlx->mlx_ptr);
	return (0);
}
