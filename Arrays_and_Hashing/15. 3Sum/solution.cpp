class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
int n=nums.size();
sort(nums.begin(),nums.end());

vector<vector<int>> ans;
int j;
int k;
for(int i=0;i<n-1;i++){
    j=i+1;
    k=n-1;
if(i!=0 && nums[i]==nums[i-1])continue;
while(j<k){

int sum=nums[i]+nums[j]+nums[k];

if(sum==0){
    ans.push_back({nums[i],nums[j],nums[k]});
    while(j<k && nums[j]==nums[j+1])j++;
    j++;
    while(k>j && nums[k-1]==nums[k])k--;
    k--;
    cout<<i<<" "<<j<<" "<<k<<" "<<endl;

}
else if (sum<0){
    j++;
}
else {
    k--;
}
   
}

}

return ans;
    }
};

// -4 -1 -1 0 1 2

// -1+-1+2=0

// -1+0+1=