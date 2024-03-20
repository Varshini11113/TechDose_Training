# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
class Solution:
    def mergeInBetween(self, list1: ListNode, a: int, b: int, list2: ListNode) -> ListNode:
        prev = list1

        # prev will point to the node one before index 'a'
        for i in range(a - 1):
            prev = prev.next

        track = prev

        # Move prev to the node at index 'b'
        for i in range(a, b + 1):
            prev = prev.next

        # Connect the end of list2 to the node after index 'b'
        track.next = list2
        end = list2
        while end.next is not None:
            end = end.next

        end.next = prev.next  # Connect end of list2 to the node after index 'b'

        return list1