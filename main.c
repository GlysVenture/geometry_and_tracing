#include <stdio.h>

#include "geotrace.h"

int main() {
	t_line	ray = {{1, 0, 0}, { 0, 0, 0 }};
	t_plane	plane = {{-5, 1, 1}, {0, 1, 0}};
	t_matrix a = {{1, 2, 0},{4, 5, 6},{7, 8, 9}};
	t_matrix b, c;

	printf("intersect distance: %f\n", plane_intersect(&plane, ray));

	print_matrix(a);
	cofactor_matrix(a, c);
	print_matrix(c);
	inverse_matrix(a, b);
	print_matrix(b);
	matrix_prod(a, b, a);
	print_matrix(a);
	return 0;
}
