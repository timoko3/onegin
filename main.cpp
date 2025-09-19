#include <stdio.h>
#include <sys\stat.h>

#include "workWithFiles.h"
#include "strFunc.h"
#include "UI.h"

#define DIVIDE printf("\n-----------------------\n");
#define FILE_DIVIDER fwrite(divider, sizeof(char), SIZE_OF_END_STR, outputFile);

int main(void){
    const char divider[] = "\r\n";

    size_t fileSize = 0;
    if((fileSize = getFileSize()) == EXIT_FAILURE) return EXIT_FAILURE;

    FILE* inputFIle = openInputFile();
    if(!inputFIle) return EXIT_FAILURE;
    assert(inputFIle);

    int nStrings = 0;
    char* buffer = getTextToBuffer(inputFIle, fileSize, &nStrings);
    assert(buffer);
    
    fclose(inputFIle);
    
    size_t bufferSize = fileSize + SIZE_OF_END_STR;

    string* strings = divideBufferToStruct(buffer, nStrings);
    assert(strings);

    //  printOnegin(strings, nStrings);
    
    FILE* outputFile = openOutputFile();
    if(!outputFile) return EXIT_FAILURE;
    assert(outputFile);

    setvbuf(outputFile, NULL, _IOFBF, 3 * sizeof(char) * (bufferSize + SIZE_OF_END_STR));

    strings = sortStrings(strings, nStrings, myStrCmpFromBegin);
    //printOnegin(strings, nStrings);
    if(!(writeSortedToFIle(outputFile, strings, nStrings, bufferSize))) return EXIT_FAILURE;

    strings = sortStrings(strings, nStrings, myStrCmpFromEnd);
    DIVIDE
    FILE_DIVIDER
    //printOnegin(strings, nStrings);
    if(!(writeSortedToFIle(outputFile, strings, nStrings, bufferSize))) return EXIT_FAILURE;

    FILE_DIVIDER
    fwrite(buffer, sizeof(char), bufferSize, outputFile);

    fclose(outputFile);
    free(buffer);
    free(strings);

}