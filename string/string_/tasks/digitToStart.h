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
#endif //INC_5E_DIGITTOSTART_H
