#include <stdio.h>
#include <sys\stat.h>

#include "fileParse.h"
#include "strFunc.h"
#include "UI.h"

int main(void){

    
    size_t fileSize = getFileSize();

    FILE* fp = openFile();
    assert(fp);

    char** strings = getText(fp, fileSize);
    assert(strings);
    

    free(strings[0]);
    strings[0] = NULL;
    free(strings);
    strings = NULL;

    fclose(fp);
}