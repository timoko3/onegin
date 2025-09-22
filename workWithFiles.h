#ifndef FILE_PARSE_H
#define FILE_PARSE_H

#include <stdlib.h>
#include <assert.h>
#include <stdio.h>

#include "strFunc.h"

#define FILE_DIVIDER fwrite(divider, sizeof(char), SIZE_OF_END_STR, outputFile);

const char* const INPUT_FILE_NAME                       = "onegin1.txt";   
const char* const OUTPUT_FILE_NAME                      = "oneginMcPushkaEdition.txt";
const char* const LOG_FILE_NAME                         = "logs.txt";
const char* const ALERT_FILE_OPEN_FAILURE               = "Ошибка при открытии файла %s\n";
const char* const ALERT_GET_INFO_FAILURE                = "Ошибка при попытке получить информацию о файле\n";
const char* const ALERT_STR_FROM_FILE_TO_STRUCT_FAILURE = "Ошибка при получении информации о файле в структуру\n";
const char* const ALERT_PRINT_RESULT_IN_FILE            = "Ошибка при записи результата в файл\n";
const char* const ALERT_RUNNING_LOGGING_SYSTEM_FAILURE  = "Ошибка при запуске сичтемы логирования\n";

const char* const GET_FILE_SIZE_ERROR_DESCRIPTION     = "getFileSize() failed";
const char* const OPEN_INPUT_FILE_ERROR_DESCRIPTION   = "openInputFile() failed";
const char* const OPEN_OUTPUT_FILE_ERROR_DESCRIPTION  = "openOutputFile() failed";
const char* const FAILURE_STRINGS_FROM_FILE_TO_STRUCT = "stringsFromFileToStructure() failed";
const char* const FAILURE_PRINT_RESULT_INF_FILE       = "printResultInFile() failed";
const char* const FAILURE_OPEN_LOG_FILE               = "openLogFile() failed";

struct DataFromInputFIle {
    size_t fileSize;
    FILE* inputFile;
    int nStrings;
    char* buffer;
    size_t bufferSize;
    string* strings;
};

FILE* openLogFile();

int stringsFromFileToStructure(DataFromInputFIle* DataFromInputFIle);
int printResultInFile(DataFromInputFIle* DataFromInputFIle);




#endif /*FILE_PARSE_H*/
