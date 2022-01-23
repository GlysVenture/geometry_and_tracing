#include <stdio.h>

#include "geotrace.h"

int main() {
	t_line	ray = {1, 0, 0,
				0, 0, 0};
	t_plane	plane = {-5, 1, 1,
				0, 1, 0};

	printf("intersect distance: %f\n", plane_intersect(&plane, ray));

	return 0;
}
