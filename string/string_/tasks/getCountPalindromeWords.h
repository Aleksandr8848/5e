//
// Created by Admin on 08.03.2022.
//

#ifndef INC_5E_GETCOUNTPALINDROMEWORDS_H
#define INC_5E_GETCOUNTPALINDROMEWORDS_H

int getCountPalindromeWords(char *s) {
    int count = 0;
    wordDescriptor word;
    while (getWordCommas(s, &word)) {
        if (isWordPalindrome(word))
            count++;
        s = word.end;
    }
    return count;
}
#endif //INC_5E_GETCOUNTPALINDROMEWORDS_H
