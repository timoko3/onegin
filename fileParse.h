#ifndef FILE_PARSE_H
#define FILE_PARSE_H

#include <stdlib.h>
#include <assert.h>
#include <stdio.h>

#include "strFunc.h"

const char* const FILE_NAME               = "onegin.txt";   
const char* const ALERT_FILE_OPEN_FAILURE = "Ошибка при открытии файла %s\n";



size_t getFileSize();
FILE* openFile();
char* getTextToBuffer(FILE* fp, int fileSize, int* nStrings);
string* divideBufferToStruct(char* buffer, int nStrings);


#endif /*FILE_PARSE_H*/
