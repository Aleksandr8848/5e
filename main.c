#include "string/string_/string_.h"
#include "string/string_/tasks/removeNonLetters.h"
#include "string/string_/tasks/removeExtraSpaces.h"
#include "string/string_/tasks/digitToStart.h"
#include "string/string_/tasks/spaceInsteadDigits.h"
#include "string/string_/tasks/replace.h"
#include "string/string_/tasks/sortedWord.h"
#include "string/string_/tasks/printWordsReverse.h"
#include "string/string_/tasks/getCountPalindromeWords.h"
#include "string/string_/tasks/getMergeString.h"
#include "string/string_/tasks/printWordBeforeFirstWordWithA.h"
#include "string/string_/tasks/stringHaveEqualWords.h"
#include "string/string_/tasks/getStringWithoutEqualLastWord.h"
#include "string/string_/tasks/deletePalindromWords.h"
#include "string/string_/tasks/getLastWordInFirstStringFromSecondString.h"
#include "string/string_/tasks/isLettersOfWordsInStringEqual.h"
#include "string/string_/tasks/isStringHaveAllLetters.h"

#define ASSERT_STRING(expected, got) assertString(expected, got, \
 __FILE__, __FUNCTION__, __LINE__)

void wordDescriptorToString(wordDescriptor word, char *destination) {
    for (; word.begin < word.end; word.begin++)
        *(destination++) = *word.begin;

    *destination = '\0';
}

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

void test_areWordsEqual_equalWord() {
    char str[] = "qwerty";
    wordDescriptor w1;
    wordDescriptor w2;

    getWord(str, &w1);
    getWord(str, &w2);

    assert(areWordsEqual(w1, w2));
}

void test_areWordsEqual_notEqualWord() {
    char str[] = "qwerty";
    wordDescriptor w1;
    wordDescriptor w2;

    getWord(str, &w1);
    getWord(str + 1, &w2);

    assert(!areWordsEqual(w1, w2));
}

void test_areWordsEqual() {
    test_areWordsEqual_equalWord();
    test_areWordsEqual_notEqualWord();
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

void test_replace_W1SizeMoreW2Size() {
    char str[] = "qwerty";

    replace(str, "qwerty", "qwe");

    char res[] = "qwe";

    ASSERT_STRING(res, str);
}

void test_replace_W1SizeLessW2Size() {
    char str[] = "qwe";

    replace(str, "qwe", "qwerty");

    char res[] = "qwerty";

    ASSERT_STRING(res, str);
}

void test_replace() {
    test_replace_W1SizeMoreW2Size();
    test_replace_W1SizeLessW2Size();
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

void test_getCountPalindromeWords_stringWithPalindromeWords() {
    char str[] = "aboba, qwerty, qweewq, 1111";

    int res = 3;

    assert(res == getCountPalindromeWords(str));

}

void test_getCountPalindromeWords_stringWithoutPalindromeWords() {
    char str[] = "wasd, qwerty, 1234";

    int res = 0;

    assert(res == getCountPalindromeWords(str));
}

void test_getCountPalindromeWords() {
    test_getCountPalindromeWords_stringWithPalindromeWords();
    test_getCountPalindromeWords_stringWithoutPalindromeWords();
}

void test_getMergeString_equalWordsCount() {
    char str1[] = "eee have nine";
    char str2[] = "i done task";

    char merge[MAX_STRING_SIZE];

    getMergeString(str1, str2, merge);

    char res[] = "eee i have done nine task";

    ASSERT_STRING(res, merge);
}

void test_getMergeString_notEqualWordsCount() {
    char str1[] = "oh ten more tasks";
    char str2[] = "no";

    char merge[MAX_STRING_SIZE];

    getMergeString(str1, str2, merge);

    char res[] = "oh no ten more tasks";

    ASSERT_STRING(res, merge);
}

void test_getMergeString() {
    test_getMergeString_equalWordsCount();
    test_getMergeString_notEqualWordsCount();

}

void testAll_getWordBeforeFirstWordWithA() {
    wordDescriptor word;

    char s1[] = "";
    assert(getWordBeforeFirstWordWithA(s1, &word) == EMPTY_STRING);

    char s2[] = "ABC";
    assert(getWordBeforeFirstWordWithA(s2, &word) == FIRST_WORD_WITH_A);

    char s3[] = "BC A";
    assert(getWordBeforeFirstWordWithA(s3, &word) == WORD_FOUND);
    char got[MAX_WORD_SIZE];
    copy(word.begin, word.end, got);
    got[word.end - word.begin] = '\0';
    ASSERT_STRING("BC", got);

    char s4[] = "B Q WE YR OW IUWR";
    assert(getWordBeforeFirstWordWithA(s4, &word) == NOT_FOUND_A_WORD_WITH_A);
}

void test_isStringHaveEqualWords_withEqualWords() {
    char str[] = "wasd 1234 wasd";

    assert(isStringHaveEqualWords(str) == true);
}

void test_isStringHaveEqualWords_withoutEqualWords() {
    char str[] = "wasd 1234 qwerty";

    assert(isStringHaveEqualWords(str) == false);
}

void test_isStringHaveEqualWords_emptyString() {
    char str[] = "";

    assert(isStringHaveEqualWords(str) == false);
}

void test_isStringHaveEqualWords() {
    test_isStringHaveEqualWords_withEqualWords();
    test_isStringHaveEqualWords_withoutEqualWords();
    test_isStringHaveEqualWords_emptyString();
}

void test_getStringWithoutEqualLastWord_withEqualLastWord() {
    char str[] = "1 2 3 1";
    char s[MAX_STRING_SIZE + 1];
    getStringWithoutEqualLastWord(str, s);

    char res[MAX_STRING_SIZE + 1] = "2 3 1";

    ASSERT_STRING(res, s);
}

void test_getStringWithoutEqualLastWord_withoutEqualLastWord() {
    char str[] = "qw er ty";
    char s[MAX_STRING_SIZE + 1];
    getStringWithoutEqualLastWord(str, s);

    char res[] = "qw er ty";

    ASSERT_STRING(res, s);
}

void test_getStringWithoutEqualLastWord_EqualWords() {
    char str[] = "1 1 1 1";
    char s[MAX_STRING_SIZE + 1];
    getStringWithoutEqualLastWord(str, s);

    char res[MAX_STRING_SIZE + 1] = "1";

    ASSERT_STRING(res, s);
}

void test_getStringWithoutEqualLastWord_EmptyString() {
    char str[] = "";
    char s[MAX_STRING_SIZE + 1];
    getStringWithoutEqualLastWord(str, s);

    char res[MAX_STRING_SIZE + 1] = "";

    ASSERT_STRING(res, s);
}

void test_getStringWithoutEqualLastWord() {
    test_getStringWithoutEqualLastWord_withEqualLastWord();
    test_getStringWithoutEqualLastWord_withoutEqualLastWord();
    test_getStringWithoutEqualLastWord_EqualWords();
    test_getStringWithoutEqualLastWord_EmptyString();
}

void test_deletePalindromeWords_stringWithPalindromeWords() {
    char str[] = "121 qweewq 123";
    char s[MAX_STRING_SIZE + 1];
    deletePalindromeWords(str, s);

    char res[MAX_STRING_SIZE + 1] = "123";

    ASSERT_STRING(res, s);
}

void test_deletePalindromeWords_stringWithoutPalindromeWords() {
    char str[] = "qw er ty";
    char s[MAX_STRING_SIZE + 1];
    deletePalindromeWords(str, s);

    char res[] = "qw er ty";

    ASSERT_STRING(res, s);
}

void test_deletePalindromeWords_stringAllPalindromeWords() {
    char str[] = "121 qweewq 11";
    char s[MAX_STRING_SIZE + 1];
    deletePalindromeWords(str, s);

    char res[MAX_STRING_SIZE + 1] = "";

    ASSERT_STRING(res, s);
}

void test_deletePalindromeWords_Emptystring() {
    char str[] = "";
    char s[MAX_STRING_SIZE + 1];
    deletePalindromeWords(str, s);

    char res[MAX_STRING_SIZE + 1] = "";

    ASSERT_STRING(res, s);
}

void test_deletePalindromeWords() {
    test_deletePalindromeWords_stringWithPalindromeWords();
    test_deletePalindromeWords_stringWithoutPalindromeWords();
    test_deletePalindromeWords_stringAllPalindromeWords();
    test_deletePalindromeWords_Emptystring();
}

void test_getLastWordInFirstStringFromSecondString_emptyStr1() {
    char str1[] = "";
    char str2[] = "qwerty wasd 123";

    wordDescriptor w;

    bool res = getLastWordInFirstStringFromSecondString(str1, str2, &w);

    assert(false == res);

    printf("test_getLastWordInFirstStringFromSecondString_emptyStr1 - OK\n");
}

void test_getLastWordInFirstStringFromSecondString_withWordInStr1AndStr2() {
    char str1[] = "12 34 qwerty";
    char str2[] = "qwerty wasd 123";

    wordDescriptor w;

    bool res = getLastWordInFirstStringFromSecondString(str1, str2, &w);

    assert(true == res);

    char got[MAX_STRING_SIZE];
    wordDescriptorToString(w, got);

    char resWord[] = "qwerty";

    ASSERT_STRING(resWord, got);
}


void test_getLastWordInFirstStringFromSecondString() {
    test_getLastWordInFirstStringFromSecondString_withWordInStr1AndStr2();
    test_getLastWordInFirstStringFromSecondString_emptyStr1();
}

void test_isLettersOfWordsInStringEqual_isEqualLetters() {
    char s[MAX_STRING_SIZE + 1] = "qwe weq";

    assert(isLettersOfWordsInStringEqual(s) == true);
}


void test_isLettersOfWordsInStringEqual_isNotEqualLetters() {
    char s[MAX_STRING_SIZE + 1] = "wasd qwerty";

    assert(isLettersOfWordsInStringEqual(s) == false);
}

void test_isLettersOfWordsInStringEqual_isEmptyString() {
    char s[MAX_STRING_SIZE + 1] = "";

    assert(isLettersOfWordsInStringEqual(s) == false);
}

void test_isLettersOfWordsInStringEqual() {
    test_isLettersOfWordsInStringEqual_isEqualLetters();
    test_isLettersOfWordsInStringEqual_isNotEqualLetters();
    test_isLettersOfWordsInStringEqual_isEmptyString();
}
void test_isStringHaveAllLetters_1() {
    char s1[MAX_STRING_SIZE + 1] = "qwerty";
    char s2[MAX_STRING_SIZE + 1] = "ytrqwe";
    wordDescriptor w;
    getWord(s2, &w);

    assert(isStringHaveAllLetters(s1, w) == true);
}

void test_isStringHaveAllLetters_2() {
    char s1[MAX_STRING_SIZE + 1] = "wasd";
    char s2[MAX_STRING_SIZE + 1] = "wsqe";
    wordDescriptor w;
    getWord(s2, &w);

    assert(isStringHaveAllLetters(s1, w) == false);
}

void test_isStringHaveAllLetters_3() {
    char s1[MAX_STRING_SIZE + 1] = "";
    char s2[MAX_STRING_SIZE + 1] = "wasd";
    wordDescriptor w;
    getWord(s2, &w);

    assert(isStringHaveAllLetters(s1, w) == false);
}

void test_isStringHaveAllLetters() {
    test_isStringHaveAllLetters_1();
    test_isStringHaveAllLetters_2();
    test_isStringHaveAllLetters_3();
}
void test_tasks() {
    test_removeExtraSpaces();
    test_removeNonLetters();
    test_digitToStart();
    test_digitToStartForString();
    test_spaceInsteadDigits();
    test_replace();
    test_sortedWord();
    test_getCountPalindromeWords();
    test_getMergeString();
    testAll_getWordBeforeFirstWordWithA();
    test_isStringHaveEqualWords();
    test_getStringWithoutEqualLastWord();
    test_deletePalindromeWords();
    test_getLastWordInFirstStringFromSecondString();
    test_isLettersOfWordsInStringEqual();
    test_isStringHaveAllLetters();
}

int main() {
    test_function();
    test_tasks();
    return 0;
}
