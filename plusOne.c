#include <stdio.h>
#include <stdlib.h>

int* plusOne (int* digits, int digitsSize, int* returnSize) {
    int* res = (int*)malloc((digitsSize+1)*(sizeof(int)));

    for(int i = 0; i < digitsSize; i++) {
        res[i] = digits[i];
    }

    for(int i = digitsSize - 1; i >= 0; i--) {
        if(res[i] < 9) {
            res[i]++;
            *returnSize = digitsSize;
            return res;
        }else {
            res[i] = 0;
        }
    }
    res[0] = 1;
    for(int i = 1; i <=digitsSize; i++) {
        res[i] = 0;
    }
    *returnSize = digitsSize + 1;
    return res;

}

int main(void) {
    int digits[] = {8,9,9,9,9,9};
    int size = sizeof(digits)/sizeof(*digits);
    int returnSize;

    int* res = plusOne(digits, size, &returnSize);

    printf("Result is: [");
    for(int i = 0; i < returnSize; i++) {
        printf("%i ", res[i]);
    }
    printf("].\n");
}