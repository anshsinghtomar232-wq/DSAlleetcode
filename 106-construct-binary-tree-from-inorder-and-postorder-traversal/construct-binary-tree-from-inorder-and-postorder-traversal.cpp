
class Solution {
public:
    TreeNode* solve(const vector<int>& inorder, const vector<int>& postorder, int& index, 
                   int inorderstart, int inorderend, unordered_map<int, int>& nodetoindex) {
        if (index < 0 || inorderstart > inorderend) {
            return nullptr;
        }

        int element = postorder[index--];
        TreeNode* root = new TreeNode(element);
        int position = nodetoindex[element];

        // Right subtree must be constructed first because postorder visits Right before Left when traversing backwards
        root->right = solve(inorder, postorder, index, position + 1, inorderend, nodetoindex);
        root->left = solve(inorder, postorder, index, inorderstart, position - 1, nodetoindex);

        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();
        int postorderindex = n - 1;
        
        unordered_map<int, int> nodetoindex;
        for (int i = 0; i < n; i++) {
            nodetoindex[inorder[i]] = i;
        }

        return solve(inorder, postorder, postorderindex, 0, n - 1, nodetoindex);
    }
};