#include <stdio.h>

int removeDuplicate(int*nums, int numSz) {
    if(numSz == 0) return 0;

    int k = 1;
    for (int i = 0; i < numSz - 1; i++) {
        if(nums[i] != nums[i+1]){
            nums[k] = nums[i+1];
            k++;
        }
    }
    return k;
}

int main(void) {
    int nums[] = {1, 1, 2, 3, 3, 4, 5, 5};
    int sizeNum = sizeof(nums)/sizeof(*nums);
    int size = removeDuplicate(nums, sizeNum);

    printf("After remove the duplicates, The array is : ");    
    for (int i = 0; i < size; i++) {
        printf("%i ",nums[i]);
    }
    printf("\n");
}