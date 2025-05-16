class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
stack<int> st;
unordered_map<int,int>mp;
int n=nums2.size();
for(int i=0;i<n;i++){
    mp[nums2[i]]=i;
}

st.push(nums2[n-1]);
nums2[n-1]=-1;
for(int i=n-2;i>=0;i--){
    while(!st.empty() && nums2[i]>st.top()){
        st.pop();
    }
    if(st.empty()){
        st.push(nums2[i]);
        nums2[i]=-1;
    }
    else if(nums2[i]<st.top()){
        int temp=st.top();
        st.push(nums2[i]);
        nums2[i]=temp;
    }
}

for(int i=0;i<nums1.size();i++){
nums1[i]=nums2[mp[nums1[i]]];
}        
return nums1;
    }
};