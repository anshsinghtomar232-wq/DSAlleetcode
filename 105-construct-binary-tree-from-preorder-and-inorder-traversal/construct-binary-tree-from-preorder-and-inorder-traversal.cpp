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

 TreeNode*solve(vector<int>&preorder,vector<int> &inorder, int&index,int inorderstart,int inorderend ,unordered_map<int,int> &nodetoindex){
    if(index>=inorder.size()|| inorderstart> inorderend){
        return NULL;
    }
    int element=preorder[index++];
    TreeNode* root= new TreeNode(element);
    int position=nodetoindex[element];

    root->left=solve(preorder, inorder,index,inorderstart,position-1,nodetoindex);

    root->right=solve(preorder,inorder,index,position+1,inorderend,nodetoindex);
    return root;
 }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int preorderindex=0;
        int n=inorder.size();
       unordered_map<int,int> nodetoindex;
        for(int i=0;i<n;i++){
            nodetoindex[inorder[i]]=i;
        }
       
       return solve(preorder,inorder,preorderindex,0,n-1,nodetoindex);
          
    }
};