#include "strFunc.h"

static int myToLower(int* sym);
static void skipPunct(int* ch1, int* ch2, int i, int j, const char* leftStr, const char* rightStr);

int myStrCmp(const char* leftStr, const char* rightStr){
    assert(leftStr);
    assert(rightStr);

    while(true){
        int i = 0, j = 0;
        int ch1 = leftStr[j];
        int ch2 = rightStr[i];
    
        skipPunct(&ch1, &ch2, i, j, leftStr, rightStr);

        myToLower(&ch1);
        myToLower(&ch2);

        if(ch1 == '\0' && ch2 == '\0') return 0;
        else if(ch1 == ch2) continue;    
        else return ch1 - ch2;
        
        i++;
        j++;
    }


}

static int myToLower(int* sym){
    assert(sym);

    if((*sym >= UPPER_SYM_MIN) && (*sym <= UPPER_SYM_MAX)){
        return *sym + UPPER_TO_LOWER_SHIFT;
    }
    
    return *sym;
}

static void skipPunct(int* ch1, int* ch2, int i, int j, const char* leftStr, const char* rightStr){
    assert(leftStr);
    assert(rightStr);

    while(true){
        if(ispunct(*ch1)){
            j++;
            *ch1 = leftStr[j];
        }
        else if(ispunct(*ch2)){
            i++;
            *ch2 = rightStr[i];
        }
        else{
            break;
        }
    }
}

size_t myStrLen(const char* start){
    assert(start);

    int i = 0;
    while(start[i] != '\0') i++;

    return i;
}