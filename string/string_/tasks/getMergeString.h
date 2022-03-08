//
// Created by Admin on 08.03.2022.
//

#ifndef INC_5E_GETMERGESTRING_H
#define INC_5E_GETMERGESTRING_H

#include "../string_.h"

void getMergeString(char *s1, char *s2, char *res) {
    wordDescriptor word1, word2;
    bool isW1Found, isW2Found;
    char *beginSearch1 = s1, *beginSearch2 = s2;
    while ((isW1Found = getWord(beginSearch1, &word1)),
            (isW2Found = getWord(beginSearch2, &word2)),
            isW1Found || isW2Found) {
        if (isW1Found) {
            res = copy(word1.begin, word1.end, res);
            *res++ = ' ';
            beginSearch1 = word1.end;
        }
        if (isW2Found) {
            res = copy(word2.begin, word2.end, res);
            *res++ = ' ';
            beginSearch2 = word2.end;
        }
    }
    *--res = '\0';
}
#endif //INC_5E_GETMERGESTRING_H
