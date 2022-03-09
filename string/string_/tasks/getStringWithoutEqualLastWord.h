//
// Created by Admin on 09.03.2022.
//

#ifndef INC_5E_GETSTRINGWITHOUTEQUALLASTWORD_H
#define INC_5E_GETSTRINGWITHOUTEQUALLASTWORD_H

#include "../string_.h"

void getStringWithoutEqualLastWord(char *s, char *res) {
    wordDescriptor lastWord;

    if(!getWordReverse(getEndOfString(s) - 1, s - 1, &lastWord)){
        *res = '\0';
        return;
    }

    wordDescriptor readWord;

    char *readPtr = s;
    while (getWord(readPtr, &readWord)) {
        if (!areWordsEqual(readWord, lastWord)) {
            res = copy(readWord.begin, readWord.end, res);
            *res++ = ' ';
        }
        readPtr = readWord.end;
    }
    res = copy(lastWord.begin, lastWord.end, res);
        *res = '\0';
}

#endif //INC_5E_GETSTRINGWITHOUTEQUALLASTWORD_H
