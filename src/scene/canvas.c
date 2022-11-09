#include "scene.h"

t_canvas	canvas(int width, int height, double fov)
{
	t_canvas	canvas;

	canvas.width = width;
	canvas.height = height;
	canvas.aspect_ratio = (double)width / (double)height;
	canvas.fov = fov;
	return (canvas);
}