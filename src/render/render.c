/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyokim <sooyokim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 11:29:36 by sooyokim          #+#    #+#             */
/*   Updated: 2022/11/09 12:16:51 by sooyokim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "mlx.h"
#include "trace.h"

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = (img->data) + (x * img->bpp / 8) + (y * img->size_l);
	*(unsigned int *)dst = color;
}

int	color_set(t_color3 pixel_color)
{
	double	r;
	double	g;
	double	b;
	int		color;

	r = (255.999 * pixel_color.x);
	g = (255.999 * pixel_color.y);
	b = (255.999 * pixel_color.z);
	color = ((int)(r) << 16) + ((int)(g) << 8) + ((int)(b));
	return (color);
}

void	render(t_mlx *mlx, t_scene *scene)
{
	int			i;
	int			j;
	double		u;
	double		v;
	t_color3	pixel_color;

	i = -1;
	while (++i < scene->canvas.width)
	{
		j = -1;
		while (++j < scene->canvas.height)
		{
			u = (double)(i) / (scene->canvas.width - 1);
			v = (double)((scene->canvas.height - j)) \
								/ (scene->canvas.height - 1);
			scene->ray = ray_primary(&scene->camera, u, v);
			pixel_color = ray_color(scene);
			my_mlx_pixel_put(&(mlx->img), i, j, color_set(pixel_color));
		}
	}
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, \
								(mlx->img.img_ptr), 0, 0);
}

