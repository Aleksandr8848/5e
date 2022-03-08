//
// Created by Admin on 02.03.2022.
//

#ifndef INC_5E_REMOVENONLETTERS_H
#define INC_5E_REMOVENONLETTERS_H

#include "../string_.h"

// удалить из строки все пробельные символы
void removeNonLetters(char *s);

void removeNonLetters(char *s) {
    char *endSource =  getEndOfString(s);
    char *destination = copyIf(s, endSource, s, isgraph);
    *destination = '\0';
}
#endif //INC_5E_REMOVENONLETTERS_H
