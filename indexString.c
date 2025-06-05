#include <stdio.h>
#include <string.h>

int strStr(char* haystack, char* needle) {
    int len1 = strlen(haystack);
    int len2 = strlen(needle);

    if (*needle == '\0') return 0;

    for (int i = 0; i <= len1-len2; i++) {
        int j = 0;
        while (j < len2 && haystack[i+j] == needle[j]) {
            j++;
        }
        if (j == len2) return i;
    }
    return -1;
}

int main(void) {
    char haystack[] = "sadbutsad";
    char needle[] = "ts";

    int index = strStr(haystack, needle);
    printf("%s occurrs at index %i \n", needle, index);
}