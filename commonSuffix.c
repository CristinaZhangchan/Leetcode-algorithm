#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *commonSuffix(char **strings, size_t strSize) {
    int i = 0;
    size_t *j = malloc(i+1);
    size_t minsz = (size_t) - 1;

    for(; i < strSize; i++){
        j[i] = strlen(*(strings+i));
        minsz = minsz < j[i] ? minsz : j[i];
        printf("%s is: %lu\n",strings[i], j[i]);
    }
    printf("Minimum size is: %lu\n",minsz); 
    
    char *ptr = strings[0] + j[0] + 1;
    for(;minsz; minsz--, ptr--){
        if(strSize < 2 || strings[0][i] == '\0') return strings[0];
        for(int k = 0; k < strSize - 1; k++) {
            if(strings[k][j[k]] != strings[k+1][j[k+1]])
                return ptr;
            j[k]--;
        }
        j[strSize-1]--;
    }
    return ptr;
}

int main(int argc, char **argv) {
    char *result = commonSuffix(argv + 1, argc - 1);
    printf("%s\n",result);  
}