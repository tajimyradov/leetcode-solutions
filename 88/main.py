class Solution:
    def merge(self, nums1: list[int], m: int, nums2: list[int], n: int) -> None:
      
        p1 = m - 1
        p2 = n - 1
        p_merged = m + n - 1

        while p1 >= 0 and p2 >= 0:
            if nums1[p1] >= nums2[p2]:
                nums1[p_merged] = nums1[p1]
                p1 -= 1 
            else:
                nums1[p_merged] = nums2[p2]
                p2 -= 1 
            p_merged -= 1  

        while p2 >= 0:
            nums1[p_merged] = nums2[p2]
            p2 -= 1
            p_merged -= 1

solver = Solution()

nums1_1 = [1, 2, 3, 0, 0, 0]
m_1 = 3
nums2_1 = [2, 5, 6]
n_1 = 3
solver.merge(nums1_1, m_1, nums2_1, n_1)
print(f"Test Case 1: Expected [1, 2, 2, 3, 5, 6], Got: {nums1_1}")
assert nums1_1 == [1, 2, 2, 3, 5, 6]