#include <stdio.h>

#include "geotrace.h"

int main() {
	t_line	ray;
	t_plane	plane;

	//ray
	ray.point.x = 0;
	ray.point.y = 0;
	ray.point.z = 0;
	ray.direction.x = 1;
	ray.direction.y = 0;
	ray.direction.z = 0;

	//sphere
	set_vec(&plane.point, -2, 0, 0);
	set_vec(&plane.normal, 0, 1, 0);

	printf("intersect distance: %f\n", plane_intersect(&plane, ray));

	return 0;
}
