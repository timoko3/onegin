#include "strFunc.h"
#include <stdio.h>

int myStrCmp(const char* leftStr, const char* rightStr){
    assert(leftStr);
    assert(rightStr);

    int ch1 = 0, ch2 = 0;

    for(int i = 0; ((ch1 = leftStr[i]) != '\0') && ((ch2 = rightStr[i]) != '\0'); i++){
        printf("ch1 = %d, ch2 = %d", ch1, ch2);
        if(ch1 == ch2) continue;    
        else return ch1 - ch2;
    }

    return 0;
}

