#include "string/string_/string_.h"


    void test_find1(){
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

        assert(!strcmp(str, res));
    }

    void test_strcmp2() {
        char str[] = "123";
        char res[] = "321";

        assert(strcmp(str, res));
    }

    void test_strcmp() {
        test_strcmp1();
        test_strcmp2();
    }

    void test() {
        test_find();
        test_findNonSpace();
        test_findSpace();
        test_findNonSpaceReverse();
        test_findSpaceReverse();

        test_strcmp();

       // test_copy();
       // test_copyIf();
       // test_copyIfReverse();
    }
int main() {
    test();
    return 0;
}
