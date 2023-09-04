/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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

// /**
//  * Definition for singly-linked list.
//  * struct ListNode {
//  *     int val;
//  *     struct ListNode *next;
//  * };
//  */
// bool hasCycle(struct ListNode *head) {
//     struct ListNode *temp = (struct ListNode*) malloc (sizeof(struct ListNode));
//     struct ListNode *fast = (struct ListNode*) malloc (sizeof(struct ListNode));
//     temp = head, fast = head;
//     while(fast != NULL && fast->next != NULL){
//         temp = temp->next;
//         fast = fast->next->next;
//         if(temp == fast){
//             return true;
//         }
//     }
//     return false;
// }