import bisect

class Solution:
    def searchInsert(self, nums: list[int], target: int) -> int:
        index = bisect.bisect_left(nums, target)
        return index


nums = [1, 3, 4, 5, 6]
print(Solution().searchInsert(nums, 2))
