class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        vector<int>lmax(n);
        vector<int>rmax(n);
        int ans=0;
lmax[0]=height[0];
rmax[n-1]=height[n-1];
int j=n-2;
        for(int i=1;i<n;i++,j--){

lmax[i]=max(lmax[i-1],height[i]);
rmax[j]=max(rmax[j+1],height[j]);
        }

        for(int i=1;i<n;i++){
            ans+=min(lmax[i],rmax[i])-height[i];
        }
        return ans;
        
    }
};