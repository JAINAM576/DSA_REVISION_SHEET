class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxi = INT_MIN;
        int sum = 0;
        for (auto it : nums) {
            sum += it;
            maxi = max(maxi, sum);

            sum = sum < 0 ? 0 : sum;
        }
        return maxi;
    }
};