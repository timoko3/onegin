#include "fileParse.h"


#include <sys/stat.h>

static int countStrings(char* buf, int fileSize, char endStr);

size_t getFileSize(){
    struct stat file_info;

    if(stat(FILE_NAME, &file_info) != 0){
        fprintf(stderr, "ќшибка при попытке получить информацию о файле\n");
        return EXIT_FAILURE;
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

char* getTextToBuffer(FILE* fp, int fileSize, int* nStrings){
    assert(fp);
    assert(nStrings);

    printf(" оличество символов в файле %s(вернул stat) fileSize: %d\n", FILE_NAME, fileSize);
    char* buffer = (char*) calloc(fileSize, sizeof(char)); 
    assert(buffer);

    fread(buffer, sizeof(char), fileSize, fp);
    printf(" ол-во символов по-насто€щему прочитанных из файла: %d\n", myStrLen(buffer));
    
    *nStrings = countStrings(buffer, fileSize, END_STR);

    return buffer;
}

string* divideBufferToStruct(char* buffer, int nStrings){
    assert(buffer);

    printf(" ол-во строк Ч %d\n", nStrings);
    printf("ƒлина буфера Ч %d", myStrLen(buffer));

    string* strings = (string*) calloc(nStrings, sizeof(string));
    assert(strings);

    printf("јдрес strings Ч %p\n", strings);

    strings[0].stringPtr = buffer;

    int curStr = 1;
    int i = 0; // rename
    for(i = 0; buffer[i] != '\0'; i++){
        printf("—ейчас символ Ч %d\n", buffer[i]);
        if((buffer[i] == END_STR) && (buffer[i + 1] != '\0')){
            strings[curStr].stringPtr = buffer + i + 1  ;
            
            printf("“екуща€ строкв %d Ч\n", curStr);

            strings[curStr - 1].len = strings[curStr].stringPtr - strings[curStr - 1].stringPtr;
            curStr++;

        }
    }
    printf("curstr Ч %d\n", curStr);
    strings[curStr - 1].len = (buffer + i) - strings[curStr - 1].stringPtr;

    return strings;
}

static int countStrings(char* buf, int fileSize, char endStr){
    assert(buf);

    int nStrings = 1;

    int i = 0;
    while(i < fileSize){
        if(buf[i] == endStr){
            nStrings++;
        }
        i++;
    }

    return nStrings;
}
