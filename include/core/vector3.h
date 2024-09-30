#ifndef VECTOR_H
#define VECTOR_H

typedef struct Vector{
	double x;
	double y;
	double z;
} Vector3;

Vector3* new_vector3();
void vector3_print(Vector3 *vector3);
void vector3_dispose(Vector3 *vector3);

#endif
