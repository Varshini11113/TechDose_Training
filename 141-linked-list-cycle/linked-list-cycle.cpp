/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

//C++ language
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode *temp, *fast;
        temp = head, fast = head;
        while(fast && fast->next){
            temp = temp->next;
            fast = fast->next->next;
            if(temp == fast){
                return true;
            }
        }
        return false;
    }
};
