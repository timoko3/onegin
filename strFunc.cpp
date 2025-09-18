#include "strFunc.h"

static void myToLower(char* sym);
static void skipPunct(int* curSym, const char* str);

int myStrCmp(const char* leftStr, const char* rightStr){
    assert(leftStr);
    assert(rightStr);
    
    int result = 0;
    int leftCurSymInd = 0, rightCurSymInd = 0;
    while(true){
        
        skipPunct(&leftCurSymInd, leftStr);
        skipPunct(&rightCurSymInd, rightStr);

        // printf("rightStrCur now — %c\n", rightStr[rightCurSymInd]);

        char leftCurSym = leftStr[leftCurSymInd];
        char rightCurSym = rightStr[rightCurSymInd];

        myToLower(&leftCurSym);
        myToLower(&rightCurSym);

        // printf("After myToLower: %c, before: %c\n", leftCurSym, leftStr[leftCurSymInd]);

        if(leftStr[leftCurSymInd] == END_STR && rightStr[rightCurSymInd] == END_STR){
             result = 0;
             break;
        }
        else if(leftStr[leftCurSymInd] != rightStr[rightCurSymInd]){
            result = leftStr[leftCurSymInd] - rightStr[rightCurSymInd];
            break;
        }
        
        leftCurSymInd++;
        rightCurSymInd++;
    }

    return result;
}

string* sortStrings(string* strings, size_t nStrings){
    
    for(size_t i = 0; i < nStrings - 1; i++){
        for(size_t j = i + 1; j < nStrings; j++){
            printf("При сравнении %d и %d strcmp вернуло %d\n", i, j,
                 myStrCmp(strings[i].stringPtr, strings[j].stringPtr));
            if(myStrCmp(strings[i].stringPtr, strings[j].stringPtr) > 0){
                printf("Смена!\n");
                string temp = strings[i];
                strings[i] = strings[j];
                strings[j] = temp;
            }
            
        }
    }
    
    return strings;
}

static void myToLower(char* sym){
    assert(sym);

    if((*sym >= UPPER_SYM_MIN) && (*sym <= UPPER_SYM_MAX)){
        *sym += UPPER_TO_LOWER_SHIFT;
    }
    
}

static void skipPunct(int* curSymInd, const char* str){
    assert(curSymInd);
    assert(str);

    while(true){
        if(ispunct(str[*curSymInd])){
            (*curSymInd)++;
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