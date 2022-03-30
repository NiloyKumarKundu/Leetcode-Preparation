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
    ListNode *detectCycle(ListNode *head) {
        if (head == NULL || head->next == NULL) {
            return NULL;
        }
        
        ListNode* hare = head;
        ListNode* tortoise = head;
        bool flag = true;
        while (tortoise != NULL && tortoise->next != NULL) {
            hare = hare->next;
            tortoise = tortoise->next->next;
            if (hare == tortoise) {
                flag = false;
                break;
            }
        }
        
        if (flag) {
            return NULL;
        }
    
        hare = head;
        while (hare != tortoise) {
            hare = hare->next;
            tortoise = tortoise->next;
        }
        return hare;
    }
};