#include <stdio.h>
#include <unistd.h>

#include "logger.h"

int main(){
	log_init();
	log_message(INFO, "This is an info log!", TO_BOTH);
	sleep(1);
	log_message(WARNING, "This is a warning log!", TO_BOTH);
	sleep(2);
	log_message(ERROR, "This is an error log!", TO_BOTH);
	sleep(3);
	log_message(DEBUG, "This is a debug log!", TO_BOTH);
	return 0;
}
