//
// Created by Admin on 08.03.2022.
//

#ifndef INC_5E_PRINTWORDBEFOREFIRSTWORDWITHA_H
#define INC_5E_PRINTWORDBEFOREFIRSTWORDWITHA_H

#include "../string_.h"

typedef enum WordBeforeFirstWordWithAReturnCode {
    FIRST_WORD_WITH_A,
    NOT_FOUND_A_WORD_WITH_A,
    WORD_FOUND,
    EMPTY_STRING
} WordBeforeFirstWordWithAReturnCode;

bool isWordWithA(wordDescriptor w) {
    char *begin = w.begin;
    while (begin < w.end) {
        if (*begin == 'A' || *begin == 'a')
            return true;
        begin++;
    }
    return false;
}

WordBeforeFirstWordWithAReturnCode getWordBeforeFirstWordWithA(char *s, wordDescriptor *wordBefore){
    wordDescriptor previousWord;
    char *begin = s;

    if (!getWord(begin, &previousWord))
        return EMPTY_STRING;

    if (isWordWithA(previousWord))
        return FIRST_WORD_WITH_A;

    wordDescriptor readWord;
    begin = previousWord.end;

    while (getWord(begin, &readWord) && !isWordWithA(readWord)) {
        previousWord = readWord;
        begin = readWord.end;
    }

    if (isWordWithA(readWord)) {
        *wordBefore = previousWord;
        return WORD_FOUND;
    } else
        return NOT_FOUND_A_WORD_WITH_A;
}

void printWordBeforeFirstWordWithA(char *s) {
    wordDescriptor word;
    WordBeforeFirstWordWithAReturnCode code = getWordBeforeFirstWordWithA(s, &word);

    if (code == WORD_FOUND) {
        printWord(word);
    }
}
#endif //INC_5E_PRINTWORDBEFOREFIRSTWORDWITHA_H
