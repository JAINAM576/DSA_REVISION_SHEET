class Solution {
public:
int maxPath(TreeNode* root,int &ans){
    if(root==NULL)return 0;

    int left=maxPath(root->left,ans);
    int right=maxPath(root->right,ans);

    ans=max(ans,max(max(max(left+right+root->val,root->val),left+root->val),right+root->val));

    return max(left+root->val,max(right+root->val,root->val));

}
    int maxPathSum(TreeNode* root) {

        int ans=INT_MIN;
        maxPath(root,ans);
        return ans;
    }
};