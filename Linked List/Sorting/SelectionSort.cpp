// Time Complexity: O(N*N)

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
    ListNode* sortList(ListNode* head) {
        if (head == NULL) 
            return NULL;
        
        ListNode* current = head;
        
        while (current != NULL) {
            ListNode* itr = current;
            ListNode* mini = itr;
            
            while (itr != NULL) {
                if (itr->val < mini->val)
                    mini = itr;
                itr = itr->next;
            }
            swap(current->val, mini->val);
            current = current->next;
        }
        return head;
    }
};










