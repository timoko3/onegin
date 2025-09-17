#include <stdio.h>
#include <sys\stat.h>

#include "fileParse.h"
#include "strFunc.h"
#include "UI.h"

int main(void){

    size_t fileSize = getFileSize();

    FILE* fp = openFile();
    assert(fp);

    int nStrings = 0;

    char* buffer = getTextToBuffer(fp, fileSize, &nStrings);
    assert(buffer);
    
    string* strings = divideBufferToStruct(buffer, nStrings);
    assert(strings);

    for(int i = 0; i < nStrings; i++){
        printf("%d строка Ч %s ее длина %d, ee адрес Ч %p\n", i,  strings[i].stringPtr, strings[i].len, strings[i].stringPtr);
    }

    free(buffer);
    free(strings);

    fclose(fp);
}