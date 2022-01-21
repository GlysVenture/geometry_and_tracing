//
// Created by tkondrac on 21.01.22.
//

#include <math.h>

#include "vec3d.h"

/// Multiplication of a vector by a scalar. For an implementation with
/// memory allocation see scalar_mult()
/// \param v vector
/// \param a scalar
/// \param new pointer to result vector
void	scalar_mult2(const t_vec3d v, const double a, t_vec3d *new)
{
	new->x = a * v.x;
	new->y = a * v.y;
	new->z = a * v.z;
}

/// Computes vector product. For an implementation with memory allocation
/// see vec_prod()
/// \param v vector
/// \param u vector
/// \param new pointer to result vector
void	vec_prod2(const t_vec3d v, const t_vec3d u, t_vec3d *new)
{
	new->x = v.y * u.z - v.z * u.x;
	new->y = v.z * u.x - v.x * u.z;
	new->z = v.x * u.y - v.y * u.x;
}

/// Computes unit vector aka vector with length 1. For an implementation with
/// memory allocation see unit_vector()
/// \param v vector
/// \param new pointer to result vector
void	unit_vector2(const t_vec3d v, t_vec3d *new)
{
	scalar_mult2(v, 1 / vec_norm(v), new);
}
