class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head) return NULL;
        int len = 1;
        ListNode *curr = head;
        while (curr->next) {
            ++len;
            curr = curr->next;
        }
        curr->next = head;
        k = len - k % len;
        while (k--) curr = curr->next;
        head = curr->next;
        curr->next = NULL;
        return head;
    }
};