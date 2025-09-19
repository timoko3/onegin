#include "UI.h"

static void myPrintf(string string);

void printOnegin(string* strings, int nStrings){
    assert(strings);

    for(int leftStr = 0; leftStr < nStrings; leftStr++){
        myPrintf(strings[leftStr]);
    }
    
    
}

static void myPrintf(string string){
    
    for(size_t leftStr = 0; leftStr < string.len; leftStr++){
        printf("%c", string.stringPtr[leftStr]);
    }
}