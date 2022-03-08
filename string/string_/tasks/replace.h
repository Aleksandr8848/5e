//
// Created by Admin on 08.03.2022.
//

#ifndef INC_5E_REPLACE_H
#define INC_5E_REPLACE_H

#include "../string_.h"

void replace(char *source, char *w1, char *w2) {
    size_t w1Size = strlen_(w1);
    size_t w2Size = strlen_(w2);
    wordDescriptor word1 = {w1, w1 + w1Size};
    wordDescriptor word2 = {w2, w2 + w2Size};

    char *readPtr;
    char *recPtr = source;
    if (w1Size >= w2Size) {
        readPtr = source;
    } else {
        copy(source, getEndOfString(source) + 1, _stringBuffer);
        readPtr = _stringBuffer;
    }
    wordDescriptor readWord;
    while (getWord(readPtr, &readWord)) {
        if (areWordsEqual(word1, readWord))
            recPtr = copy(word2.begin, word2.end, recPtr);
        else
            recPtr = copy(readWord.begin, readWord.end, recPtr);

        *recPtr++ = ' ';
        readPtr = readWord.end;
    }
    if (recPtr != source)
        *--recPtr = '\0';
}

#endif //INC_5E_REPLACE_H
