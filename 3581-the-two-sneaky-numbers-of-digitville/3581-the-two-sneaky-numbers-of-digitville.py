class Solution:
    def getSneakyNumbers(self, nums: List[int]) -> List[int]:
        ans =[]
        temp =[]
        for i in nums:
            if i in temp:
                ans.append(i)
            else:
                temp.append(i)
        return ans