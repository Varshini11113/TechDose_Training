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
    ListNode* oddEvenList(ListNode* head) {
        if(!head || !head->next || !head->next->next) return head;
        ListNode *start = head;
        ListNode *end = head->next;
        ListNode *temp = head->next;
        while(start->next && end->next){
            start->next = end->next;
            end->next = start->next->next;
            start = start->next;
            end = end->next;
        }
        start->next = temp;
        return head;
    }
};