#include "workWithFiles.h"

#include <sys/stat.h>

static int countStrings(char* buf, int fileSize, char endStr);

size_t getFileSize(){
    struct stat file_info;

    if(stat(INPUT_FILE_NAME, &file_info) != 0){
        fprintf(stderr, ALERT_GET_INFO_FAILURE);
        return EXIT_FAILURE;
    }

    return file_info.st_size;
}

FILE* openInputFile(){
    FILE* inputFile = NULL;

    if(!(inputFile = fopen(INPUT_FILE_NAME, "rb"))){
        printf(ALERT_FILE_OPEN_FAILURE, INPUT_FILE_NAME);
        return NULL;
    }

    return inputFile;
}

char* getTextToBuffer(FILE* inputFIle, int fileSize, int* nStrings){
    assert(inputFIle);
    assert(nStrings);

    char* buffer = (char*) calloc(fileSize + SIZE_OF_END_STR, sizeof(char)); 
    assert(buffer);
    buffer[fileSize] = '\r';
    buffer[fileSize + 1] = '\n';

    fread(buffer, sizeof(char), fileSize, inputFIle);
    
    *nStrings = countStrings(buffer, fileSize, END_STR);

    return buffer;
}

string* divideBufferToStruct(char* buffer, int nStrings){
    assert(buffer);

    string* strings = (string*) calloc(nStrings, sizeof(string));
    assert(strings);

    strings[0].stringPtr = buffer;

    int curStr = 1;
    int curSym = 0;
    for(curSym = 0; buffer[curSym] != '\0'; curSym++){
        if((buffer[curSym] == END_STR) && (buffer[curSym + 1] != '\0')){
            strings[curStr].stringPtr = buffer + curSym + 1;
            strings[curStr - 1].len = strings[curStr].stringPtr - 
                                      strings[curStr - 1].stringPtr;
            curStr++;
        }
    }

    strings[curStr - 1].len = (buffer + curSym) - strings[curStr - 1].stringPtr;

    return strings;
}

FILE* openOutputFile(){
    FILE* outputFile = NULL;

    if(!(outputFile = fopen(OUTPUT_FILE_NAME, "w+b"))){
        printf(ALERT_FILE_OPEN_FAILURE, OUTPUT_FILE_NAME);
        return NULL;
    }

    return outputFile;
}

bool writeSortedToFIle(FILE* outputFile, string* strings, size_t nStrings, size_t bufferSize){
    assert(outputFile);
    assert(strings);
    
    bool result = true;

    char* outputBuffer = (char*) calloc(bufferSize, sizeof(char));
    assert(outputBuffer);
    
    int curBufInd = 0;
    for(size_t curStrInd = 0; curStrInd < nStrings; curStrInd++){
        size_t curSymInd = 0;
        while(curSymInd < strings[curStrInd].len){
            
            outputBuffer[curBufInd] = strings[curStrInd].stringPtr[curSymInd];
            curSymInd++;
            curBufInd++;
        }
        
    }
    
    if(fwrite(outputBuffer, sizeof(char), bufferSize, outputFile) != bufferSize) result = false;
    free(outputBuffer);

    return result;
}

static int countStrings(char* buf, int fileSize, char endStr){
    assert(buf);

    int nStrings = 1;

    int curSym = 0;
    while(curSym < fileSize){
        if(buf[curSym] == endStr){
            nStrings++;
        }
        curSym++;
    }

    return nStrings;
}
