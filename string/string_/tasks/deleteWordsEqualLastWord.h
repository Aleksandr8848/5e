//
// Created by Admin on 09.03.2022.
//

#ifndef INC_5E_DELETEWORDSEQUALLASTWORD_H
#define INC_5E_DELETEWORDSEQUALLASTWORD_H

#include "../string_.h"

void deleteWordsEqualLastWord(char *s, char *res) {
    wordDescriptor lastWord;

    getWordReverse(getEndOfString(s) - 1, s - 1, &lastWord);

    wordDescriptor readWord;
    char *recPtr = res;
    char *readPtr = s;
    while (getWord(readPtr, &readWord)) {
        if (!areWordsEqual(readWord, lastWord)) {
            recPtr = copy(readWord.begin, readWord.end, recPtr);
            *recPtr++ = ' ';
        }
        readPtr = readWord.end;
    }
    recPtr = copy(lastWord.begin, lastWord.end, recPtr);
        *recPtr = '\0';
}
#endif //INC_5E_DELETEWORDSEQUALLASTWORD_H
