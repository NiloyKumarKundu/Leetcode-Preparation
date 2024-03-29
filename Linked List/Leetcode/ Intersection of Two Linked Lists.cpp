// Time Complexity: O(2 * M)
// Space Complexity: O(1)

// Shorter version Code:


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
    ListNode *getIntersectionNode(ListNode *root1, ListNode *root2) {
        ListNode* head1 = root1;
        ListNode* head2 = root2;

        if (head1 == NULL || head2 == NULL) {
            return NULL;
        }

        while (head1 != head2) {
            head1 = head1 == NULL ? root2 : head1->next;
            head2 = head2 == NULL ? root1 : head2->next;
        }
        return head1;
    }
};




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
    ListNode *getIntersectionNode(ListNode *root1, ListNode *root2) {
        ListNode* head1 = root1;
        ListNode* head2 = root2;

        if (head1 == NULL || head2 == NULL) {
            return NULL;
        }

        while (head1 != head2) {
            if (head1 == NULL) {
                head1 = root2;
            } else {
                head1 = head1->next;
            }
            
            if (head2 == NULL) {
                head2 = root1;
            } else {
                head2 = head2->next;
            }
        }
        return head1;
    }
};