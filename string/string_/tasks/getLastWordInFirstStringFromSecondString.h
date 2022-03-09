//
// Created by Admin on 09.03.2022.
//

#ifndef INC_5E_GETLASTWORDINFIRSTSTRINGFROMSECONDSTRING_H
#define INC_5E_GETLASTWORDINFIRSTSTRINGFROMSECONDSTRING_H
#include "../string_.h"

bool getLastWordInFirstStringFromSecondString(char *s1, char *s2,wordDescriptor *resWord) {
    getBagOfWords(&_bag, s2);
    char *readPtr = getEndOfString(s1);

    wordDescriptor readWord;
    while (getWordReverse(readPtr, s1 - 1, &readWord)) {
        for (wordDescriptor *readBag = _bag.words; readBag < _bag.size + _bag.words; readBag++) {
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
