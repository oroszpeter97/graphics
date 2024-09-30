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
### New vector
`Vector3* vector = vector3_new();`

### Dispose
Using `vector3_dispose(Vector*)` is recommended instead of `free()`.