#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#include "logger.h"

static DateTime log_file_date_time = {0, 0, 0, 0, 0, 0};

/* private functions */
static void get_current_date_time(DateTime *date_time){
	time_t t;
	struct tm *tm_info;
	time(&t);
	tm_info = localtime(&t);
	date_time->year = tm_info->tm_year + 1900;
	date_time->month = tm_info->tm_mon + 1;
	date_time->day = tm_info->tm_mday;
	date_time->hour = tm_info->tm_hour;
	date_time->minute = tm_info->tm_min;
	date_time->second = tm_info->tm_sec;
}

static void date_time_to_string(DateTime date_time, char *date_time_string){
	sprintf(date_time_string, "%d-%d-%d-%d-%d-%d", 
		date_time.year, date_time.month, date_time.day, 
		date_time.hour, date_time.minute, date_time.second);
}

static void log_filename_builder(char *filename){
	sprintf(filename, "logs/%d-%d-%d-%d-%d-%d.log", 
		log_file_date_time.year, log_file_date_time.month, log_file_date_time.day, 
		log_file_date_time.hour, log_file_date_time.minute, log_file_date_time.second);
}

static void log_builder(LogLevel log_level_enum, const char *message, char *console_log, char *file_log){
	DateTime current_date_time = {0, 0, 0, 0, 0, 0};
	char *current_date_time_string = (char *)malloc(512 * sizeof(char));
	get_current_date_time(&current_date_time);
	date_time_to_string(current_date_time, current_date_time_string);
	
	switch(log_level_enum){
		case INFO:
			sprintf(console_log, "\033[0;30;47m%s - INFO: %s\033[0m", current_date_time_string, message);
			sprintf(file_log, "%s - INFO: %s", current_date_time_string, message);
			break;
		case WARNING: 
			sprintf(console_log, "\033[0;30;43m%s - WARNING: %s\033[0m", current_date_time_string, message);
			sprintf(file_log, "%s - WARNING: %s", current_date_time_string, message);
			break;
		case ERROR: 
			sprintf(console_log, "\033[0;37;41m%s - ERROR: %s\033[0m", current_date_time_string, message);
			sprintf(file_log, "%s - ERROR: %s", current_date_time_string, message);
			break;
		case DEBUG:
			sprintf(console_log, "\033[0;30;42m%s - DEBUG: %s\033[0m", current_date_time_string, message);
			sprintf(file_log, "%s - DEBUG: %s", current_date_time_string, message);
			break;
		default: 
			sprintf(console_log, "\033[0;37;41m%s - WRONG ENUM: %s\033[0m", current_date_time_string, message);
			sprintf(file_log, "%s - WRONG ENUM: %s", current_date_time_string, message);
			break;
	}

	free(current_date_time_string);
}

static void log_message_to_file(char *file_log){
	char *filename = (char *)malloc(MAX_LOG_FILENAME_LENGTH * sizeof(char));
	log_filename_builder(filename);
	FILE *log_file;
	log_file = fopen(filename, "r");
	
	if (log_file) {
		fclose(log_file);
	} else {
		log_file = fopen(filename, "w");
		if (log_file) {
			fclose(log_file);
		} else {
			log_message(ERROR, "Failed to create file!", TO_CONSOLE);
		}
	}

	log_file = fopen(filename, "a");
	if (log_file) {
		fprintf(log_file, "%s\n", file_log);
		fclose(log_file);
	} else {
		log_message(ERROR, "Failed to open file for appending!", TO_CONSOLE);
	}
	free(filename);
}

/* public functions */
void log_message(LogLevel log_level_enum, const char *message, LogTarget log_target_enum){
	char *console_log = (char *)malloc(MAX_LOG_LENGTH * sizeof(char));	
	char *file_log = (char *)malloc(MAX_LOG_LENGTH * sizeof(char));	

  if (console_log == NULL || file_log == NULL) {
  	perror("Failed to allocate memory");
  	free(console_log);
  	free(file_log);
		return;
    }

	log_builder(log_level_enum, message, console_log, file_log);

	if(log_target_enum == TO_CONSOLE || log_target_enum == TO_BOTH){
		printf("%s\n", console_log);
	}

	if(log_target_enum == TO_FILE || log_target_enum == TO_BOTH){
		log_message_to_file(file_log);
	}

	free(console_log);
	free(file_log);
}

void log_init(){
	get_current_date_time(&log_file_date_time);
}
