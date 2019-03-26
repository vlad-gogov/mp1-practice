#include "Vector.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#define M_PI 3.14159265358979323846

void New(Vector* x)
{
	x->dim = 0;
	x->val = NULL;
}

int Create(int _n, Vector* result)
{
	if (_n > 0)
	{
		int i;
		result->dim = _n;
		result->val = (float*)malloc((sizeof(float)) * _n);
		for (i = 0; i < _n; i++)
			result->val[i] = 0.0f;
		return 0;
	}
	result->dim = _n;
	result->val = NULL;
	return 1;
}

void Input(Vector x)
{
	int i = 0;
	for (i = 0; i < x.dim; i++)
		scanf("%f", x.val + i);
}

void Output(Vector x)
{
	int i = 0;
	printf("( ");
	for (i = 0; i < x.dim; i++)
		printf("%.f ", x.val[i]);
	printf(")\n");
}

int Delete(Vector* x)
{
	x->dim = 0;
	if (x->val)
		free(x->val);
	x->val = NULL;
	return 0;
}

int Sum(Vector x, Vector y, Vector* result)
{
	int i = 0;
	if ((x.dim != y.dim) || (x.dim < 0) || (y.dim < 0))
		return 1;
	if(x.dim == 0 && y.dim == 0)
	Delete(result);
	Create(x.dim, result);
	for (i = 0; i < x.dim; i++)
		result->val[i] = x.val[i] + y.val[i];
	return 0;
}

int Sub(Vector x, Vector y, Vector* result)
{
	int i = 0;
	if ((x.dim != y.dim) || (x.dim < 0) || (y.dim < 0))
		return 1;
	Delete(result);
	Create(x.dim, result);
	for (i = 0; i < x.dim; i++)
		result->val[i] = x.val[i] - y.val[i];
	return 0;
}

int Scal(Vector x, Vector y, double* result)
{
	int i = 0;
	if ((x.dim != y.dim) || (x.dim < 0) || (y.dim < 0))
		return 1;
	*result = 0;
	for (i = 0; i < x.dim; i++)
		*result += x.val[i] * y.val[i];
	return 0;
}

int Angle(Vector x, Vector y, double* result)
{
	double scal = 0, lens = 0, len_x = 0, len_y = 0;
	if ((x.dim != y.dim) || (x.dim < 0) || (y.dim < 0))
		return 1;
	if (Len(x, &len_x) || Len(y, &len_y) || Scal(x, y, &scal))
		return 1;
	lens = len_x * len_y;
	if (!lens)
		return 2;
	*result = (acos(scal / lens)) * 180 / M_PI;
	return 0;
}

int Len(Vector x, double* result)
{
	int i = 0;
	*result = 0;
	if (!x.dim)
		return 1;
	for (i = 0; i < x.dim; i++)
		*result += x.val[i] * x.val[i];
	*result = sqrt(*result);
	return 0;
}