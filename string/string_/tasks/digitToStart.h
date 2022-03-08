//
// Created by Admin on 02.03.2022.
//

#ifndef INC_5E_DIGITTOSTART_H
#define INC_5E_DIGITTOSTART_H

#include "../string_.h"

// преобразовывает строку таким образом, чтобы цифры слова
// были перенесены в начало слова и изменить порядок следования
// цифр в слове на обратный
void digitToStart(wordDescriptor word);

// преобразовывает строку таким образом, чтобы цифры каждого слова
// были перенесены в начало слова и изменить порядок следования
// цифр в слове на обратный
void digitToStartForString(char *s);

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

#endif //INC_5E_DIGITTOSTART_H
