#include <stdio.h>

#include "geotrace.h"

int main() {
	t_line	ray = {{0, 1, 0}, { 3, -3, 4}};
	t_line	ray2 = {{1, 0, 0}, { -2, 0, 0}};
	t_matrix a = {{3.5,0,0},{0,4,0},{0,0,5}};
	t_object obj;
	t_vec3d p, d;

	set_matrix(obj.transformation, a[0], a[1], a[2]);
	inverse_matrix(obj.transformation, obj.inv);
	matrix_transpose(obj.inv, obj.inv_transp);
	set_vec(obj.tr_vec, 1, 0, 0);

	printf("intersect distance: %f\n", cylinder_intersect2(&obj, ray, p, d));
	printf("intersect distance: %f\n", cylinder_intersect2(&obj, ray2, p, d));

	return 0;
}
