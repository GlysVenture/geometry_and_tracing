//
// Created by Tadeusz Kondracki on 2/10/22.
//

#include "geotrace.h"
#include <math.h>
#include <float.h>
#include <criterion/criterion.h>

#define isequalf(a, b) (fabs((a) - (b)) <= FLT_EPSILON)

#define matrix_expect(a, b1, b2, b3, b4, b5, b6, b7, b8, b9, str) {cr_expect(isequalf((a)[0][0], (b1)), str);\
cr_expect(isequalf((a)[0][1], (b2)), str);\
cr_expect(isequalf((a)[0][2], (b3)), str);\
cr_expect(isequalf((a)[1][0], (b4)), str);\
cr_expect(isequalf((a)[1][1], (b5)), str);\
cr_expect(isequalf((a)[1][2], (b6)), str);\
cr_expect(isequalf((a)[2][0], (b7)), str);\
cr_expect(isequalf((a)[2][1], (b8)), str);\
cr_expect(isequalf((a)[2][2], (b9)), str);}

Test(matrix_tests, product)
{
	t_matrix	m = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
	t_matrix	m2 = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

	matrix_prod(m, m2, m);
	matrix_expect(m, 30, 36, 42, 66, 81, 96, 102, 126, 150, "matrix product doesn't work");
}

Test(matrix_tests, inverse)
{
	t_matrix	m = {{1, 2, 0}, {4, 5, 6}, {7, 8, 9}};
	t_matrix	i;


	inverse_matrix(m, i);
	matrix_prod(m, i, i);

	matrix_expect(i, 1, 0, 0, 0, 1, 0, 0, 0, 1, "matrix inverse doesn't work");
}
