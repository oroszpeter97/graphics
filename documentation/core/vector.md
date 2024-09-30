# Vector

## Struct
```
typedef struct Vector{
	double x;
	double y;
	double z;
} Vector3;
```

## Usage
```
Vector3* v1 = vector3_create(1.0f, 2.0f, 3.0f);
Vector3* v2 = vector3_create(4.0f, 5.0f, 6.0f);

if (v1 == NULL || v2 == NULL) {
	printf("Memory allocation failed.\n");
	return 1;
}

Vector3* sum = vector3_add(v1, v2);
Vector3* diff = vector3_subtract(v1, v2);
float dotProd = vector3_dot(v1, v2);
Vector3* crossProd = vector3_cross(v1, v2);
float distance = vector3_distance(v1, v2);

printf("Sum: (%f, %f, %f)\n", sum->x, sum->y, sum->z);
printf("Difference: (%f, %f, %f)\n", diff->x, diff->y, diff->z);
printf("Dot Product: %f\n", dotProd);
printf("Cross Product: (%f, %f, %f)\n", crossProd->x, crossProd->y, crossProd->z);
printf("Distance: %f\n", distance);

vector3_normalize(v1);
printf("Normalized v1: (%f, %f, %f)\n", v1->x, v1->y, v1->z);
```

### Dispose
Using `vector3_dispose(Vector*)` is recommended instead of `free()`.
```
vector3_dispose(v1);
vector3_dispose(v2);
vector3_dispose(sum);
vector3_dispose(diff);
vector3_dispose(crossProd);
```