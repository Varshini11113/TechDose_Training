class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def removeNthFromEnd(self, head, n):
        start = ListNode()
        start.next = head
        fast = start
        slow = start
        
        # Move fast pointer to the (n+1)-th node
        for i in range(1, n + 2):
            fast = fast.next
        
        # Move both pointers until fast reaches the end
        while fast is not None:
            fast = fast.next
            slow = slow.next
        
        # Remove the Nth node from the end
        slow.next = slow.next.next
        
        return start.next

# Example usage:
# Create a linked list: 1 -> 2 -> 3 -> 4 -> 5
# head = ListNode(1, ListNode(2, ListNode(3, ListNode(4, ListNode(5)))))
# solution = Solution()
# result = solution.removeNthFromEnd(head, 2)

# Print the result
