# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def rotateRight(self, head: Optional[ListNode], k: int) -> Optional[ListNode]:
        # Edge case: empty list or only one node or no rotation
        if not head or not head.next or k == 0:
            return head

        # Step 1: Compute the length of the list and get the tail
        length = 1
        tail = head
        while tail.next:
            tail = tail.next
            length += 1

        # Step 2: Effective rotations (handle cases where k > length)
        k = k % length
        if k == 0:
            return head

        # Step 3: Connect tail to head to make it circular
        tail.next = head

        # Step 4: Find the new tail: (length - k - 1) steps from head
        new_tail = head
        for _ in range(length - k - 1):
            new_tail = new_tail.next

        # Step 5: New head is next of new tail
        new_head = new_tail.next

        # Step 6: Break the circular link
        new_tail.next = None

        return new_head
