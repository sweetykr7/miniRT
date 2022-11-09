/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyokim <sooyokim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 10:20:17 by sooyokim          #+#    #+#             */
/*   Updated: 2022/11/09 12:04:49 by sooyokim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_H
# define STRUCTURES_H
# include <unistd.h>

# define LUMEN 3  // 이 값을 조절하여 장면의 밝기를 조절할 수 있다.
# define FOV 1.0
# define MOVE_OFFSET 3
# define ROTATE_ANGLE 90
# define FOV_GAP 0.1

typedef struct s_vec3			t_vec3;
typedef struct s_vec3			t_point3;
typedef struct s_vec3			t_color3;
typedef struct s_ray			t_ray;
typedef struct s_camera			t_camera;
typedef struct s_canvas			t_canvas;
typedef struct s_object			t_object;
typedef struct s_object_light	t_object_light;
typedef struct s_sphere			t_sphere;
typedef struct s_plane			t_plane;
typedef struct s_cylinder		t_cylinder;
typedef struct s_light			t_light;
typedef struct s_hit_record		t_hit_record;
typedef struct s_scene			t_scene;
typedef struct s_object_value	t_object_value;

typedef int						t_bool;
# define FALSE 0
# define TRUE 1

typedef int						t_object_type;
# define SP 0
# define PL 1
# define CY 2
# define LIGHT_POINT 10

# define EPSILON 1e-6 


# define CAMERA_MODE 0
# define OBJECT_MODE 1

# define OBJECT_POSITION 0
# define OBJECT_ROTATE 1

struct s_vec3
{
	double	x;
	double	y;
	double	z;
};

struct	s_ray
{
	t_point3	orig;
	t_vec3		dir;
};

struct	s_camera
{
	t_point3	orig;
	double		viewport_h; // 뷰포트 세로길이
	double		viewport_w; // 뷰포트 가로길이
	t_vec3		horizontal; // 수평길이 벡터
	t_vec3		vertical; // 수직길이 벡터
	double		focal_len; // focal length
	t_point3	left_bottom; // 왼쪽 아래 코너점
};

struct	s_canvas
{
	int		width; //canvas width
	int		height; //canvas height;
	double	aspect_ratio; //종횡비
	double	fov;
};

struct	s_sphere
{
	t_point3	center;
	double		radius;
	double		radius2;
};

struct s_hit_record
{
	t_point3	p; //교점의 좌표
	t_vec3		normal;
	double		tmin;
	double		tmax;
	double		t; //원점과 교점사이의 거리
	t_bool		front_face;
	t_color3	albedo;
};

struct s_object_value
{
	t_point3	center;
	t_vec3		dir;
	double		diameter;
	double		height;
	double		radius;
	double		radius2;
};


struct	s_object
{
	t_object_type	type;
	t_object_value	*element;
	t_object		*next;
	t_color3		albedo;
};

struct	s_object_light
{
	t_object_type	type;
	t_light			*element;
	t_object_light	*next;
	t_color3		albedo;
};

struct	s_light
{
	t_point3	origin;
	t_color3	light_color;
	double		bright_ratio;
};

struct	s_scene
{
	t_canvas		canvas;
	t_camera		camera;
	t_object		*world;
	t_object_light	*light;
	t_color3		ambient; // 8.4에서 설명할 요소
	t_ray			ray;
	t_hit_record	rec;
	int				mode;
	int				object_mode;
	size_t			object_cnt;
	size_t			total_obj_cnt;
};

struct s_plane
{
	t_point3	center;
	t_vec3		dir;
};

struct s_cylinder
{
	t_point3	center;
	t_vec3		dir;
	double		diameter;
	double		height;
};

#endif