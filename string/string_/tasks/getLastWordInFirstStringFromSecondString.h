//
// Created by Admin on 09.03.2022.
//

#ifndef INC_5E_GETLASTWORDINFIRSTSTRINGFROMSECONDSTRING_H
#define INC_5E_GETLASTWORDINFIRSTSTRINGFROMSECONDSTRING_H

#include "../string_.h"

bool getLastWordInFirstStringFromSecondString(char *s1, char *s2, wordDescriptor *resWord) {

    if (*s1 == '\0' && *s2 == '\0')
        return false;

    getBagOfWords(&_bag, s2);
    char *readPtr = getEndOfString(s1);
    wordDescriptor *_bagEnd = _bag.size + _bag.words;
    wordDescriptor readWord;
    while (getWordReverse(readPtr - 1, s1 - 1, &readWord)) {
        for (wordDescriptor *readBag = _bag.words; readBag < _bagEnd; readBag++) {
            if (areWordsEqual(readWord, *readBag)) {
                *resWord = readWord;
                return true;
            }
        }
        readPtr = readWord.end;
    }
    return false;
}

#endif //INC_5E_GETLASTWORDINFIRSTSTRINGFROMSECONDSTRING_H
