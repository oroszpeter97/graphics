#ifndef VECTOR_H
#define VECTOR_H

typedef struct Vector{
	float x;
	float y;
	float z;
} Vector3;

Vector3* vector3_create(float x, float y, float z);
void vector3_print(Vector3 *vector3);
void vector3_dispose(Vector3 *vector3);
Vector3* vector3_add(const Vector3* a, const Vector3* b);
Vector3* vector3_subtract(const Vector3* a, const Vector3* b);
Vector3* vector3_multiply(const Vector3* v, float scalar);
Vector3* vector3_divide(const Vector3* v, float scalar);
float vector3_dot(const Vector3* a, const Vector3* b);
Vector3* vector3_cross(const Vector3* a, const Vector3* b);
float vector3_magnitude(const Vector3* v);
void vector3_normalize(Vector3* v);
float vector3_distance(const Vector3* a, const Vector3* b);

#endif
