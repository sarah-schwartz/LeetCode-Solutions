from typing import List

class Solution:
    def permute(self, nums: List[int]) -> List[List[int]]:
        result = []  # will hold all permutations

        def backtrack(start: int):
            # If we've fixed all positions, record the current permutation
            if start == len(nums):
                result.append(nums[:])  # append a shallow copy
                return
            # Try each possible swap for current position
            for i in range(start, len(nums)):
                nums[start], nums[i] = nums[i], nums[start]  # swap in
                backtrack(start + 1)                        # recurse
                nums[start], nums[i] = nums[i], nums[start]  # swap back (backtrack)

        backtrack(0)  # kick off recursion starting at index 0
        return result
