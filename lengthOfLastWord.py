class Solution(object):
    def lengthOfLastWord(self, s):
        """
        :type s: str
        :rtype: int
        """
        word = s.strip().split()
        if len(s) == 0:
            return 0
        
        return len(word[-1])
    
s = "   fly me   to   the moon  "
solution = Solution().lengthOfLastWord(s)
print(solution)
