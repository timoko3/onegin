#include "strFunc.h"

static void myToLower(char* sym);
static void skipPunct(int* curSym, const char* str, bool sign);

#define PLUS true
#define MINUS false

int myStrCmpFromBegin(const char* leftStr, const char* rightStr){
    assert(leftStr);
    assert(rightStr);
    
    int result = 0;
    int leftCurSymInd = 0, rightCurSymInd = 0;
    while(true){
        
        skipPunct(&leftCurSymInd, leftStr, PLUS);
        skipPunct(&rightCurSymInd, rightStr, PLUS);

        char leftCurSym = leftStr[leftCurSymInd];
        char rightCurSym = rightStr[rightCurSymInd];

        myToLower(&leftCurSym);
        myToLower(&rightCurSym);

        if(leftCurSym == END_STR && rightCurSym == END_STR){
             result = 0;
             break;
        }
        else if(leftCurSym != rightCurSym){
            result = leftCurSym - rightCurSym;
            break;
        }
        
        leftCurSymInd++;
        rightCurSymInd++;
    }

    return result;
}

int myStrCmpFromEnd(const char* leftStr, const char* rightStr){
    assert(leftStr);
    assert(rightStr);

    int result = 0;
    
    int leftCurSymInd = myStrLen(leftStr, '\n') - SIZE_OF_END_STR, 
        rightCurSymInd = myStrLen(rightStr, '\n') - SIZE_OF_END_STR;

    while(true){
        
        skipPunct(&leftCurSymInd, leftStr, MINUS);
        skipPunct(&rightCurSymInd, rightStr, MINUS);

        char leftCurSym = leftStr[leftCurSymInd];
        char rightCurSym = rightStr[rightCurSymInd];

        myToLower(&leftCurSym);
        myToLower(&rightCurSym);

        if(leftCurSymInd == 0 && rightCurSymInd == 0){
             result = 0;
             break;
        }
        else if(leftCurSym != rightCurSym){
            result = leftCurSym - rightCurSym;
            break;
        }
        
        leftCurSymInd--;
        rightCurSymInd--;
    }

    return result;
}

string* sortStrings(string* strings, size_t nStrings, comparator comparatorFunc){
    assert(strings);
    
    for(size_t leftStrInd = 0; leftStrInd < nStrings - 1; leftStrInd++){
        for(size_t rightStrInd = leftStrInd + 1; rightStrInd < nStrings; rightStrInd++){
            if(comparatorFunc(strings[leftStrInd].stringPtr, strings[rightStrInd].stringPtr) > 0){
                string temp = strings[leftStrInd];
                strings[leftStrInd] = strings[rightStrInd];
                strings[rightStrInd] = temp;
            }
            
        }
    }
    
    return strings;
}

size_t myStrLen(const char* start, char endStr){
    assert(start);

    int curSymInd = 0;
    while(start[curSymInd] != endStr) curSymInd++;

    return curSymInd;
}

static void myToLower(char* sym){
    assert(sym);

    if((*sym >= UPPER_SYM_MIN) && (*sym <= UPPER_SYM_MAX)){
        *sym += UPPER_TO_LOWER_SHIFT;
    }
    
}

static void skipPunct(int* curSymInd, const char* str, bool sign){
    assert(curSymInd);
    assert(str);

    while(true){
        if(ispunct(str[*curSymInd])){
            if(sign){
                (*curSymInd)++;
            }
            else{
                (*curSymInd)--;
            }
        }
        else{
            break;
        }
    }

}

