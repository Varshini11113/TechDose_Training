/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* reverseLinkedList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* current = head;
        while (current) {
            ListNode* next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        return prev;
    }

    ListNode* doubleIt(ListNode* head) {
        if (!head) {
        return nullptr;
        }

        ListNode* reversedHead = reverseLinkedList(head);

        ListNode* current = reversedHead;
        ListNode* prev = nullptr;
        int carry = 0;
        while (current) {
            int newVal = current->val * 2 + carry;
            current->val = newVal % 10;
            carry = newVal / 10;
            prev = current;
            current = current->next;
        }

        while (carry > 0) {
            if (!prev->next) {
                prev->next = new ListNode(carry);
                break;
            }
            int newVal = prev->next->val + carry;
            prev->next->val = newVal % 10;
            carry = newVal / 10;
            prev = prev->next;
        }

        return reverseLinkedList(reversedHead);

    }
};