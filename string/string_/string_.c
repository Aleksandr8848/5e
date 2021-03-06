//
// Created by Admin on 01.03.2022.
//

#include "string_.h"

size_t strlen_(const char *begin) {
    char *end = begin;
    while (*end != '\0')
        end++;
    return end - begin;
}

char *find(char *begin, char *end, int ch) {
    while (begin != end && *begin != ch)
        begin++;

    return begin;
}

char *findNonSpace(char *begin) {
    while (isspace(*begin) && *begin != '\0')
        begin++;

    return begin;
}

char *findSpace(char *begin) {
    while (!isspace(*begin) && *begin != '\0')
        begin++;

    return begin;
}

char *findNonSpaceReverse(char *rbegin, const char *rend) {
    while (isspace(*rbegin) && rbegin != rend)
        rbegin--;

    return rbegin;
}

char *findSpaceReverse(char *rbegin, const char *rend) {
    while (!isspace(*rbegin) && rbegin != rend)
        rbegin--;

    return rbegin;
}

int strcmp_(const char *lhs, const char *rhs) {
    while (*lhs == *rhs && *rhs != '\0') {
        lhs++;
        rhs++;
    }
    return *lhs - *rhs;
}

char *copy(const char *beginSource, const char *endSource, char *beginDestination) {
    size_t size = endSource - beginSource;
    memcpy(beginDestination, beginSource, size);

    return beginDestination + size;
}

char *copyIf(char *beginSource, const char *endSource, char *beginDestination, int (*f)(int)) {
    while (beginSource < endSource) {
        if (f(*beginSource)) {
            *beginDestination = *beginSource;
            beginDestination++;
        }
        beginSource++;
    }
    return beginDestination;
}

char *copyIfReverse(char *rBeginSource, const char *rendSource, char *beginDestination, int (*f)(int)) {
    while (rBeginSource > rendSource) {
        if (f(*rBeginSource)) {
            *beginDestination = *rBeginSource;
            beginDestination++;
        }
        rBeginSource--;
    }
    return beginDestination;
}

char *getEndOfString(char *begin) {
    while (*begin != '\0')
        begin++;
    return begin;
}

bool getWord(char *beginSearch, wordDescriptor *word) {
    word->begin = findNonSpace(beginSearch);

    if (*word->begin == '\0')
        return false;

    word->end = findSpace(word->begin);

    return true;
}

bool getWordReverse(char *rBegin, char *rend, wordDescriptor *word) {
    word->end = findNonSpaceReverse(rBegin, rend);

    if (word->end == rend)
        return false;

    word->begin = findSpaceReverse(word->end, rend);
    word->end++;
    word->begin++;
    return true;
}

bool areWordsEqual(wordDescriptor w1, wordDescriptor w2) {
    if (w1.end - w1.begin != w2.end - w2.begin)
        return false;
    return !memcmp(w1.begin, w2.begin, w1.end - w1.begin);
}

void getBagOfWords(BagOfWords *bag, char *s) {
    wordDescriptor readW;
    wordDescriptor *readWs = bag->words;
    size_t size = 0;
    while (getWord(s, &readW)) {
        readWs->begin = readW.begin;
        readWs->end = readW.end;
        readWs++;
        size++;
        s = readW.end;
    }
    bag->size = size;
}

void printWord(wordDescriptor word) {
    char *end = word.end;
    for (char *i = word.begin; i < end; ++i)
        printf("%c", *i);
    printf("\n");
}

char *findCommas(char *begin) {
    while (*begin != '\0' && *begin != ',')
        begin++;
    return begin;
}

char *findNonCommas(char *begin) {
    while (*begin == ',')
        begin++;
    return begin;
}

bool getWordCommas(char *beginSearch, wordDescriptor *word) {
    word->begin = findNonSpace(beginSearch);
    if (*word->begin == '\0')
        return false;

    word->end = findCommas(word->begin);
    return true;
}

bool isWordPalindrome(wordDescriptor word) {
    char *left = word.begin;
    char *right = word.end - 1;

    while (left < right) {
        if (*left != *right)
            return false;

        left++;
        right--;
    }

    return true;
}
