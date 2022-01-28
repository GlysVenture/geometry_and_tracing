//
// Created by tkondrac on 28.01.22.
//

#include "geotrace.h"

/// Computes the transpose of matrix
/// \param a matrix
/// \param b pointer to result matrix
void	matrix_transpose(t_matrix a, t_matrix *b)
{
	b->x.x = a.x.x;
	b->x.y = a.y.x;
	b->x.z = a.z.x;
	b->y.x = a.x.y;
	b->y.y = a.y.y;
	b->y.z = a.z.y;
	b->z.x = a.x.z;
	b->z.y = a.y.z;
	b->z.z = a.z.z;
}

double	m_val(t_matrix *a, int row, int column)
{
	double val;

	val = ((double *)(((t_vec3d *)a) + row))[column];
	return (val);
}

double	get_cofactor(t_matrix a, int row, int column)
{
	double val;

	val = m_val(&a, (row + 1) % 3, (column + 1) % 3)
		 * m_val(&a, (row + 2) % 3, (column + 2) % 3)
		 - m_val(&a, (row + 2) % 3, (column + 1) % 3)
		   * m_val(&a, (row + 1) % 3, (column + 2) % 3);
	return (val);
}

double	matrix_determinant(t_matrix a)
{
	double	d;

	d = a.x.x * (a.y.y * a.z.z - a.z.y * a.y.z);
	d -= a.x.y * (a.y.x * a.z.z - a.z.x * a.y.z);
	d += a.x.z * (a.y.x * a.z.y - a.z.x * a.y.y);
	return (d);
}

void	cofactor_matrix(t_matrix a, t_matrix *c)
{
	c->x.x = get_cofactor(a, 0, 0);
	c->x.y = get_cofactor(a, 0, 1);
	c->x.z = get_cofactor(a, 0, 2);
	c->y.x = get_cofactor(a, 1, 0);
	c->y.y = get_cofactor(a, 1, 1);
	c->y.z = get_cofactor(a, 1, 2);
	c->z.x = get_cofactor(a, 2, 0);
	c->z.y = get_cofactor(a, 2, 1);
	c->z.z = get_cofactor(a, 2, 2);
}

void	matrix_scalar_mult(t_matrix a, double scalar, t_matrix *b)
{
	scalar_mult2(a.x, scalar, &b->x);
	scalar_mult2(a.y, scalar, &b->y);
	scalar_mult2(a.z, scalar, &b->z);
}

void	inverse_matrix(t_matrix a, t_matrix *b)
{
	cofactor_matrix(a, b);
	matrix_transpose(*b, b);
	matrix_scalar_mult(*b, 1 / matrix_determinant(a), b);
}
