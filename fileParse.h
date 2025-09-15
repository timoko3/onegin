#ifndef FILE_PARSE_H
#define FILE_PARSE_H

#include <stdlib.h>
#include <assert.h>
#include <stdio.h>

const char* const FILE_NAME               = "onegin.txt";   
const char* const ALERT_FILE_OPEN_FAILURE = "Ошибка при открытии файла %s\n";

void openFile(FILE** fp);
void getText(FILE* fp, char** strings, int fileSize);
char* myFGets(char* str, int count, FILE* stream);


#endif /*FILE_PARSE_H*/
