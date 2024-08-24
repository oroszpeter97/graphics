#include <stdio.h>
#include <unistd.h>

#include "tools/logger.h"
#include "core/vector.h"

int main(){
	log_init();

	Vector3* vector = new_vector();
	vector->print(vector);
	vector->dispose(vector);	

	return 0;
}
