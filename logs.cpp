#include "logs.h"
#include "workWithFiles.h"

void log_message(const char* type, const char* file, const int curCodeStrNum, const char* message, ...){
    assert(type);
    assert(file);
    assert(message);

    FILE* logsFile = NULL;
    if(!(logsFile = openLogFile())) printf("Система логирования не работает\n");
    assert(logsFile);

    time_t curTime = time(NULL);
    struct tm* now = localtime(&curTime);
    assert(now);

    fprintf(logsFile, "[%d-%d-%d %d:%d:%d] [%s] ", now->tm_year + BEGINNING_YEAR, 
                                                  now->tm_mon, 
                                                  now->tm_mday, 
                                                  now->tm_hour, 
                                                  now->tm_min, 
                                                  now->tm_sec,
                                                  type);

    va_list message_args_list;
    va_start(message_args_list, message);
    vfprintf(logsFile, message, message_args_list);
    va_end(message_args_list);

    fprintf(logsFile, " %s:%d\r\n", file, curCodeStrNum);

    fclose(logsFile);
                                                  
}