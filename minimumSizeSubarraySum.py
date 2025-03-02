class Solution(object):
    def minSubArrayLen(self, target, nums):
        """
        :type target: int
        :type nums: List[int]
        :rtype: int
        """
        l= len(nums)
        min_len = float('inf')
        j = 0
        cur_sum = 0

        for i in range(l):
            cur_sum += nums[i]
            while cur_sum >= target:
                min_len = min(min_len,i-j+1)
                cur_sum -= nums[j]
                j += 1
        return  min_len if min_len != float("inf") else 0


target = 7
nums = [2,3,1,2,4,3]
solution = Solution().minSubArrayLen(target, nums)
print(solution)