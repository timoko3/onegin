#include "UI.h"

static void myPrintf(string string);

void printOnegin(string* strings, int nStrings){
    assert(strings);

    for(int i = 0; i < nStrings; i++){
        myPrintf(strings[i]);
    }
    
    
}

static void myPrintf(string string){
    
    for(size_t i = 0; i < string.len; i++){
        printf("%c", string.stringPtr[i]);
    }
}