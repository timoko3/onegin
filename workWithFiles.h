#ifndef FILE_PARSE_H
#define FILE_PARSE_H

#include <stdlib.h>
#include <assert.h>
#include <stdio.h>

#include "strFunc.h"

const char* const INPUT_FILE_NAME               = "onegin.txt";   
const char* const OUTPUT_FILE_NAME        = "oneginMcPushkaEdition.txt";
const char* const ALERT_FILE_OPEN_FAILURE = "Ошибка при открытии файла %s\n";



size_t getFileSize();
FILE* openInputFile();
char* getTextToBuffer(FILE* inputFile, int fileSize, int* nStrings);
string* divideBufferToStruct(char* buffer, int nStrings);

FILE* openOutputFile();
bool writeSortedToFIle(FILE* outputFile, string* strings, size_t nStrings, size_t fileSize);


#endif /*FILE_PARSE_H*/
