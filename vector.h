#ifndef VECTOR_H
#define VECTOR_H
#include <math.h>
/*Square Calaulation*/
inline float sqr(float n)
{
	return n * n;
}
/*Define a Single Vector*/
typedef struct {
	float x, y, z;
	float length;
} Vector;

inline Vector* vector_init(Vector* v1)
{
	v1->x = 0;
	v1->y = 0;
	v1->z = 0;
	v1->length = 0;
	return v1;
}

inline float length_square(Vector* v)
{
	return sqr(v->x) + sqr(v->y) + sqr(v->z);
}

inline float set_length(Vector* v)
{
	v->length = sqrt(length_square(v));
	return v->length;
}

Vector* vector_normalized(Vector* v)
{
	Vector* v1;
	v1->x = v->x / v->length;
	v1->y = v->y / v->length;
	v1->z = v->z / v->length;
	v1->length = 1;
	return v1;
}

inline float dot(Vector* v1, Vector* v2) 
{
	return (v1->x * v2->x) + (v1->y * v2->y) + (v1->z * v2->z);
}

Vector* cross(Vector* v1, Vector* v2)
{	
	Vector* v3;
	v3->x = (v1->y * v2->z) - (v1->z * v2->y);
	v3->y = (v1->z * v2->x) - (v1->x * v2->z);
	v3->z = (v1->x * v2->y) - (v1->y * v2->x);
	return v3;
}

inline Vector* add(Vector* v1, Vector* v2)
{
	v1->x += v2->x;
	v1->y += v2->y;
	v1->z += v2->z;
	return v1;
}

inline Vector* sub(Vector* v1, Vector* v2)
{
	v1->x -= v2->x;
	v1->y -= v2->y;
	v1->z -= v2->z;
	return v1;
}

inline Vector* mul_f(Vector* v1, float f)
{
	v1->x *= f;
	v1->y *= f;
	v1->z *= f;
	return v1;
}

inline Vector* mul_v(Vector* v1, Vector* v2)
{
	v1->x *= v2->x;
	v1->y *= v2->y;
	v1->z *= v2->z;
	return v1;
}

inline Vector* over_f(Vector* v1, float f)
{
	v1->x /= f;
	v1->y /= f;
	v1->z /= f;
	return v1;
}

inline Vector* over_v(Vector* v1, Vector* v2)
{
	v1->x /= v2->x;
	v1->y /= v2->y;
	v1->z /= v2->z;
	return v1;
}

inline Vector* reverse(Vector* v1)
{
	v1->x = -(v1->x);
	v1->y = -(v1->y);
	v1->z = -(v1->z);
	return v1;
}
#endif