#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int lengthOfLastWord(char* s) {
    if(*s == ' ' || *s == '\0') return 0;
    int size = strlen(s);
    bool untilspace = false;

    int count = 0;
    for(int i = size - 1; i >= 0;i--) {
        if(s[i] != ' ') {
            count++;
            untilspace = true;
        } else if (untilspace) {
            break;
        }
    }
    return count;
}

int main(void) {
    char words[] = " ";
    int size = lengthOfLastWord(words);
    printf("The length of last word is %i.\n",size); 
}