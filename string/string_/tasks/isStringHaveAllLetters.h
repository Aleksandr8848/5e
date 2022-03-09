//
// Created by Admin on 09.03.2022.
//

#ifndef INC_5E_ISSTRINGHAVEALLLETTERS_H
#define INC_5E_ISSTRINGHAVEALLLETTERS_H

#include "../string_.h"

bool isStringHaveAllLetters(char *s,wordDescriptor w){
    bool strElements[MAX_STRING_SIZE] = {false};
    char *begin = s;
    char *end = getEndOfString(begin);
    while (begin < end) {
        if (isalpha(*begin))
            strElements[*begin - 'a'] = true;
        begin++;
    }

    begin = w.begin;
    end = w.end;
    while (begin < end) {
        if (isalpha(*begin) && (strElements[*begin - 'a'] == false))
            return false;
        begin++;
    }

    return true;
}
#endif //INC_5E_ISSTRINGHAVEALLLETTERS_H
