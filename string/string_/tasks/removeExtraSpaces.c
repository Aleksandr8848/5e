//
// Created by Admin on 02.03.2022.
//

#include "removeExtraSpaces.h"

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