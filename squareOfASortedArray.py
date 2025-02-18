class Solution(object):
    def sortedSquares(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        #brute force
        """
        index = 0 
        for index in range(len(nums)):
            nums[index] = nums[index] ** 2
        nums.sort()
        return nums
        """
        #double-pointer alg  1.犯错点：right的长度出现了out of index，2.abs的写法是分开的，3.list起名字避免叫list，因为有这样的func
        """
        left, right = 0, len(nums)-1
        new_list =[]
        while left <= right:
            if abs(nums[left]) <= abs(nums[right]):
                new_list.append(nums[left] **2)
                left = left + 1
            else:
                new_list.append(nums[right] **2)
                right = right - 1
        return sorted(new_list)
        """
        left, right ,i = 0, len(nums)-1, len(nums) - 1
        new_list = [float('inf')] *len(nums)
        while left <=right:
            if nums[left]**2 < nums[right]**2:
                new_list[i] = nums[right]**2
                right -= 1    
            else:
                new_list[i] = nums[left]**2
                left += 1
            i -= 1
        return new_list
 

arr = [2,4,6,3,5,2,4,2,6,7,9]
solution = Solution()
result = solution.sortedSquares(arr)
print("Index of target:", result) 