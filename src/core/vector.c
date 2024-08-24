#include <stdio.h>
#include <stdlib.h>

#include "core/vector.h"
#include "tools/logger.h"

/* private functions*/
static void print(Vector3 *vector3){
	char buffer[512];
	sprintf(buffer, "(%lf, %lf, %lf)", vector3->x, vector3->y, vector3->z);
	log_message(DEBUG, buffer, TO_CONSOLE);
}

static void dispose(Vector3 *vector3){
	free(vector3);
}

/* public functions */
Vector3* new_vector(){
	Vector3* vector3 = (Vector3*)malloc(sizeof(Vector3));

	vector3->x=0.0;
	vector3->y=0.0;
	vector3->z=0.0;
	vector3->print=print;
	vector3->dispose=dispose;

	return vector3;
}

