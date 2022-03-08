//
// Created by Admin on 01.03.2022.
//

#ifndef INC_5E_STRING__H
#define INC_5E_STRING__H

#include "stdio.h"
#include <ctype.h>
#include <stdlib.h>
#include <assert.h>
#include <memory.h>
#include <stdbool.h>

#define MAX_STRING_SIZE 100
#define MAX_N_WORDS_IN_STRING 100
#define MAX_WORD_SIZE 20

typedef struct wordDescriptor {
    char *begin; // позиция начала слова
    char *end; // позиция первого символа, после последнего символа слова
} wordDescriptor;

char _stringBuffer[MAX_STRING_SIZE + 1];

typedef struct BagOfWords {
    wordDescriptor words[MAX_N_WORDS_IN_STRING];
    size_t size;
} BagOfWords;

BagOfWords _bag;
BagOfWords _bag2;

// возвращает количество символов в строке.
size_t strlen_(const char *begin);

// возвращает указатель на первый элемент с кодом ch, расположенным на ленте памяти между
// адресами begin и end не включая end. Если символ не найден, возвращается значение end
char *find(char *begin, char *end, int ch);

//
char *findNonSpace(char *begin);

// возвращает указатель на первый пробельный символ, расположенный на ленте памяти начиная с адреса begin
//или на первый ноль-символ.
char *findSpace(char *begin);

// возвращает указатель на первый справа символ, отличный от пробельных,
// расположенный на ленте памяти, начиная с rbegin (последний символстроки, за которым следует ноль-символ)
// и заканчивая rend (адрес символа перед началом строки). Если символ не найден, возвращается адресrend.
char *findNonSpaceReverse(char *rbegin, const char *rend);

// возвращает указатель на первый пробельный символ справа, расположенный на ленте памяти, начиная с rbegin и заканчивая rend.
// Если символ не найден, возвращается адрес rend.
char *findSpaceReverse(char *rbegin, const char *rend);

// возвращает отрицательное значение, если lhs располагается до rhs
// в лексикографическом порядке (как в словаре), значение 0, если lhs и rhs
// равны, иначе – положительное значение.
int strcmp_(const char *lhs, const char *rhs);

// записывает по адресу beginDestination фрагмент памяти, начиная с адреса beginSource до endSource.
// Возвращает указатель на следующий свободный фрагмент памяти в destination.
char *copy(const char *beginSource, const char *endSource, char *beginDestination);

// записывает по адресу beginDestination элементы из фрагмента памяти начиная с beginSource
// заканчивая endSource, удовлетворяющие функции-предикату f.
// Функция возвращает указатель на следующий свободный для записи фрагмент в памяти.
char *copyIf(char *beginSource, const char *endSource, char *beginDestination, int (*f)(int));

// записывает по адресу beginDestination элементы из фрагмента памяти начиная с rbeginSource заканчивая rendSource, удовлетворяющие функции-предикату f.
// возвращает значение beginDestination по окончанию работы функции.
char *copyIfReverse(char *rbeginSource, const char *rendSource, char *beginDestination, int (*f)(int));

char *getEndOfString(char *begin);

// Функция вернёт значение 0, если слово не было считано, в противном
// случае будет возвращено значение 1 и в переменную word типа wordDescriptor
// будут записаны позиции начала слова, и первого символа после конца слова
bool getWord(char *beginSearch, wordDescriptor *word);

bool getWordReverse(char *rBegin, char *rend, wordDescriptor *word);

// сравнивает два слова, если слова одинаковые возвращает "истина", иначе ложь.
bool areWordsEqual(wordDescriptor w1, wordDescriptor w2);

void getBagOfWords(BagOfWords *bag, char *s);

// выводит слово word
void printWord(wordDescriptor word);

// возвращает указатель на первую запятую, расположенный на ленте памяти начиная с адреса begin
//или на первый ноль-символ.
char *findCommas(char *begin);


char *findNonCommas(char *begin);


bool getWordCommas(char *beginSearch, wordDescriptor *word);

bool isWordPalindrome(wordDescriptor word);
#endif //INC_5E_STRING__H
