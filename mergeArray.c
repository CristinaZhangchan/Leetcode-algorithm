#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {
    int i = m - 1;
    int j = n - 1;
    int tot = m + n - 1;

    while(i >= 0 && j >= 0) {
        if(nums1[i] >= nums2[j]){
            nums1[tot--] = nums1[i--];
        } else {
            nums1[tot--] = nums2[j--];
        }
    }
    while(j >= 0) nums1[tot--] = nums2[j--];
}

int main(void) {
    int nums1[] = {2,3,5,6,8,9,56};
    int nums2[] = {3,5,6,8,9};
    int size2 = sizeof(nums2) / sizeof(*nums2);
    int size1 = sizeof(nums1) / sizeof(*nums1) - size2;
    int *numsall = malloc(sizeof(*nums1) * (size1+size2));

    memcpy(numsall, nums1, sizeof(*nums1)*size1);
    merge(numsall,size1,size1,nums2,size2,size2);
    
    for(int i = 0; i < size1+size2; i++) {
        printf("%d ", nums1[i]);
    } 
    printf("\n");
    return 0;
}