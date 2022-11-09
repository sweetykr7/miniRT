/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinwoole <indibooks@naver.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 11:28:56 by sooyokim          #+#    #+#             */
/*   Updated: 2022/11/09 16:20:30 by jinwoole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
//#include "minirt.h"
#include "structures.h"
#include "utils.h"
#include "print.h"
#include "scene.h"
#include "trace.h"
//#include "src/libft/includes/libft.h"
#include "parsing.h"

/*t_scene	*scene_init(void)
{
	t_scene		*scene;
	t_object	*world;
	t_object	*lights;
	double		ka; // 8.4 에서 설명

	// malloc 할당 실패 시, 실습에서는 return NULL로 해두었지만, 적절한 에러 처리가 필요하다.
	if(!(scene = (t_scene *)malloc(sizeof(t_scene))))
		ft_error("Malloc failure");

	scene->canvas = canvas(800, 600);
	scene->camera = camera(&scene->canvas, point3(0, 0, 20.6));
	// world = object(SP, sphere(point3(0, 0, 1), 5), color3(1, 0.5, 0)); // world 에 구1 추가
	// oadd(&world, object(CY, scylinder(point3(10, 1, 2), vec3(0,1/sqrt(2),1/sqrt(2)), 10, 10), color3(10/255, 0, 255/255))); // world 에 원기둥
	// oadd(&world, object(PL, splane(point3(0, 0, 5), vec3(0,0,1)), color3(1, 0, 0))); // world 에 평면 추가

	world = object(SP, sphere(point3(0, 0, 1), 5), color3(1, 0.5, 0)); // world 에 구1 추가
	oadd(&world, object(SP, sphere(point3(-8, 0, 1), 5), color3(0, 0.5, 0))); // world 에 구2 추가
	oadd(&world, object(CY, scylinder(point3(10, 1, 2), vec3(0,1/sqrt(2),1/sqrt(2)), 10, 10), color3(10/255, 0, 255/255))); // world 에 원기둥
	oadd(&world, object(PL, splane(point3(0, 0, 0), vec3(0,0,1)), color3(1, 1, 1))); // world 에 평면 추가

	// oadd(&world, object(SP, sphere(point3(0, -1000, 0), 995), color3(1, 1, 1))); // world 에 구3 추가
	// oadd(&world, object(SP, sphere(point3(0, -1000, 0), 999), color3(1, 1, 1))); // world 에 구3 추가
	scene->world = world;
	lights = object(LIGHT_POINT, light_point(point3(20, 3, 30), color3(1, 1, 1), 0.4), color3(0, 0, 0)); // 더미 albedo
	scene->light = lights;
	ka = 0.1; // 8.4 에서 설명
	scene->ambient = vmult(color3(1,1,1), ka); // 8.4 에서 설명
	return (scene);
}*/

t_scene	*scene_init(t_list *d)
{
	t_scene		*scene;
	t_object	*world;
	t_object	*lights;
	int			i;

	// malloc 할당 실패 시, 실습에서는 return NULL로 해두었지만, 적절한 에러 처리가 필요하다.
	if(!(scene = (t_scene *)malloc(sizeof(t_scene))))
		ft_error("Malloc failure");
	i = 0;
	while (i < ft_lstsize(d))
	{
		if (ft_lstselect(d, i)->id == C)
		{
			scene->canvas = canvas(800, 600, d->fov/90);
			scene->camera = camera(&scene->canvas, point3(d->origin[0], d->origin[1], d->origin[2]));
		}
		else if (ft_lstselect(d, i)->id == A)
			scene->ambient = vmult(color3(d->rgb[0] / 255, d->rgb[1] / 255, d->rgb[2] / 255), d->ratio); // 8.4 에서 설명
		else if (ft_lstselect(d, i)->id == L)
		{
			lights = object_light(LIGHT_POINT, light_point(point3(20, 3, 30), color3(1, 1, 1), 0.4), color3(0, 0, 0)); // 더미 albedo

			lights = object(LIGHT_POINT, \
			//light_point(point3(d->origin[0], d->origin[1], d->origin[2]), \
			color3(d->rgb[0] / 255, d->rgb[1] / 255, d->rgb[2] / 255), d->ratio), color3(0, 0, 0));
			scene->light = lights;
		}
		i++;
	}

	// world = object(SP, sphere(point3(0, 0, 1), 5), color3(1, 0.5, 0)); // world 에 구1 추가
	// oadd(&world, object(CY, scylinder(point3(10, 1, 2), vec3(0,1/sqrt(2),1/sqrt(2)), 10, 10), color3(10/255, 0, 255/255))); // world 에 원기둥
	// oadd(&world, object(PL, splane(point3(0, 0, 5), vec3(0,0,1)), color3(1, 0, 0))); // world 에 평면 추가

//	scene->canvas = canvas(800, 600, 1.0);
//	scene->camera = camera(&scene->canvas, point3(0, 0, 20.6));

	world = object(SP, sphere(point3(1, 0, 1), 5), color3(1, 0.5, 0)); // world 에 구1 추가
	oadd(&world, object(SP, sphere(point3(-8, 0, 1), 5), color3(0, 0.5, 0))); // world 에 구2 추가
	oadd(&world, object(CY, scylinder(point3(10, 1, 2), vec3(0,1/sqrt(2),1/sqrt(2)), 3, 20), color3(10/255, 0, 255/255))); // world 에 원기둥
	oadd(&world, object(PL, splane(point3(0, 0, 0), vec3(0,0,1)), color3(1, 1, 1))); // world 에 평면 추가


	// oadd(&world, object(SP, sphere(point3(0, -1000, 0), 995), color3(1, 1, 1))); // world 에 구3 추가
	// oadd(&world, object(SP, sphere(point3(0, -1000, 0), 999), color3(1, 1, 1))); // world 에 구3 추가
	scene->world = world;

	return (scene);
}


int	main(int ac, const char **av)
{
	t_mlx		*mlx;
	t_viewpoint	*vp;
	t_scene		*scene;
	t_list		*data;

	if (ac != 2)
		ft_error("Put 1 argument\n");
	data = map_init(av[1], scene);

	scene = scene_init(data);

	mlx = init_mlx(av[1], av, scene);
	render(mlx, scene);
	mlx_key_hook(mlx->win_ptr, hook_key, mlx);
	mlx_hook(mlx->win_ptr, 4, 0, hook_mouse, mlx);
	mlx_hook(mlx->win_ptr, 17, 0, terminate_fractol, mlx);
	mlx_loop(mlx->mlx_ptr);
	return (0);
}
