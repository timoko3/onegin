#ifndef FILE_PARSE_H
#define FILE_PARSE_H

#include <stdlib.h>
#include <assert.h>
#include <stdio.h>

const char* const FILE_NAME               = "onegin.txt";   
const char* const ALERT_FILE_OPEN_FAILURE = "Не удалось открыть файл %s\n";

void openFile(FILE** fp);
void getText(FILE* fp, char strings[][1000]);
char* myFGets(char* str, int count, FILE* stream);


#endif /*FILE_PARSE_H*/
