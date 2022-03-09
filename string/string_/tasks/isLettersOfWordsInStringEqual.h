//
// Created by Admin on 09.03.2022.
//

#ifndef INC_5E_ISLETTERSOFWORDSINSTRINGEQUAL_H
#define INC_5E_ISLETTERSOFWORDSINSTRINGEQUAL_H
#include "../string_.h"
#include "../tasks/stringHaveEqualWords.h"


int compare_char(const void *a, const void *b) {
    char arg1 = *(const char *) a;
    char arg2 = *(const char *) b;
    if (arg1 < arg2) return -1;
    if (arg1 > arg2) return 1;
    return 0;
}

bool isLettersOfWordsInStringEqual(char *s) {
    copy(s, getEndOfString(s) + 1, _stringBuffer);
    char *readPtr = _stringBuffer;
    wordDescriptor w;
    while (getWord(readPtr, &w)) {
        qsort(w.begin, w.end - w.begin, sizeof(char), compare_char);
        readPtr = w.end;
    }
    return isStringHaveEqualWords(_stringBuffer);
}
#endif //INC_5E_ISLETTERSOFWORDSINSTRINGEQUAL_H
