#include "string/string_/string_.h"
#include "string/string_/tasks/removeNonLetters.h"
#include "string/string_/tasks/removeExtraSpaces.h"
#include "string/string_/tasks/digitToStart.h"
#include "string/string_/tasks/spaceInsteadDigits.h"
#include "string/string_/tasks/replace.h"
#include "string/string_/tasks/sortedWord.h"
#include "string/string_/tasks/printWordsReverse.h"
#include "string/string_/tasks/getCountPalindromeWords.h"

#define ASSERT_STRING(expected, got) assertString(expected, got, \
 __FILE__, __FUNCTION__, __LINE__)
/*
void test_strlen_string() {
    char str[] = "123qwerty";
    int lenghtStr = 9;

    assert(lenghtStr == strlen_(str));
}

void test_strlen_stringEmpty() {
    char str[] = "";
    int lenghtStr = 0;

    assert(lenghtStr == strlen_(str));
}

void test_strlen_() {
    test_strlen_string();
    test_strlen_stringEmpty();
}

void test_find_firstEl() {
    char str[] = "123qwerty";
    int lenghtStr = 9;
    char *res = &str[0];

    assert(find(str, str + lenghtStr, '1') == res);
}

void test_find_lastEl() {
    char str[] = "123qwerty";
    int lenghtStr = 9;
    char *res = &str[8];

    assert(find(str, str + lenghtStr, 'y') == res);
}

void test_find_stringNoEl() {
    char str[] = "123qwerty";
    int lenghtStr = 9;
    char *res = &str[9];

    assert(find(str, str + lenghtStr, '0') == res);
}

void test_find() {
    test_find_firstEl();
    test_find_lastEl();
    test_find_stringNoEl();
}

void test_findNonSpace_stringWithSpace() {
    char str[] = "  123qwerty";
    char *res = &str[2];

    assert(findNonSpace(str) == res);
}

void test_findNonSpace_stringWithoutSpace() {
    char str[] = "123qwerty";
    char *res = &str[0];

    assert(findNonSpace(str) == res);
}

void test_findNonSpace_stringSpace() {
    char str[] = "   ";
    char *res = &str[3];

    assert(findNonSpace(str) == res);
}

void test_findNonSpace() {
    test_findNonSpace_stringSpace();
    test_findNonSpace_stringWithSpace();
    test_findNonSpace_stringWithoutSpace();
}


void test_findSpace_stringWithoutSpace() {
    char str[] = "123qwerty";
    char *res = &str[9];

    assert(findSpace(str) == res);
}

void test_findSpace_stringWithSpace() {
    char str[] = "123 qwe rty";
    char *res = &str[3];

    assert(findSpace(str) == res);
}

void test_findSpace() {
    test_findSpace_stringWithSpace();
    test_findSpace_stringWithoutSpace();
}

void test_findSpaceReverse_stringWithSpace() {
    char str[] = "123 qwe rty";
    char *res = &str[7];
    int lenghtStr = 11;

    assert(findSpaceReverse(str + lenghtStr - 1, str) == res);
}

void test_findSpaceReverse_stringWithoutSpace() {
    char str[] = "123qwerty";
    char *res = str;
    int lenghtStr = 9;

    assert(findSpaceReverse(str + lenghtStr - 1, str) == res);
}

void test_findSpaceReverse() {
    test_findSpaceReverse_stringWithSpace();
    test_findSpaceReverse_stringWithoutSpace();
}

void test_findNonSpaceReverse_stringWithSpace() {
    char str[] = "     1";
    char *res = &str[5];
    int lenghtStr = 6;

    assert(findNonSpaceReverse(str + lenghtStr - 1, str) == res);
}

void test_findNonSpaceReverse_stringSpace() {
    char str[] = "   ";
    char *res = str;
    int lenghtStr = 3;

    assert(findNonSpaceReverse(str + lenghtStr - 1, str) == res);
}

void test_findNonSpaceReverse() {
    test_findNonSpaceReverse_stringSpace();
    test_findNonSpaceReverse_stringWithSpace();
}

void test_strcmp_stringEqual() {
    char str[] = "123qwerty";
    char res[] = "123qwerty";

    assert(!strcmp_(str, res));
}

void test_strcmp_stringNotEqual() {
    char str[] = "123";
    char res[] = "321";

    assert(strcmp_(str, res));
}

void test_strcmp_() {
    test_strcmp_stringNotEqual();
    test_strcmp_stringEqual();
}

void test_copy_partString() {
    char str[] = "123qwerty";
    int lenghtStr = 9;

    char endStr[] = "qwe";

    char *resBegin = malloc(sizeof(char) * (lenghtStr + 1));

    char *resEnd = copy(&str[3], &str[6], resBegin);
    *resEnd = '\0';

    assert(!strcmp_(endStr, resBegin));

    free(resBegin);
}

void test_copy_fullString() {
    char str[] = "qwerty";
    int lenghtStr = 6;

    char *resBegin = malloc(sizeof(char) * (lenghtStr + 1));

    char *resEnd = copy(str, str + lenghtStr, resBegin);
    *resEnd = '\0';

    assert(!strcmp_(str, resBegin));
    free(resBegin);
}

void test_copy() {
    test_copy_fullString();
    test_copy_partString();
}

int isDigit(int x) {
    return x >= '0' && x <= '9';
}

void test_copyIf_digit() {
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
    test_copyIf_digit();
}

void test_copyIfReverse_digit_stringWithSpace() {
    char str[] = "1 q 2 w 3 e 4";
    int lenghtStr = 13;

    char endStr[] = "4321";

    char *resBegin = malloc(sizeof(char) * (lenghtStr + 1));

    char *resEnd = copyIfReverse(str + lenghtStr, str - 1, resBegin, isDigit);
    *resEnd = '\0';

    assert(!strcmp_(endStr, resBegin));

    free(resBegin);
}

void test_copyIfReverse_digit() {
    char str[] = "qwerty";
    int lenghtStr = 6;

    char endStr[] = "\0";

    char *resBegin = malloc(sizeof(char) * (lenghtStr + 1));

    char *resEnd = copyIfReverse(str + lenghtStr, str, resBegin, isDigit);
    *resEnd = '\0';

    assert(!strcmp_(endStr, resBegin));

    free(resBegin);
}

void test_copyIfReverse() {
    test_copyIfReverse_digit();
    test_copyIfReverse_digit_stringWithSpace();
}

void test_areWordsEqual() {
    char str[] = "qwerty";
    wordDescriptor w1;
    wordDescriptor w2;

    getWord(str, &w1);
    getWord(str, &w2);

    assert(areWordsEqual(w1, w2));
}

void test_function() {
    test_strlen_();

    test_find();
    test_findNonSpace();
    test_findSpace();
    test_findNonSpaceReverse();
    test_findSpaceReverse();

    test_strcmp_();
    test_areWordsEqual();

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

void test_removeNonLetters_stringWithSpace() {
    char str[] = " qw er ty ";

    removeNonLetters(str);

    char res[] = "qwerty";

    ASSERT_STRING(res, str);
}

void test_removeNonLetters_stringSpace() {
    char str[] = "    ";

    removeNonLetters(str);

    char res[] = "";

    ASSERT_STRING(res, str);
}

void test_removeNonLetters() {
    test_removeNonLetters_stringSpace();
    test_removeNonLetters_stringWithSpace();
}

void test_removeExtraSpaces_stringWithExtraSpace() {
    char str[] = "qwerty  123";

    removeExtraSpaces(str);

    char res[] = "qwerty 123";

    ASSERT_STRING(res, str);
}

void test_removeExtraSpaces_stringExtraSpace() {
    char str[] = "        ";

    removeExtraSpaces(str);

    char res[] = " ";

    ASSERT_STRING(res, str);
}

void test_removeExtraSpaces() {
    test_removeExtraSpaces_stringExtraSpace();
    test_removeExtraSpaces_stringWithExtraSpace();
}

void test_digitToStart_oneWord() {
    char str[] = "qwe1rty23";
    wordDescriptor word;

    getWord(str, &word);

    digitToStart(word);

    char res[] = "321qwerty";

    ASSERT_STRING(res, str);
}

void test_digitToStart_twoWord() {
    char str[] = "qwe12 rt3y";
    wordDescriptor word;

    getWord(str, &word);

    digitToStart(word);

    char res[] = "21qwe rt3y";

    ASSERT_STRING(res, str);
}

void test_digitToStart() {
    test_digitToStart_oneWord();
    test_digitToStart_twoWord();
}

void test_digitToStartForString() {
    char str[] = "qwe12 rt3y";

    digitToStartForString(str);

    char res[] = "21qwe 3rty";

    ASSERT_STRING(res, str);
}

void test_spaceInsteadDigits_stringWithDigit() {
    char str[] = "q1w0e2rty";

    spaceInsteadDigits(str);

    char res[] = "q we  rty";

    ASSERT_STRING(res, str);
}

void test_spaceInsteadDigits_stringWithoutDigit() {
    char str[] = "qwerty";

    spaceInsteadDigits(str);

    char res[] = "qwerty";

    ASSERT_STRING(res, str);
}

void test_spaceInsteadDigits_stringDigits() {
    char str[] = "0123";

    spaceInsteadDigits(str);

    char res[] = "      ";

    ASSERT_STRING(res, str);
}

void test_spaceInsteadDigits() {
    test_spaceInsteadDigits_stringWithDigit();
    test_spaceInsteadDigits_stringWithoutDigit();
    test_spaceInsteadDigits_stringDigits();
}

void test_replace() {
    char str[] = "qwe rty";

    replace(str, "rty", "qwe");

    char res[] = "qwe qwe";

    ASSERT_STRING(res, str);
}

void test_sortedWord_isSorted() {
    char str[] = "asd bnv zxc";

    assert(isSortedWords(str) == true);
}

void test_sortedWord_isNotSorted() {
    char str[] = "qwe wasd rty";

    assert(isSortedWords(str) == false);
}

void test_sortedWord_isEqualWords() {
    char str[] = "a a a";

    assert(isSortedWords(str) == true);
}
void test_sortedWord_stringWithEqualWords() {
    char str[] = "b b a";

    assert(isSortedWords(str) == false);
}
void test_sortedWord() {
    test_sortedWord_isSorted();
    test_sortedWord_isNotSorted();
    test_sortedWord_isEqualWords();
    test_sortedWord_stringWithEqualWords();
}
*/
void test_getCountPalindromeWords_stringWithPalindromeWords(){
    char str[] = "aboba, qwerty, qweewq, 1111";

    int res = 3;

    assert(res == getCountPalindromeWords(str));

}
void test_getCountPalindromeWords_stringWithoutPalindromeWords(){
    char str[] = "wasd, qwerty, 1234";

    int res = 0;

    assert(res == getCountPalindromeWords(str));
}

void test_getCountPalindromeWords(){
    test_getCountPalindromeWords_stringWithPalindromeWords();
    test_getCountPalindromeWords_stringWithoutPalindromeWords();
}
void test_tasks() {
//    test_removeExtraSpaces();
//    test_removeNonLetters();
//    test_digitToStart();
//    test_digitToStartForString();
//    test_spaceInsteadDigits();
//    test_replace();
 //   test_sortedWord();
    test_getCountPalindromeWords();
}

int main() {
//    test_function();
    test_tasks();
    return 0;
}
