#include <stdio.h>

#include "fileParse.h"
#include "strFunc.h"

int main(void){
    FILE* fp;
    openFile(&fp);
    char strings[1000][1000];
    getText(fp, strings);
    // sort();
    // exportText();
    printf("%d", myStrCmp(strings[0], strings[1]));
    printf("%d", myStrCmp(strings[0], strings[1]));
    
    fclose(fp);

}