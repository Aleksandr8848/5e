//
// Created by Admin on 07.03.2022.
//

#ifndef INC_5E_SPACEINSTEADDIGITS_H
#define INC_5E_SPACEINSTEADDIGITS_H

#include "digitToStart.h"

void spaceInsteadDigits(char *s) {
    char *beginBuffer = _stringBuffer;
    char *endBuffer = copy(s, getEndOfString(s), _stringBuffer);
    char *begin = s;

    while (beginBuffer < endBuffer){
        if (isdigit(*beginBuffer)){
            int spaceCount = *beginBuffer - '0';
            for (int i = 0; i < spaceCount; ++i) {
                *begin++ = ' ';
            }
        }else 
            *begin++ = *beginBuffer;

        beginBuffer++;
    }
    *begin = '\0';
}

#endif //INC_5E_SPACEINSTEADDIGITS_H
