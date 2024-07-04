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
    ListNode* deleteMiddle(ListNode* head) {
        if(head->next == nullptr) return nullptr;
        ListNode* slow = head, *fast = head, *data = nullptr;
        while(fast != nullptr && fast->next != nullptr){
            data = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        data->next = data->next->next;
        return head;
    }
};