//
// Created by Admin on 08.03.2022.
//

#ifndef INC_5E_PRINTWORDSREVERSE_H
#define INC_5E_PRINTWORDSREVERSE_H

#include "../string_.h"

void printWordsReverse(char *s) {
    getBagOfWords(&_bag, s);
    wordDescriptor *endBag = _bag.words + _bag.size - 1;
    while (endBag >= _bag.words) {
        printWord(*endBag);
        endBag--;
    }
}

#endif //INC_5E_PRINTWORDSREVERSE_H
