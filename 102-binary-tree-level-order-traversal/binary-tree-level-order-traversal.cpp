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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;

        if (root == NULL)
            return ans;

        deque<TreeNode*> dq;
        dq.push_back(root);

        while (!dq.empty()) {
            int n = dq.size();
            vector<int> level;

            for (int i = 0; i < n; i++) {
                TreeNode* node = dq.front();
                dq.pop_front();

                level.push_back(node->val);

                if (node->left)
                    dq.push_back(node->left);

                if (node->right)
                    dq.push_back(node->right);
            }

            ans.push_back(level);
        }

        return ans;
    }
};