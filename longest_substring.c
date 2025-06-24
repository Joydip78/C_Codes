#include <stdio.h>
#include <string.h>

int lengthOfLongestSubstring(char * s) {
    int index[128]; // ASCII size
    for (int i = 0; i < 128; i++) index[i] = -1;

    int maxLen = 0;
    int start = 0;

    for (int end = 0; s[end] != '\0'; end++) {
        if (index[(unsigned char)s[end]] >= start) {
            start = index[(unsigned char)s[end]] + 1;
        }
        index[(unsigned char)s[end]] = end;
        int len = end - start + 1;
        if (len > maxLen) maxLen = len;
    }

    return maxLen;
}
int main() {
    char s[] = "abcabcbb";
    int result = lengthOfLongestSubstring(s);
    printf("Length of longest substring without repeating characters: %d\n", result);
    return 0;
}
