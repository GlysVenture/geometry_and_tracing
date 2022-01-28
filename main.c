#include <stdio.h>

#include "geotrace.h"

void	print_matrix(const t_matrix a)
{
	printf("matrix\n");
	printf("| %.3f : %.3f : %.3f |\n", a.x.x, a.x.y, a.x.z);
	printf("| %.3f : %.3f : %.3f |\n", a.y.x, a.y.y, a.y.z);
	printf("| %.3f : %.3f : %.3f |\n", a.z.x, a.z.y, a.z.z);
	printf("determinant : %.3f\n", matrix_determinant(a));
}

int main() {
	t_line	ray = {{1, 0, 0}, { 0, 0, 0 }};
	t_plane	plane = {{-5, 1, 1}, {0, 1, 0}};
	t_matrix a = {{1, 2, 0},{4, 5, 6},{7, 8, 9}};
	t_matrix b, c;

	printf("intersect distance: %f\n", plane_intersect(&plane, ray));

	print_matrix(a);
	inverse_matrix(a, &b);
	print_matrix(b);
	matrix_prod(a, b, &c);
	print_matrix(c);
	return 0;
}
