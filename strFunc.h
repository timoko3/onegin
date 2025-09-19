#ifndef STR_FUNC_H
#define STR_FUNC_H

#include <ctype.h>
#include <assert.h>
#include <stdio.h>

typedef int (*comparator) (const char* leftstr, const char* rightStr);

struct string {
    char* stringPtr;
    size_t len;
};

const int UPPER_SYM_MIN        = 65;
const int UPPER_SYM_MAX        = 90;
const int UPPER_TO_LOWER_SHIFT = 32;
const int SIZE_OF_END_STR      = 2;

const char END_STR             = '\n';

int myStrCmpFromBegin(const char* leftStr, const char* rightStr);
int myStrCmpFromEnd(const char* leftStr, const char* rightStr);
size_t myStrLen(const char* start, char endStr);
string* sortStrings(string* strings, size_t nStrings, comparator comparatorFunc);

#endif /* STR_FUNC_H */