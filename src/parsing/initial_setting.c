/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initial_setting.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinwoole <indibooks@naver.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 10:46:29 by sooyokim          #+#    #+#             */
/*   Updated: 2022/11/14 12:12:01 by jinwoole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "mlx.h"
#include "../libft/includes/libft.h"

t_mlx	*mlx_structure_init(t_mlx *mlx, t_scene *scene)
{
	mlx->mlx_ptr = mlx_init();
	if (!mlx->mlx_ptr)
		return (0);
	mlx->win_ptr = mlx_new_window(mlx->mlx_ptr, \
		scene->canvas.width, scene->canvas.height, "miniRT");
	if (!mlx->win_ptr)
		return (0);
	return (mlx);
}

t_img	new_image(t_mlx *mlx, t_scene *scene)
{	
	t_img	img;

	img.img_ptr = mlx_new_image(mlx->mlx_ptr, \
			scene->canvas.width, scene->canvas.height);
	img.data = mlx_get_data_addr(img.img_ptr, &img.bpp, &img.size_l,
			&img.endian);
	return (img);
}

t_mlx	*init_mlx(t_scene *scene)
{
	t_mlx	*mlx;

	mlx = malloc(sizeof(t_mlx));
	if (!mlx)
		return (0);
	mlx = mlx_structure_init(mlx, scene);
	if (!mlx)
		return (0);
	mlx->img = new_image(mlx, scene);
	if (!mlx->img.img_ptr)
		return (0);
	return (mlx);
}
