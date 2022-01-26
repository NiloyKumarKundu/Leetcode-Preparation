// Time Complexity: O(N)
// Space Complexity: O(N) or O(Height of the binary tree)

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        TreeNode* node = root;
        stack<TreeNode*> st;
        vector<int> inorder;
        
        while (true) {
            if (node != NULL) {
                st.push(node);
                node = node->left;
            } else {
                if (st.empty())
                    break;
                
                node = st.top();
                inorder.push_back(node->val);
                st.pop();
                node = node->right;
            }
        }
        return inorder;
    }
};