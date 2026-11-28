class Solution:
    def smallestEqual(self, nums: list[int]) -> int:

        n=len(nums)
        for i in range(0,n):
            if(i%10==nums[i]):
                return i

        return -1
        