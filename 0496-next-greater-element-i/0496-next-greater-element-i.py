class Solution:
    def nextGreaterElement(self, nums1: List[int], nums2: List[int]) -> List[int]:
        stack = []  # Stack to keep track of elements for which we haven't found a next greater yet
        next_greater = {}  # Dictionary to store the next greater element for each number in nums2

        # Traverse nums2 from right to left
        for i in range(len(nums2) - 1, -1, -1):
            current = nums2[i]

            # Remove elements from stack that are smaller than or equal to current
            while stack and stack[-1] <= current:
                stack.pop()

            # If stack is empty, there is no greater element to the right
            if not stack:
                next_greater[current] = -1
            else:
                next_greater[current] = stack[-1]  # Top of stack is the next greater element

            # Push the current element onto the stack
            stack.append(current)

        # Build the result for nums1 by looking up the next greater elements
        return [next_greater[num] for num in nums1]
