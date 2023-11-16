#ifndef RAY_H
#define RAY_H

#include "vector.h"
/*To prevent intersections where distance is zero*/
#define RAY_T_MIN 0.0001f

/*Intersection occur far enough is not considered*/
#define RAY_T_MAX 1.0e30f

typedef struct {
	Vector* origin; // The start point of ray, the length of start point will remain 0;
	Vector* direction; // The direction vector of ray
	float tMax;
} Ray;

typedef struct {
	Ray* ray;
	float t;
} Intersection;

inline Ray* ray_init(Ray* r1)
{
	vector_init(r1->origin);
	vector_init(r1->direction);
	r1->tMax = RAY_T_MAX;
	return r1;
}

inline Ray* ray_given(Ray* r1, Vector* o1, Vector* v1, float tM)
{
	r1->origin = o1;
	r1->direction = v1;
	r1->tMax = tM;
	return r1;
}

inline Vector* ray_forward(Ray* r1, float t)
{
	return add(r1->origin, mul_f(r1->direction, t));
}

inline Intersection* intersection_init(Intersection* i1)
{
	ray_init(i1->ray);
	i1->t = RAY_T_MAX;
	return i1;
}

inline Intersection* intersection_given(Intersection* i1, Ray* r1)
{
	i1->ray = r1;
	i1->t = r1->tMax;
	return i1;
}
// The ray is intersected or not
bool intersected(Ray* r1)
{

}
// The position of ray 
Vector* position(Ray* r1, float t)
{
	return ray_forward(r1, t);
}
#endif