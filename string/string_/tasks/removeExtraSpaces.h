//
// Created by Admin on 02.03.2022.
//

#ifndef INC_5E_REMOVEEXTRASPACES_H
#define INC_5E_REMOVEEXTRASPACES_H

#include "../string_.h"

// Сокращает количество пробелов между словами данного предложения до одного
void removeExtraSpaces(char *s);

void removeExtraSpaces(char *s){
    if(*s == '\0')
        return;
    char *lastSymbol = s;
    s++;

    while (*s){
        if(!(isspace(*lastSymbol) && isspace(*s))){
            lastSymbol++;
            *lastSymbol = *s;
        }
        s++;
    }
    lastSymbol++;
    *lastSymbol = '\0';
}
#endif //INC_5E_REMOVEEXTRASPACES_H
