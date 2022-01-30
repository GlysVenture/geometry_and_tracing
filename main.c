#include <stdio.h>

#include "geotrace.h"

int main() {
	t_line	ray = {{0, 1, 0}, { 1, -2, 2 }};
	t_line	ray2 = {{1, 0, 0}, { -2, 0, 2}};
//	t_plane	plane = {{-5, 1, 1}, {0, 1, 0}};
	t_matrix a = {{1,0,0},{0,1,0},{0,0,3}};
	t_object sphere;
	t_vec3d p;

	set_matrix(sphere.transformation, a[0], a[1], a[2]);
	inverse_matrix(sphere.transformation, sphere.inv);
	matrix_transpose(sphere.inv, sphere.inv_transp);
	set_vec(sphere.tr_vec, 1, 0, 0);

	printf("intersect distance: %f\n", sphere_intersect2(&sphere, ray, p));
	printf("intersect distance: %f\n", sphere_intersect2(&sphere, ray2, p));

	return 0;
}
