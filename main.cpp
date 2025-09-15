#include <stdio.h>

#include "fileParse.h"
#include "strFunc.h"
#include "UI.h"

int main(void){
    FILE* fp;
    char strings[100][100];

    openFile(&fp);
    getText(fp, strings);

    // временно
    printf("\n%d\n", myStrCmp(strings[0], strings[1]));
    
    fclose(fp);

}