class Solution {
public:
    int firstSmallValueIndex(vector<int>& nums, int& n) {
        int maxi = nums[n - 1];
        int tempIndex = n - 1;
        for (int i = n - 2; i >= 0; i--) {
            if (nums[i] != maxi && nums[i] < maxi) {
                tempIndex = i;
                break;
            }
            if (nums[i] > maxi) {
                maxi = nums[i];
            }
        }
        return tempIndex;
    }
    void firstGreaterValue(vector<int>& nums, int& tempNewLeftValue,
                           int& tempIndex,int &n) {
        for (int i = n - 1; i > tempIndex; i--) {
            if (nums[i] > nums[tempIndex] && nums[i] != nums[tempIndex]) {
                tempNewLeftValue = i;
                break;
            }
        }
    }

    void nextPermutation(vector<int>& nums) {
        bool isIncreased = true;
        int n = nums.size();
        for (int i = 0; i < n - 1; i++) {
            if (nums[i] != nums[i + 1] && nums[i] < nums[i + 1]) {
                isIncreased = false;
                break;
            }
        }
        if (isIncreased) {
            reverse(nums.begin(), nums.end());
            return;
        }

        vector<int> temp;
        int tempIndex = firstSmallValueIndex(nums, n);
        int tempNewLeftValue = tempIndex;
        firstGreaterValue(nums, tempNewLeftValue, tempIndex,n);
        swap(nums[tempIndex],nums[tempNewLeftValue]);
 reverse(nums.begin()+tempIndex+1,nums.end());
    }
};