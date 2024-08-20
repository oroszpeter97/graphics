#ifndef LOGGER_H
#define LOGGER_H

#include <time.h>

#define MAX_LOG_LENGTH 1024
#define MAX_LOG_FILENAME_LENGTH 512

typedef struct {
    int year;
    int month;
    int day;
    int hour;
    int minute;
    int second;
} DateTime;

typedef enum {
	INFO,
	WARNING,
	ERROR,
	DEBUG
} LogLevel;

typedef enum {
	TO_CONSOLE,
	TO_FILE,
	TO_BOTH
} LogTarget;

void log_message(LogLevel log_level, const char *message, LogTarget log_target);
void log_init();

#endif
