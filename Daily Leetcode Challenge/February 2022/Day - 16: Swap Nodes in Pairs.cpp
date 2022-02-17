
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
    ListNode* swapPairs(ListNode* head) {
        ListNode* dummy = new ListNode(-1, head);
        ListNode* prev = dummy, *current = head;
        while (current != NULL && current->next != NULL) {
            prev->next = current->next;
            current->next = current->next->next;
            prev->next->next = current;
            current = current->next;
            prev = prev->next->next;
        }
        
        return dummy->next;
    }
};