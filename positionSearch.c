#include <stdio.h>

int searchInsert(int* nums, int numsSize, int target) {
    if(numsSize == 0) return 0;
    int left = 0;
    int right = numsSize -1;
    while(left <= right) {
        int mid = (left + right) / 2;
        if(target < nums[mid]) right = mid - 1;
        else if (target > nums[mid]) left = mid + 1 ;
        else return mid;
    }  
    return left;  
}

int main (void) {
    int nums[] = {1,2,6,8,9,10,24};
    int target = 10;
    int numSize = sizeof(nums)/sizeof(*nums);

    int index = searchInsert(nums, numSize, target);
    printf("The target %i inserts index %i\n",target, index);
}