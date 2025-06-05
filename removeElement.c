#include <stdio.h>

int removeElement (int* nums, int numsSize, int val) {
    int k = 0;
    for (int i = 0; i < numsSize; i++) {
        if(nums[i] != val) {
            nums[k] = nums[i];
            k++;    
        } 
    }
    return k;
}

int main(void) {
    int nums[] = {2,3,5,3,6,4,4,32,2};
    int val = 4;
    int numSize = sizeof(nums) / sizeof(*nums);
    int size = removeElement(nums, numSize, val);
    printf("After removing the array is :");
    for (int i = 0; i < size; i++) {
        printf("%i ", nums[i]);
    }
    printf("\n");
    return 0;
}