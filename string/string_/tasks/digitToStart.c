//
// Created by Admin on 02.03.2022.
//

#include "digitToStart.h"

void digitToStart(WordDescriptor word) {
    char *endStringBuffer = copy(word.begin, word.end, stringBuffer_);
    char *recPosition = copyIfReverse(endStringBuffer - 1,
                                      stringBuffer_ - 1,
                                      word.begin, isdigit);
    copyIf(stringBuffer_, endStringBuffer, recPosition, isalpha);
}

void digitToStartForString(char *s) {
    char *beginSearch = s;
    WordDescriptor word;

    while (getWord(beginSearch, &word)) {
        digitToStart(word);
        beginSearch = word.end;
    }
}

