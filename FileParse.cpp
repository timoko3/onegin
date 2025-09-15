#include "fileParse.h"

void openFile(FILE** fp){
    assert(fp);

    if(!(*fp = fopen(FILE_NAME, "r"))){
        printf(ALERT_FILE_OPEN_FAILURE, FILE_NAME);
    }

}

void getText(FILE* fp, char strings[][100]){
    assert(fp);
    assert(strings);

    int i = 0;
    while(fgets(strings[i], 100, fp) != NULL){
        printf("%s", strings[i]);
        i++;
    }

    
}

char* myFGets(char* str, int count, FILE* stream){
    assert(str);
    assert(stream);
    if(count < 1)return NULL;

    int i = 0;
    while(i < count){
        int ch = fgetc(stream);
        if(ch == EOF) return NULL;
        
        str[i] = (char) ch;
        i++;
    }
    str[i] = '\0';

    return str;
}
