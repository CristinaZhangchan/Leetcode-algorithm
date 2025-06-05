#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//without copy paste the first index auguments
/*
char *common_suffix(char **strings, size_t strSize) {        
        int k = 0;
        char *copy = malloc(k+1);
        for(int j = 0;;++j){
            if(strings[0][j] == '\0') return strdup(strings[0]);
            for (int i = 1; i < strSize - 1 ; i++){
                if(strings[i][j] != strings[0][j]){
                    copy[k] = '\0';
                    return copy;         
                }
            }
            copy[k++] = strings[i][j];
        }
        return copy;

}
*/
//with changing the first index argument in array
char *common_suffix(char **strings, size_t strSize) {
    for (int j = 0; ; ++j) {
        if (strings[0][j] == '\0') return strings[0];
        for (int i = 1; i < strSize; i++) {
            if(strings[i][j] != strings[0][j]) {
                strings[0][j] = '\0';
                strings[0][j] = '\0';
                return strings[0];
            }
        }
    }
}
int main(int argc, char **argv) {
    char *result = common_suffix(argv + 1, argc - 1);
    printf("%s\n", result);
    //free(result); 
}




