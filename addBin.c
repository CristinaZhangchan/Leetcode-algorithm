#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* addBinary(char* a, char* b) {
    int sizeA = strlen(a);
    int sizeB = strlen(b);
    int sizeOutput = (sizeA > sizeB ? sizeA : sizeB) + 1;
    char* output = malloc(sizeOutput + 1);
    int sum = 0;

    output[sizeOutput] = '\0';
    while (sizeA > 0 || sizeB > 0 || sum > 0) {
        if (sizeA > 0) {
            sum += a[--sizeA] - '0';
        }
        if (sizeB > 0) {
            sum += b[--sizeB] - '0';
        }
        output[--sizeOutput] = (sum % 2) + '0';
        sum /= 2;
    }
    return output + sizeOutput;
}

int main(void) {
    char *a1 = "101011";
    char *b1 = "1100";
    char *res1 = addBinary(a1, b1);
    printf("addBinary(\"%s\",\"%s\") = \"%s\"\n",a1, b1, res1);
    int lenA = strlen(a1), lenB = strlen(b1);
    int bufSize = (lenA > lenB ? lenA : lenB) + 1;
    int resLen = strlen(res1);
    int offset = bufSize - resLen;
    char *orig = res1 - offset;
    free(orig);

    return 0;
}