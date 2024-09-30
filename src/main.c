#include <stdio.h>
#include <unistd.h>

#include "tools/logger.h"
#include "core/vector3.h"

int main(){
	log_init();
	log_message(WARNING, "This is a warning", TO_CONSOLE);

	Vector3* vector = vector3_new();
	vector3_print(vector);
	vector3_dispose(vector);	
	s

	return 0;
}
