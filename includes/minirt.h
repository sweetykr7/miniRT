/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyokim <sooyokim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 11:32:00 by sooyokim          #+#    #+#             */
/*   Updated: 2022/11/09 11:55:30 by sooyokim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include <stdlib.h>
# include "structures.h"

typedef struct structure_img{
	void		*img_ptr;
	char		*data;
	int			size_l;
	int			bpp;
	int			endian;
}				t_img;

typedef struct s_complex
{
	double		re;
	double		im;
}				t_complex;

typedef struct structure_mlx
{
	void		*mlx_ptr;
	void		*win_ptr;
	t_img		img;
	t_scene		*scene;
	double		color_set;
}				t_mlx;


int			hook_key(int key, t_mlx *mlx);
int			hook_mouse(int button, int x, int y, t_mlx *mlx);
void		zoom(int x, int y, t_mlx *mlx, double z);
void		render(t_mlx *mlx, t_scene *scene);
void		camera_move(t_scene *scene, t_mlx *mlx, char option);
void		object_control(int key, t_mlx *mlx);
void		object_rotate(int key, t_mlx *mlx);
int			input_check(int ac, const char **av);
t_mlx		*mlx_structure_init(t_mlx *mlx, t_scene *scene);
t_mlx		*init_mlx(const char *fractol, const char **av, t_scene *scene);
t_img		new_image(t_mlx *mlx, t_scene *scene);
t_object	*get_current_object(t_scene *scene);

int			terminate_minirt(t_mlx *mlx);
void		reset_viewpoint(t_mlx *mlx);
int			error_return_zero(int *error);

#endif