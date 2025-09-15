#include "fileParse.h"

#include <sys/stat.h>

static int countStrings(char* buf, int fileSize);

void openFile(FILE** fp){
    assert(fp);

    if(!(*fp = fopen(FILE_NAME, "r"))){
        printf(ALERT_FILE_OPEN_FAILURE, FILE_NAME);
    }

}

void getText(FILE* fp, char** strings, int fileSize){
    assert(fp);
    assert(strings);
    char* buffer = (char*) calloc(fileSize, sizeof(char)); 
    fread(buffer, sizeof(char), fileSize, fp);

    int nStrings = countStrings(buffer, fileSize);
    
    strings = (char**) calloc(nStrings, sizeof(char*));


    int curStr = 1;
    int i = 0;
    strings[0] = buffer;
    while(i < fileSize){
        if(buffer[i] == '\0'){
            strings[curStr] = buffer + i;
            curStr++;
        }
        i++;
    }

    for(int j = 0; j < nStrings; j++){
        printf("%s\n", strings[j]);
    }
    
    free(buffer);
}

static int countStrings(char* buf, int fileSize){
    assert(buf);

    int nStrings = 1;

    int i = 0;
    while(i < fileSize){
        if(buf[i] == '\n'){
            buf[i] = '\0';
            nStrings++;
        }
        i++;
    }

    return nStrings;
}
