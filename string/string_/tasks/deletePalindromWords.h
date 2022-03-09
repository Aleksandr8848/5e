//
// Created by Admin on 09.03.2022.
//

#ifndef INC_5E_DELETEPALINDROMWORDS_H
#define INC_5E_DELETEPALINDROMWORDS_H

#include "../string_.h"

void deletePalindromeWords(char *s, char *res) {
    wordDescriptor readWord;
    char *recPtr = res;
    char *readPtr = s;
    while (getWord(readPtr, &readWord)) {
        if (!isWordPalindrome(readWord)) {
            recPtr = copy(readWord.begin, readWord.end, recPtr);
            *recPtr++ = ' ';
        }
        readPtr = readWord.end;
    }
    if (recPtr != s)
    *--recPtr = '\0';
}
#endif //INC_5E_DELETEPALINDROMWORDS_H
