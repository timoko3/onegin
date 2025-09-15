#include "UI.h"

/// временная
void printEncoding(){
    int i = -256;
    while(i < 512){
        printf("%c - код %d\n", (char)i, i);
        i++;
    }
}