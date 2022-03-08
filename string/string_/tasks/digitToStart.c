//
// Created by Admin on 02.03.2022.
//

#include "digitToStart.h"

void digitToStart(wordDescriptor word) {
    char *endStringBuffer = copy(word.begin, word.end, _stringBuffer);
    char *recPosition = copyIfReverse(endStringBuffer - 1,
                                      _stringBuffer - 1,
                                      word.begin, isdigit);
    copyIf(_stringBuffer, endStringBuffer, recPosition, isalpha);
}

void digitToStartForString(char *s) {
    char *beginSearch = s;
    wordDescriptor word;

    while (getWord(beginSearch, &word)) {
        digitToStart(word);
        beginSearch = word.end;
    }
}

