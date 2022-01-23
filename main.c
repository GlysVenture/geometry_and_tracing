#include <stdio.h>

#include "geotrace.h"

int main() {
	t_line		ray;
	t_sphere	sphere;

	//ray
	ray.point.x = 0;
	ray.point.y = 0;
	ray.point.z = 0;
	ray.direction.x = 1;
	ray.direction.y = 0;
	ray.direction.z = 0;

	//sphere
	sphere.radius = 2;
	sphere.center.x = 4;
	sphere.center.y = 2;
	sphere.center.z = 0;

	printf("intersect distance: %f\n", sphere_intersect(&sphere, ray));

	return 0;
}
