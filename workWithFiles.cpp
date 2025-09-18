#include "workWithFiles.h"


#include <sys/stat.h>

static int countStrings(char* buf, int fileSize, char endStr);

size_t getFileSize(){
    struct stat file_info;

    if(stat(INPUT_FILE_NAME, &file_info) != 0){
        fprintf(stderr, "ќшибка при попытке получить информацию о файле\n");
        return EXIT_FAILURE;
    }

    return file_info.st_size;
}

FILE* openInputFile(){
    FILE* inputFile;

    if(!(inputFile = fopen(INPUT_FILE_NAME, "rb"))){
        printf(ALERT_FILE_OPEN_FAILURE, INPUT_FILE_NAME);
        return NULL;
    }

    return inputFile;
}

char* getTextToBuffer(FILE* inputFIle, int fileSize, int* nStrings){
    assert(inputFIle);
    assert(nStrings);

    printf(" оличество символов в файле %s(вернул stat) fileSize: %d\n", INPUT_FILE_NAME, fileSize);
    char* buffer = (char*) calloc(fileSize, sizeof(char)); 
    assert(buffer);

    fread(buffer, sizeof(char), fileSize, inputFIle);
    printf(" ол-во символов по-насто€щему прочитанных из файла: %d\n", myStrLen(buffer));
    
    *nStrings = countStrings(buffer, fileSize, END_STR);

    return buffer;
}

string* divideBufferToStruct(char* buffer, int nStrings){
    assert(buffer);

    printf(" ол-во строк Ч %d\n", nStrings);
    printf("ƒлина буфера Ч %d", myStrLen(buffer));

    string* strings = (string*) calloc(nStrings, sizeof(string));
    assert(strings);

    printf("јдрес strings Ч %p\n", strings);

    strings[0].stringPtr = buffer;

    int curStr = 1;
    int i = 0; // rename
    for(i = 0; buffer[i] != '\0'; i++){
        printf("—ейчас символ Ч %d\n", buffer[i]);
        if((buffer[i] == END_STR) && (buffer[i + 1] != '\0')){
            strings[curStr].stringPtr = buffer + i + 1  ;
            
            printf("“екуща€ строкв %d Ч\n", curStr);

            strings[curStr - 1].len = strings[curStr].stringPtr - strings[curStr - 1].stringPtr;
            curStr++;

        }
    }
    printf("curstr Ч %d\n", curStr);
    strings[curStr - 1].len = (buffer + i) - strings[curStr - 1].stringPtr;

    return strings;
}

FILE* openOutputFile(){
    FILE* outputFile = NULL;

    if(!(outputFile = fopen(OUTPUT_FILE_NAME, "wb"))){
        printf(ALERT_FILE_OPEN_FAILURE, OUTPUT_FILE_NAME);
        return NULL;
    }

    return outputFile;
}

bool writeSortedToFIle(FILE* outputFile, string* strings, size_t nStrings, size_t fileSize){
    assert(outputFile);
    assert(strings);
    
    char* outputBuffer = (char*) calloc(fileSize, sizeof(char));
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

    printf("\n\nOutput buffer: %s его размер: %d\n", outputBuffer, myStrLen(outputBuffer));

    if(fwrite(outputBuffer, sizeof(char), fileSize, outputFile) != fileSize) return false;
    
    free(outputBuffer);

    return true;
}

static int countStrings(char* buf, int fileSize, char endStr){
    assert(buf);

    int nStrings = 1;

    int i = 0;
    while(i < fileSize){
        if(buf[i] == endStr){
            nStrings++;
        }
        i++;
    }

    return nStrings;
}
