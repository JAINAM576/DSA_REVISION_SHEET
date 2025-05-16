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
int solve(TreeNode*root,int &ans){
    if(root==NULL)return -1;
    int leftMaxDepth=1+solve(root->left,ans);
    int rightMaxDepth=1+solve(root->right,ans);


    ans=max(ans,leftMaxDepth+rightMaxDepth);

    return max(rightMaxDepth,leftMaxDepth);
}
    int diameterOfBinaryTree(TreeNode* root) {
        int ans=0;
     
         solve(root,ans);
         return ans;
    }
};