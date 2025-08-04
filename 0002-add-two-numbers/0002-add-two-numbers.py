# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def addTwoNumbers(self, l1: ListNode, l2: ListNode) -> ListNode:
        dummy_head = ListNode()  # Dummy node to simplify handling the head
        current = dummy_head     # Pointer to build the result list
        carry = 0                # Initialize carry to 0

        # Traverse both lists until all digits and carry are processed
        while l1 or l2 or carry:
            val1 = l1.val if l1 else 0  # Get current digit from l1
            val2 = l2.val if l2 else 0  # Get current digit from l2
            total = val1 + val2 + carry # Sum of digits and carry

            carry = total // 10         # Compute new carry
            current.next = ListNode(total % 10)  # Add digit node to result
            current = current.next

            # Advance the input lists if not at the end
            if l1:
                l1 = l1.next
            if l2:
                l2 = l2.next

        return dummy_head.next  # Return the real head of the result list
