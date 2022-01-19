// Time Complexity: O(N)
// Space Complexity: O(1)

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
    ListNode *intersection(ListNode *head) {
        ListNode *hare = head, *tortoris = head;
        
        while (hare != NULL && hare->next != NULL) {
            tortoris = tortoris->next;
            hare = hare->next->next;
            if (hare == tortoris) {
                return hare;
            }
        }
        return NULL;
    }
    
    ListNode *detectCycle(ListNode *head) {
        if (head == NULL || head->next == NULL) {
            return NULL;
        }
        ListNode *intersect = intersection(head);
        
        if (intersect != NULL) {
            ListNode *start = head;
            while (intersect != start) {
                intersect = intersect->next;
                start = start->next;
            }
            return start;
        }
        
        return NULL;
    }
};