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

    unordered_map<int, TreeNode*> mp;
    int used = 0;

    bool merge(TreeNode* root) {

        if (root == NULL)
            return true;

        // If this is a leaf
        if (root->left == NULL && root->right == NULL) {

            // Is there another tree whose root has this value?
            if (mp.count(root->val)) {

                TreeNode* tree = mp[root->val];

                // Merge it here
                root->left = tree->left;
                root->right = tree->right;

                // Remove it so we don't use it again
                mp.erase(root->val);

                used++;

                // Continue merging the newly attached tree
                return merge(root->left) && merge(root->right);
            }

            return true;
        }

        // Normal node
        return merge(root->left) && merge(root->right);
    }


    bool isBST(TreeNode* root, long long low, long long high) {

        if (root == NULL)
            return true;

        if (root->val <= low || root->val >= high)
            return false;

        return isBST(root->left, low, root->val) &&
               isBST(root->right, root->val, high);
    }


    TreeNode* canMerge(vector<TreeNode*>& trees) {

        // Store all roots
        for (auto tree : trees) {
            mp[tree->val] = tree;
        }

        // Find which root is NOT a leaf in another tree
        unordered_set<int> leaves;

        for (auto tree : trees) {

            if (tree->left)
                leaves.insert(tree->left->val);

            if (tree->right)
                leaves.insert(tree->right->val);
        }

        TreeNode* root = NULL;

        for (auto tree : trees) {

            if (!leaves.count(tree->val)) {
                root = tree;
                break;
            }
        }

        if (root == NULL)
            return NULL;

        // Don't try to merge the final root into itself
        mp.erase(root->val);

        // Merge all possible trees
        if (!merge(root))
            return NULL;

        // Every other tree must have been used
        if (used != trees.size() - 1)
            return NULL;

        // Finally check BST
        if (!isBST(root, LLONG_MIN, LLONG_MAX))
            return NULL;

        return root;
    }
};