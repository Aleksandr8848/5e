//
// Created by Admin on 08.03.2022.
//

#ifndef INC_5E_GETCOUNTPALINDROMEWORDS_H
#define INC_5E_GETCOUNTPALINDROMEWORDS_H

int getCountPalindromeWords(char *s) {
    char *readPtr = s;
    int count = 0;
    wordDescriptor word;
    while (getWordCommas(readPtr, &word)) {
        count += isWordPalindrome(word);
        readPtr = word.end + (*word.end != '\0');
    }
    return count;
}
#endif //INC_5E_GETCOUNTPALINDROMEWORDS_H
