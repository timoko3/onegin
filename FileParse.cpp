#include "fileParse.h"
#include "strFunc.h"

#include <sys/stat.h>

static int countStrings(char* buf, int fileSize, char endStr);

size_t getFileSize(){
    struct stat file_info;

    if(stat(FILE_NAME, &file_info) != 0){
        fprintf(stderr, "Ошибка при попытке получить информацию о файле\n");
        return 1;
    }

    return file_info.st_size;
}

FILE* openFile(){
    FILE* fp;

    if(!(fp = fopen(FILE_NAME, "rb"))){
        printf(ALERT_FILE_OPEN_FAILURE, FILE_NAME);
    }

    return fp;
}

char** getText(FILE* fp, int fileSize){
    assert(fp);

    printf("Количество символов в файле %s(вернул stat) fileSize: %d\n", FILE_NAME, fileSize);
    char* buffer = (char*) calloc(fileSize, sizeof(char)); 
    assert(buffer);

    fread(buffer, sizeof(char), fileSize, fp);
    printf("Кол-во символов по-настоящему прочитанных из файла: %d\n", myStrLen(buffer));
    /////////////можно улучшить
    int nStrings = countStrings(buffer, fileSize, '\r');
    
    char** strings = (char**) calloc(nStrings, sizeof(char*));
    assert(strings);


    int curStr = 1;
    int i = 0;
    strings[0] = buffer;
    while(i < fileSize){
        if(buffer[i] == '\0'){
            strings[curStr] = buffer + i + 1;
            curStr++;
        }
        i++;
    }

    for(int j = 0; j < nStrings; j++){
        printf("%s", strings[j]);
    }
    

    return strings;
}

static int countStrings(char* buf, int fileSize, char endStr){
    assert(buf);

    int nStrings = 1;

    int i = 0;
    while(i < fileSize){
        if(buf[i] == endStr){
            buf[i] = '\0';
            nStrings++;
        }
        i++;
    }

    return nStrings;
}
