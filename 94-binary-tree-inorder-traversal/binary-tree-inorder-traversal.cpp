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
        if (root == NULL) {
            return {};
        }

        vector<int> left = inorderTraversal(root->left);
        vector<int> right = inorderTraversal(root->right);

        vector<int> result;

        // Left
        result.insert(result.end(), left.begin(), left.end());

        // Root
        result.push_back(root->val);

        // Right
        result.insert(result.end(), right.begin(), right.end());

        return result;
    }
};