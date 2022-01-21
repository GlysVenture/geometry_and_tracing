//
// Created by tkondrac on 21.01.22.
//

#ifndef VEC3D_H
# define VEC3D_H

/// mathematical vector
/// \param x coord
/// \param y coord
/// \param z coord
typedef struct s_vec3d
{
	double	x;
	double	y;
	double	z;
}	t_vec3d;

t_vec3d	*scalar_mult(t_vec3d v, double a);

double	dot_prod(t_vec3d v, t_vec3d u);

t_vec3d	*vec_prod(t_vec3d v, t_vec3d u);

double	vec_norm(t_vec3d v);

t_vec3d	*unit_vector(t_vec3d v);

void	scalar_mult2(t_vec3d v, double a, t_vec3d *new);

void	vec_prod2(t_vec3d v, t_vec3d u, t_vec3d *new);

void	unit_vector2(t_vec3d v, t_vec3d *new);

#endif //VEC3D_H
