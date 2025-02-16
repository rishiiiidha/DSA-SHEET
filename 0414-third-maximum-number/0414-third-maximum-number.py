class Solution:
    def thirdMax(self, nums: List[int]) -> int:
        res = []
        temp =[]
        for i in nums:
            if i in temp:
               continue
            else: 
                temp.append(i)
        temp.sort(reverse=True)
        k=len(temp)
        if k >=3:
            return temp[2]
        return temp[0]

