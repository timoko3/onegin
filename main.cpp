#include <stdio.h>
#include <sys\stat.h>

#include "workWithFiles.h"
#include "strFunc.h"
#include "UI.h"

#define DIVIDE printf("\n");

int main(void){

    size_t fileSize = 0;
    if((fileSize = getFileSize()) == EXIT_FAILURE) return EXIT_FAILURE;

    FILE* inputFIle = NULL;
    if(!(inputFIle = openInputFile())) return EXIT_FAILURE;
    assert(inputFIle);

    int nStrings = 0;

    char* buffer = getTextToBuffer(inputFIle, fileSize, &nStrings);
    assert(buffer);
    
    fclose(inputFIle);

    string* strings = divideBufferToStruct(buffer, nStrings);
    assert(strings);

    printOnegin(strings, nStrings);
    // printf("–езультат myStrCmp Ч %d\n", myStrCmp(strings[0].stringPtr, strings[1].stringPtr));
    
    strings = sortStrings(strings, nStrings);

    printf("\n-----------------------\n");
    
    printOnegin(strings, nStrings);

    FILE* outputFile = NULL;
    if(!(outputFile = openOutputFile())) return EXIT_FAILURE;
    assert(outputFile);
    
    if(!(writeSortedToFIle(outputFile, strings, nStrings, fileSize))) return EXIT_FAILURE;


    fclose(outputFile);
    free(buffer);
    free(strings);


}