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

        // printf("rightStrCur now Ч %c\n", rightStr[rightCurSymInd]);

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

int myStrCmpFromEnd(const char* leftStr, const char* rightStr){
    assert(leftStr);
    assert(rightStr);

    int result = 0;
    /// -2 дл€ того, чтобы прийти именно к букве(windows)
    int leftCurSymInd = myStrLen(leftStr, '\n') - 2, rightCurSymInd = myStrLen(rightStr, '\n') - 2;

    while(true){
        
        skipPunct(&leftCurSymInd, leftStr, MINUS);
        skipPunct(&rightCurSymInd, rightStr, MINUS);

        // printf("rightStrCur now Ч %c\n", rightStr[rightCurSymInd]);

        char leftCurSym = leftStr[leftCurSymInd];
        char rightCurSym = rightStr[rightCurSymInd];

        myToLower(&leftCurSym);
        myToLower(&rightCurSym);

        // printf("After myToLower: %c, before: %c\n", leftCurSym, leftStr[leftCurSymInd]);

        if(leftCurSymInd == 0 && rightCurSymInd == 0){
             result = 0;
             break;
        }
        else if(leftStr[leftCurSymInd] != rightStr[rightCurSymInd]){
            result = leftStr[leftCurSymInd] - rightStr[rightCurSymInd];
            break;
        }
        
        leftCurSymInd--;
        rightCurSymInd--;
    }

    return result;
}

    


string* sortStrings(string* strings, size_t nStrings, comparator comparatorFunc){
    assert(strings);
    
    for(size_t i = 0; i < nStrings - 1; i++){
        for(size_t j = i + 1; j < nStrings; j++){
            printf("ѕри сравнении %d и %d strcmp вернуло %d\n", i, j,
                 comparatorFunc(strings[i].stringPtr, strings[j].stringPtr));
            if(comparatorFunc(strings[i].stringPtr, strings[j].stringPtr) > 0){
                printf("—мена!\n");
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

size_t myStrLen(const char* start, char endStr){
    assert(start);

    int i = 0;
    while(start[i] != endStr) i++;

    return i;
}