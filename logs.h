#ifndef LOGS_H
#define LOGS_H

#include <time.h>
#include <stdio.h>
#include <stdarg.h>

#define INFO(message_args, ...)  log_message("INFO", __FILE__, __LINE__, message_args, ##__VA_ARGS__)
#define ERROR(message_args, ...)  log_message("ERROR", __FILE__, __LINE__, message_args, ##__VA_ARGS__)

const int BEGINNING_YEAR = 1900;


void log_message(const char* type, const char* file, const int curCodeStrNum, const char* message_args, ...);

#endif /* LOGS_H */
