//
// Created by tkondrac on 28.01.22.
//

#include <stdlib.h>

#include "geotrace.h"

/// Sets the values of an existing matrix
/// \param a matrix
/// \param x 1st row
/// \param y 2nd row
/// \param z 3rd row
void		set_matrix(t_matrix *a, t_vec3d x, t_vec3d y, t_vec3d z)
{
	a->x = x;
	a->y = y;
	a->z = z;
}

/// Alters a single value of a matrix
/// \param a matrix
/// \param line coord
/// \param column coord
/// \param val value to put at row and column specified
void		set_matrix_spot(t_matrix *a, int line, int column, double val)
{
	if (line == 1)
	{
		if (column == 1)
			a->x.x = val;
		else if (column == 2)
			a->x.y = val;
		else if (column == 3)
			a->x.z = val;
	}
	else if (line == 2)
	{
		if (column == 1)
			a->y.x = val;
		else if (column == 2)
			a->y.y = val;
		else if (column == 3)
			a->y.z = val;
	}
	else if (line == 3)
	{
		if (column == 1)
			a->z.x = val;
		else if (column == 2)
			a->z.y = val;
		else if (column == 3)
			a->z.z = val;
	}
}

/// Creates a new matrix
/// \param x 1st row
/// \param y 2nd row
/// \param z 3rd row
/// \return memory allocated [t_matrix*]
t_matrix	*init_matrix(t_vec3d x, t_vec3d y, t_vec3d z)
{
	t_matrix	*new;

	new = malloc(sizeof(t_matrix));
	if (!new)
		return (NULL);
	new->x = x;
	new->y = y;
	new->z = z;
	return (new);
}

/// Multiplies given vector by a matrix
/// \param a matrix
/// \param v vector
/// \param u pointer to result vector
void	matrix_vect_prod(t_matrix a, t_vec3d v, t_vec3d *u)
{
	u->x = dot_prod(a.x, v);
	u->y = dot_prod(a.y, v);
	u->z = dot_prod(a.z, v);
}

/// Computes Matrix multiplication
/// \param a matrix
/// \param b matrix
/// \param c pointer to result matrix
void	matrix_prod(t_matrix a, t_matrix b, t_matrix *c)
{
	matrix_transpose(b, &b);
	matrix_vect_prod(a, b.x, &c->x);
	matrix_vect_prod(a, b.y, &c->y);
	matrix_vect_prod(a, b.z, &c->z);
	matrix_transpose(*c, c);
}
