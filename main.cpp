#include <stdio.h>
#include <sys\stat.h>

#include "fileParse.h"
#include "strFunc.h"
#include "UI.h"

int main(void){
    FILE* fp;
    char** strings;
    struct stat file_info;

    if(stat(FILE_NAME, &file_info) != 0){
        fprintf(stderr, "Ошибка при попытке получить информацию о файле\n");
        return 1;
    }
    
    

    openFile(&fp);
    getText(fp, strings, file_info.st_size);

    // // временно
    // printf("\n%d\n", myStrCmp(strings[0], strings[1]));
    
    // fclose(fp);

}