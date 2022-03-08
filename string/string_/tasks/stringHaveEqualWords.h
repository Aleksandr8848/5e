//
// Created by Admin on 09.03.2022.
//

#ifndef INC_5E_STRINGHAVEEQUALWORDS_H
#define INC_5E_STRINGHAVEEQUALWORDS_H

#include "digitToStart.h"

bool isStringHaveEqualWords(char *s) {
    char *begin = s;
    wordDescriptor currentWord;
    while (getWord(begin, &currentWord)) {
        begin = currentWord.end;
        char *readBegin = currentWord.end;
        wordDescriptor readWord;
        while (getWord(readBegin, &readWord)) {
            if (areWordsEqual(currentWord, readWord))
                return true;
            readBegin = readWord.end;
        }
    }
    return false;
}

#endif //INC_5E_STRINGHAVEEQUALWORDS_H
