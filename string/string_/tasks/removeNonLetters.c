//
// Created by Admin on 02.03.2022.
//

#include "removeNonLetters.h"

char *getEndOfString(char *begin){
    while(*begin != '\0')
        begin++;
    return begin;
}
void removeNonLetters(char *s) {
    char *endSource =  getEndOfString(s);
    char *destination = copyIf(s, endSource, s, isgraph);
    *destination = '\0';
}