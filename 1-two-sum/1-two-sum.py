class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        hits = dict()
        for i, num in enumerate(nums):
            if (target - num) in hits:
                return [i, hits[target-num]]
            hits[num] = i