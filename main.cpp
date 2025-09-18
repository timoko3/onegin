#include <stdio.h>
#include <sys\stat.h>

#include "fileParse.h"
#include "strFunc.h"
#include "UI.h"

#define DIVIDE printf("\n");

int main(void){

    size_t fileSize = 0;
    if((fileSize = getFileSize()) == EXIT_FAILURE) return EXIT_FAILURE;

    FILE* fp = openFile();
    assert(fp);

    int nStrings = 0;

    char* buffer = getTextToBuffer(fp, fileSize, &nStrings);
    assert(buffer);
    
    string* strings = divideBufferToStruct(buffer, nStrings);
    assert(strings);

    printOnegin(strings, nStrings);
    // printf("–езультат myStrCmp Ч %d\n", myStrCmp(strings[0].stringPtr, strings[1].stringPtr));
    
    strings = sortStrings(strings, nStrings);

    printf("\n-----------------------\n");
    
    printOnegin(strings, nStrings);
    

    free(buffer);
    free(strings);

    fclose(fp);
}