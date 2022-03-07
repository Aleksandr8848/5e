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

    memcpy(beginDestination, beginSource, sizeof(char) * (endSource - beginSource));

    return beginDestination + (endSource - beginSource);
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

bool getWord(char *beginSearch, WordDescriptor *word) {
    word->begin = findNonSpace(beginSearch);

    if (*word->begin == '\0')
        return false;

    word->end = findSpace(word->begin);

    return true;
}

bool getWordReverse(char *rBegin, char *rend, WordDescriptor *word) {
    word->end = findNonSpaceReverse(rBegin, rend);

    if (word->end == rend)
        return false;

    word->begin = findSpaceReverse(word->end, rend);

    return true;
}

