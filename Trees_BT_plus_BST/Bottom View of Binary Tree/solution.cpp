// Function to return a list containing the bottom view of the given tree.

class Solution {
  public:
    vector<int> bottomView(Node *root) {
        // Your Code Here
        queue<pair<int,Node *>>q;
        map<int,int> mp;
        
        vector<int> ans;
        
        q.push({0,root});
        
        while(!q.empty()){
            pair<int,Node*> top=q.front();
            int verticleLine=top.first;
            Node* rt=top.second;
            q.pop();
            mp[verticleLine]=rt->data;
            if(rt->left!=NULL){
                q.push({verticleLine-1,rt->left});
            }
            if(rt->right!=NULL){
                q.push({verticleLine+1,rt->right});
            }
        }
        for(auto it:mp){
            ans.push_back(it.second);
        }
        return ans;
    }
};