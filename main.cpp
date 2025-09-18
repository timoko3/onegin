#include <stdio.h>
#include <sys\stat.h>

#include "workWithFiles.h"
#include "strFunc.h"
#include "UI.h"

#define DIVIDE printf("\n-----------------------\n");
#define FILE_DIVIDER fwrite(divider, sizeof(char), 2, outputFile);

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
    
    size_t bufferSize = fileSize + 2;

    string* strings = divideBufferToStruct(buffer, nStrings);
    assert(strings);

    printOnegin(strings, nStrings);
    // printf("–езультат myStrCmpFromBegin Ч %d\n", myStrCmpFromBegin(strings[0].stringPtr, strings[1].stringPtr));
    
    FILE* outputFile = NULL;
    if(!(outputFile = openOutputFile())) return EXIT_FAILURE;
    assert(outputFile);

    /// +6 дл€ символов новой строки 
    setvbuf(outputFile, NULL, _IOFBF, sizeof(char) * (3 * bufferSize + 6));

    /// дл€ линукса помен€ть
    char divider[3] = "\r\n";

    strings = sortStrings(strings, nStrings, myStrCmpFromBegin);

    DIVIDE
    
    printOnegin(strings, nStrings);

    
    if(!(writeSortedToFIle(outputFile, strings, nStrings, bufferSize))) return EXIT_FAILURE;

    strings = sortStrings(strings, nStrings, myStrCmpFromEnd);

    DIVIDE
    FILE_DIVIDER

    printOnegin(strings, nStrings);

    if(!(writeSortedToFIle(outputFile, strings, nStrings, bufferSize))) return EXIT_FAILURE;

    FILE_DIVIDER

    fwrite(buffer, sizeof(char), bufferSize, outputFile);


    fclose(outputFile);
    free(buffer);
    free(strings);


}