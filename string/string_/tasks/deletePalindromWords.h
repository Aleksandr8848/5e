//
// Created by Admin on 09.03.2022.
//

#ifndef INC_5E_DELETEPALINDROMWORDS_H
#define INC_5E_DELETEPALINDROMWORDS_H

#include "../string_.h"

void deletePalindromeWords(char *s, char *res) {
    if (*s == '\0') {
        *res = '\0';
        return;
    }
    wordDescriptor readWord;
    char *recPtr = res;
    char *readPtr = s;
    int wordCount = 0;
    int palindromeWordsCount = 0;
    while (getWord(readPtr, &readWord)) {
        if (!isWordPalindrome(readWord)) {
            recPtr = copy(readWord.begin, readWord.end, recPtr);
            *recPtr++ = ' ';
        }else
            palindromeWordsCount++;
        readPtr = readWord.end;
        wordCount++;
    }

    if (wordCount == palindromeWordsCount) {
        *recPtr = '\0';
        return;
    }
    if (recPtr != s)
        *--recPtr = '\0';
}

#endif //INC_5E_DELETEPALINDROMWORDS_H
