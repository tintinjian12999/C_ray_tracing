#ifndef SHAPE_H
#define SHAPE_H

#include "ray.h"

typedef struct {
	Vector position;
	Vector normal;
} Plane;

typedef struct {
	Vector position;
	float radius;
} Sphere;

typedef union {
	Plane p;
	Sphere s;
} Element;

struct Node {
	Element e;
	struct Node* next;
};

static inline void INIT_LIST_HEAD(struct Node *n)
{
	n->next = n;
}
#define LIST_HEAD(head) struct list_head head = {&(head), &(head)}
#endif