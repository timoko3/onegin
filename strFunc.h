#include <ctype.h>
#include <assert.h>
#include <stdio.h>

int myStrCmp(const char* leftStr, const char* rightStr);
size_t myStrLen(const char* start);

const int UPPER_SYM_MIN        = 65;
const int UPPER_SYM_MAX        = 90;
const int UPPER_TO_LOWER_SHIFT = 32;


