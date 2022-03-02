#include "string/string_/string_.h"
#include "string/string_/tasks/removeNonLetters.h"
#include "string/string_/tasks/removeExtraSpaces.h"
#define ASSERT_STRING(expected, got) assertString(expected, got, \
 __FILE__, __FUNCTION__, __LINE__)

void test_find1() {
    char str[] = "123qwerty";
    int lenghtStr = 9;
    char *res = &str[4];

    assert(find(str, str + lenghtStr, 'w') == res);
}

void test_find2() {
    char str[] = "123qwerty";
    int lenghtStr = 9;
    char *res = &str[8];

    assert(find(str, str + lenghtStr, 'y') == res);
}

void test_find() {
    test_find1();
    test_find2();
}

void test_findNonSpace1() {
    char str[] = "  123qwerty";
    char *res = &str[2];

    assert(findNonSpace(str) == res);
}

void test_findNonSpace2() {
    char str[] = "   ";
    char *res = &str[3];

    assert(findNonSpace(str) == res);
}

void test_findNonSpace() {
    test_findNonSpace1();
    test_findNonSpace2();
}


void test_findSpace1() {
    char str[] = "123qwerty";
    char *res = &str[9];

    assert(findSpace(str) == res);
}

void test_findSpace2() {
    char str[] = "123 qwe rty";
    char *res = &str[3];

    assert(findSpace(str) == res);
}

void test_findSpace() {
    test_findSpace1();
    test_findSpace2();
}

void test_findSpaceReverse1() {
    char str[] = "123 qwe rty";
    char *res = &str[7];
    int lenghtStr = 11;

    assert(findSpaceReverse(str + lenghtStr - 1, str) == res);
}

void test_findSpaceReverse2() {
    char str[] = "123qwerty";
    char *res = str;
    int lenghtStr = 9;

    assert(findSpaceReverse(str + lenghtStr - 1, str) == res);
}

void test_findSpaceReverse() {
    test_findSpaceReverse1();
    test_findSpaceReverse2();
}

void test_findNonSpaceReverse1() {
    char str[] = "     1";
    char *res = &str[5];
    int lenghtStr = 6;

    assert(findNonSpaceReverse(str + lenghtStr - 1, str) == res);
}

void test_findNonSpaceReverse2() {
    char str[] = "   ";
    char *res = str;
    int lenghtStr = 3;

    assert(findNonSpaceReverse(str + lenghtStr - 1, str) == res);
}

void test_findNonSpaceReverse() {
    test_findNonSpaceReverse1();
    test_findNonSpaceReverse2();
}

void test_strcmp1() {
    char str[] = "123qwerty";
    char res[] = "123qwerty";

    assert(!strcmp_(str, res));
}

void test_strcmp2() {
    char str[] = "123";
    char res[] = "321";

    assert(strcmp_(str, res));
}

void test_strcmp_() {
    test_strcmp1();
    test_strcmp2();
}

void test_copy1() {
    char str[] = "123qwerty";
    int lenghtStr = 9;

    char endStr[] = "qwe";

    char *resBegin = malloc(sizeof(char) * (lenghtStr + 1));

    char *resEnd = copy(&str[3], &str[6], resBegin);
    *resEnd = '\0';

    assert(!strcmp_(endStr, resBegin));

    free(resBegin);
}

void test_copy2() {
    char str[] = "qwerty";
    int lenghtStr = 6;

    char *resBegin = malloc(sizeof(char) * (lenghtStr + 1));

    char *resEnd = copy(str, str + lenghtStr, resBegin);
    *resEnd = '\0';

    assert(!strcmp_(str, resBegin));
    free(resBegin);
}

void test_copy() {
    test_copy1();
    test_copy2();
}

int isDigit(int x) {
    return x >= '0' && x <= '9';
}

void test_copyIf1() {
    char str[] = "q1w2e3r4";
    int lenghtStr = 8;

    char endStr[] = "1234";

    char *resBegin = malloc(sizeof(char) * (lenghtStr + 1));

    char *resEnd = copyIf(str, str + lenghtStr, resBegin, isDigit);
    *resEnd = '\0';

    assert(!strcmp_(endStr, resBegin));

    free(resBegin);
}

void test_copyIf2() {
    char str[] = "1qwe123rty1";
    int lenghtStr = 11;

    char endStr[] = "11231";

    char *resBegin = malloc(sizeof(char) * (lenghtStr + 1));

    char *resEnd = copyIf(str, str + lenghtStr, resBegin, isDigit);
    *resEnd = '\0';

    assert(!strcmp_(endStr, resBegin));

    free(resBegin);
}

void test_copyIf() {
    test_copyIf1();
    test_copyIf2();
}

void test_copyIfReverse1() {
    char str[] = "1 q 2 w 3 e 4";
    int lenghtStr = 13;

    char endStr[] = "4321";

    char *resBegin = malloc(sizeof(char) * (lenghtStr + 1));

    char *resEnd = copyIfReverse(str + lenghtStr, str - 1, resBegin, isDigit);
    *resEnd = '\0';

    assert(!strcmp_(endStr, resBegin));

    free(resBegin);
}

void test_copyIfReverse2() {
    char str[] = "qwerty";
    int lenghtStr = 11;

    char endStr[] = "\0";

    char *resBegin = malloc(sizeof(char) * (lenghtStr + 1));

    char *resEnd = copyIfReverse(str + lenghtStr, str, resBegin, isDigit);
    *resEnd = '\0';

    assert(!strcmp_(endStr, resBegin));

    free(resBegin);
}

void test_copyIfReverse() {
    test_copyIfReverse1();
    test_copyIfReverse2();
}

void test_function() {
    test_find();
    test_findNonSpace();
    test_findSpace();
    test_findNonSpaceReverse();
    test_findSpaceReverse();

    test_strcmp_();

    test_copy();
    test_copyIf();
    test_copyIfReverse();
}

void assertString(const char *expected, char *got,
                  char const *fileName, char const *funcName, int line) {
    if (strcmp_(expected, got)) {
        fprintf(stderr, "File %s\n", fileName);
        fprintf(stderr, "%s - failed on line %d\n", funcName, line);
        fprintf(stderr, "Expected: \"%s\"\n", expected);
        fprintf(stderr, "Got: \"%s\"\n\n", got);
    } else
        fprintf(stderr, "%s - OK\n", funcName);
}
void test_removeNonLetters1() {
    char str[] = " qw er ty ";

    removeNonLetters(str);

    char res[] = "qwerty";

    ASSERT_STRING(res, str);
}

void test_removeNonLetters2() {
    char str[] = "    ";

    removeNonLetters(str);

    char res[] = "";

    ASSERT_STRING(res, str);
}

void test_removeNonLetters() {
    test_removeNonLetters1();
    test_removeNonLetters2();
}
void test_removeExtraSpaces1() {
    char str[] = "qwerty  123";

    removeExtraSpaces(str);

    char res[] = "qwerty 123";

    ASSERT_STRING(res, str);
}

void test_removeExtraSpaces2() {
    char str[] = " qwe  rty 123 ";

    removeExtraSpaces(str);

    char res[] = " qwe rty 123 ";

    ASSERT_STRING(res, str);
}

void test_removeExtraSpaces() {
    test_removeExtraSpaces1();
    test_removeExtraSpaces2();
}
void test_tasks(){
    test_removeExtraSpaces();
    test_removeNonLetters();
}
int main() {
    test_function();
    test_tasks();
    return 0;
}
