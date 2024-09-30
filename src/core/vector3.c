#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "core/vector3.h"
#include "tools/logger.h"

Vector3* vector3_create(float x, float y, float z) {
    Vector3* v = (Vector3*)malloc(sizeof(Vector3));  
    if (v == NULL) return NULL;

    v->x = x;
    v->y = y;
    v->z = z;

    return v;
}

void vector3_print(Vector3 *vector3){
	char buffer[512];
	sprintf(buffer, "(%lf, %lf, %lf)", vector3->x, vector3->y, vector3->z);
	log_message(DEBUG, buffer, TO_CONSOLE);
}

void vector3_dispose(Vector3 *vector3){
	free(vector3);
}

Vector3* vector3_add(const Vector3* a, const Vector3* b) {
    Vector3* result = (Vector3*)malloc(sizeof(Vector3));
    if (result == NULL) return NULL;

    result->x = a->x + b->x;
    result->y = a->y + b->y;
    result->z = a->z + b->z;

    return result;
}

Vector3* vector3_subtract(const Vector3* a, const Vector3* b) {
    Vector3* result = (Vector3*)malloc(sizeof(Vector3));
    if (result == NULL) return NULL;

    result->x = a->x - b->x;
    result->y = a->y - b->y;
    result->z = a->z - b->z;

    return result;
}

Vector3* vector3_multiply(const Vector3* v, float scalar) {
    Vector3* result = (Vector3*)malloc(sizeof(Vector3));
    if (result == NULL) return NULL;
    result->x = v->x * scalar;
    result->y = v->y * scalar;
    result->z = v->z * scalar;
    return result;
}

Vector3* vector3_divide(const Vector3* v, float scalar) {
    Vector3* result = (Vector3*)malloc(sizeof(Vector3));
    if (result == NULL) return NULL;

    result->x = v->x / scalar;
    result->y = v->y / scalar;
    result->z = v->z / scalar;

    return result;
}

float vector3_dot(const Vector3* a, const Vector3* b) {
    return a->x * b->x + a->y * b->y + a->z * b->z;
}

Vector3* vector3_cross(const Vector3* a, const Vector3* b) {
    Vector3* result = (Vector3*)malloc(sizeof(Vector3));
    if (result == NULL) return NULL;

    result->x = a->y * b->z - a->z * b->y;
    result->y = a->z * b->x - a->x * b->z;
    result->z = a->x * b->y - a->y * b->x;

    return result;
}

float vector3_magnitude(const Vector3* v) {
    return sqrt(v->x * v->x + v->y * v->y + v->z * v->z);
}

void vector3_normalize(Vector3* v) {
    float mag = vector3_magnitude(v);
    if (mag == 0) return; 

    v->x /= mag;
    v->y /= mag;
    v->z /= mag;
}

float vector3_distance(const Vector3* a, const Vector3* b) {
    Vector3 diff = {a->x - b->x, a->y - b->y, a->z - b->z};

    return vector3_magnitude(&diff);
}
