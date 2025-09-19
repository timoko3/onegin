#ifndef FILE_PARSE_H
#define FILE_PARSE_H

#include <stdlib.h>
#include <assert.h>
#include <stdio.h>

#include "strFunc.h"

const char* const INPUT_FILE_NAME         = "onegin1.txt";   
const char* const OUTPUT_FILE_NAME        = "oneginMcPushkaEdition.txt";
const char* const ALERT_FILE_OPEN_FAILURE = "Ошибка при открытии файла %s\n";
const char* const ALERT_GET_INFO_FAILURE  = "Ошибка при попытке получить информацию о файле\n";

const char* const GET_FILE_SIZE_ERROR_DESCRIPTION    = "getFileSize() failed";
const char* const OPEN_INPUT_FILE_ERROR_DESCRIPTION  = "openInputFile() failed";
const char* const OPEN_OUTPUT_FILE_ERROR_DESCRIPTION = "openOutputFile() failed";

size_t getFileSize();
FILE* openInputFile();
char* getTextToBuffer(FILE* inputFile, int fileSize, int* nStrings);
string* divideBufferToStruct(char* buffer, int nStrings);

FILE* openOutputFile();
bool writeSortedToFIle(FILE* outputFile, string* strings, size_t nStrings, size_t fileSize);


#endif /*FILE_PARSE_H*/
