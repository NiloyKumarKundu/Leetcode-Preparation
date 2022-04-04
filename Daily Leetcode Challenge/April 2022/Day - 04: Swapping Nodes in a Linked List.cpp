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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* left = head;
        ListNode* right = head;
        ListNode* cur = head;
        
        int count = 1;
        while (cur != NULL) {
            if (count < k) {
                left = left->next;
            } else if (count > k) {
                right = right->next;
            }
            count++;
            cur = cur->next;
        }
        
        int temp = left->val;
        left->val = right->val;
        right->val = temp;
        
        return head;
    }
};





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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* temp = head;
        ListNode* newHead = head;
        vector<int> v;
        int count = 0;
        
        while (temp != NULL) {
            v.push_back(temp->val);
            temp = temp->next;
            count++;
        }
        
        swap(v[k - 1], v[count - k]);
        
        int i = 0;
        while (newHead != NULL) {
            newHead->val = v[i];
            newHead = newHead->next;
            i++;
        }
        return head;
    }
};
