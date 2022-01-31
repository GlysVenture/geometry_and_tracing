//
// Created by Tadeusz Kondracki on 1/31/22.
//

#include <math.h>
#include <float.h>

#include "geotrace.h"

static int	get_x_int(double res[], t_line *ray)
{
	if (fabs(ray->direction[0]) <= FLT_EPSILON)
	{
		if (islessequal(ray->point[0], 1) && isgreaterequal(ray->point[0], 0))
			return (-1);
		return (0);
	}
	res[0] = (1 - ray->point[0]) / ray->direction[0];
	res[1] = - ray->point[0] / ray->direction[0];
	if (isless(res[1], res[0]))
		swap(res, res + 1);
	return (1);
}

static int	get_y_int(double res[], t_line *ray)
{
	if (fabs(ray->direction[1]) <= FLT_EPSILON)
	{
		if (islessequal(ray->point[1], 1) && isgreaterequal(ray->point[1], 0))
			return (-1);
		return (0);
	}
	res[0] = (1 - ray->point[1]) / ray->direction[1];
	res[1] = - ray->point[1] / ray->direction[1];
	if (isless(res[1], res[0]))
		swap(res, res + 1);
	return (1);
}

static int	get_z_int(double res[], t_line *ray)
{
	if (fabs(ray->direction[2]) <= FLT_EPSILON)
	{
		if (islessequal(ray->point[2], 1) && isgreaterequal(ray->point[2], 0))
			return (-1);
		return (0);
	}
	res[0] = (1 - ray->point[2]) / ray->direction[2];
	res[1] = - ray->point[2] / ray->direction[2];
	if (isless(res[1], res[0]))
		swap(res, res + 1);
	return (1);
}

static void	add_bounds(double res[], double temp[])
{
	if (isless(res[0], temp[0]))
		res[0] = temp[0];
	if (isgreater(res[1], temp[1]))
		res[1] = temp[1];
}

static int	get_res(t_line *ray, double res[])
{
	double	temp[3][2];
	int		t[3];

	t[0] = get_x_int(temp[0], ray);
	t[1] = get_y_int(temp[1], ray);
	t[2] = get_z_int(temp[2], ray);
	if (!t[0] || !t[1] || !t[2])
		return (0);
	if (t[0] == -1)
	{
		if (t[1] == -1)
		{
			res[0] = temp[2][0];
			res[1] = temp[2][1];
			return (1);
		}
		res[0] = temp[1][0];
		res[1] = temp[1][1];
	}
	else
	{
		res[0] = temp[0][0];
		res[1] = temp[0][1];
	}
	if (t[1] == 1)
		add_bounds(res, temp[1]);
	if (t[2] == 1)
		add_bounds(res, temp[2]);
	return (1);
}

static void	get_cube_normal(t_vec3d hit, t_vec3d normal)
{
	if (fabs(hit[0]) <= FLT_EPSILON || fabs(hit[0] - 1) <= FLT_EPSILON)
		set_vec(normal, 1, 0, 0);
	if (fabs(hit[1]) <= FLT_EPSILON || fabs(hit[1] - 1) <= FLT_EPSILON)
		set_vec(normal, 0, 1, 0);
	if (fabs(hit[2]) <= FLT_EPSILON || fabs(hit[2] - 1) <= FLT_EPSILON)
		set_vec(normal, 0, 0, 1);
}

double	cube_intersect2(t_object *cube, t_line ray, t_vec3d hit, t_vec3d normal)
{
	double	res[2];

	transform_ray(cube->inv, cube->tr_vec, &ray);
	if (!get_res(&ray, res) || isless(res[1], res[0]))
		return (-1);
	if (isgreater(res[1], 0) && isless(res[1], res[0]))
		swap(res, res + 1);
	if (isless(res[0], 0))
		return (-1);
	scalar_mult(ray.direction, res[0], hit);
	get_cube_normal(hit, normal);
	matrix_vect_prod(cube->transformation, hit, hit);
	return (vec_norm(hit));
}
