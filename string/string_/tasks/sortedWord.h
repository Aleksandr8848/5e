//
// Created by Admin on 08.03.2022.
//

#ifndef INC_5E_SORTEDWORD_H
#define INC_5E_SORTEDWORD_H

#include "../string_.h"

bool isSortedWords(char *s) {
    wordDescriptor previousWord;

    if (!getWord(s, &previousWord))
        return true;
    wordDescriptor readWord;
    while (getWord(previousWord.end, &readWord)) {
        if (!areWordsEqual(previousWord, readWord) &&(strcmp_(previousWord.begin, readWord.begin) > 0))
            return false;
        previousWord = readWord;
    }
    return true;
}

#endif //INC_5E_SORTEDWORD_H
