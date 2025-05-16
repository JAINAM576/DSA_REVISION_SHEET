class Solution {
public:
    int dp[101];
    int solve(vector<int>& nums, int i) {
        if (i == 0)
            return nums[0];
        if (i < 0)
            return 0;
        if (dp[i] != -1)
            return dp[i];

        int pick=nums[i]+solve(nums,i-2);
        int nopick=0+solve(nums,i-1);
        return dp[i]=max(pick,nopick);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        memset(dp, -1, sizeof(dp));

        return solve(nums, n - 1);
    }
};