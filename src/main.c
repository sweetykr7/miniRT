/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinwoole <indibooks@naver.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 11:28:56 by sooyokim          #+#    #+#             */
/*   Updated: 2022/11/10 16:09:00 by jinwoole         ###   ########.fr       */
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
	if (e->id == C)
	{ //아마 지금 카메라 벡터를 어떻게 못하는 상황임
		scene->canvas = canvas(1280, 720, (double)(180 - e->fov)/90);
		scene->camera = camera(&scene->canvas, point3(e->ori[0], e->ori[1], e->ori[2]));
	}
	else if (e->id == A)
		scene->ambient = vmult(color3(e->rgb[0] / 255, e->rgb[1] / 255, e->rgb[2] / 255), e->ratio);
	else if (e->id == L)
		scene->light = object_light(LIGHT_POINT, light_point(point3(e->ori[0], e->ori[1],e->ori[2]), color3(e->rgb[0], e->rgb[1], e->rgb[2]), e->ratio), color3(0, 0, 0)); // 더미 albedo
		//여기 마지막 color3?
	else if (e->id == SP)
		oadd(&scene->world, object(SP, sphere(point3(e->ori[0], e->ori[1],e->ori[2]), e->diameter), color3(e->rgb[0], e->rgb[1], e->rgb[2]))); 
	else if (e->id == CY)
		oadd(&scene->world, object(CY, scylinder(point3(e->ori[0], e->ori[1],e->ori[2]), vec3(e->vec[0] / sqrt(2), e->vec[1] / sqrt(2),e->vec[2] / sqrt(2)), 3, 20), color3(e->rgb[0], e->rgb[1], e->rgb[2]))); 
//	else if (e->id == PL)
		//oadd(&scene->world, object(PL, splane(point3(0, 0, 0), vec3(0,0,1)), color3(1, 1, 1)));
}
//할일 1. 변수잘넣기


t_scene	*scene_init(t_list *d)
{
	t_scene		*scene;
	t_object	*lights;
	int	i;
	double		ka;

	i = 0;
	if(!(scene = (t_scene *)malloc(sizeof(t_scene))))
		ft_error("Malloc failure");
	while (i < ft_lstsize(d))
	{
		scene_set(ft_lstselect(d, i), scene);
		printf("<%d>\n", i);
		i++;
	}
	int cnt = 6;
	scene->total_obj_cnt = ft_lstsize(d); ///함수에 집어넣어야함. 자동화로
//	lights = object_light(LIGHT_POINT, light_point(point3(20, 3, 30), color3(1, 1, 1), 0.4), color3(0, 0, 0)); // 더미 albedo
//	scene->light = lights;
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
