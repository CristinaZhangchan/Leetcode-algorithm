class Solution(object):
    def search(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """
        left, right = 0, len(nums)
        nums.sort()

        while left < right:
            middle = left + (right - left) // 2

            if nums[middle] < target:
                left = middle + 1
            elif nums[middle] > target:
                right = middle
            else:
                return middle
        
        return -1

arr = [2,4,6,3,5,2,4,2,6,7,9]
target = 5
solution = Solution()
result = solution.search(arr, target)
print("Index of target:", result) 