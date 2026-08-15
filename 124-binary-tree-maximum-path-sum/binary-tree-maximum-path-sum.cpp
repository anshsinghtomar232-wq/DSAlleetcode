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
private:
    int maxSum = INT_MIN;

    int maxGain(TreeNode* node) {
        if (node == nullptr) return 0;

        // Max sum from left and right subtrees; ignore negative contributions
        int leftGain = max(maxGain(node->left), 0);
        int rightGain = max(maxGain(node->right), 0);

        // Path sum if current node is the highest node (turning point) of the path
        int currentPathSum = node->val + leftGain + rightGain;

        // Update global maximum
        maxSum = max(maxSum, currentPathSum);

        // Return max path sum extending to parent (can only choose 1 branch)
        return node->val + max(leftGain, rightGain);
    }

public:
    int maxPathSum(TreeNode* root) {
        maxGain(root);
        return maxSum;
    }
};