#ifndef VECTOR_H
#define VECTOR_H

typedef struct Vector{
	double x;
	double y;
	double z;
	void (*print)(struct Vector*);
	void (*dispose)(struct Vector*);
} Vector3;

Vector3* new_vector();

#endif
