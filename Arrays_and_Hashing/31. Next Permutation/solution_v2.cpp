class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int firstSmallValueIndex=-1;
        int n = nums.size();
        for(int i=n-1;i>0;i--){
            if(nums[i-1]<nums[i]){
                firstSmallValueIndex=i-1;
                break;
            }
        }
   
        if(firstSmallValueIndex!=-1){

        int nextGreaterValue=firstSmallValueIndex;
        for(int i=n-1;i>firstSmallValueIndex;i--){
            if(nums[i]>nums[firstSmallValueIndex]){
                nextGreaterValue=i;
                break;
            }
        }
        swap(nums[firstSmallValueIndex],nums[nextGreaterValue]);
        }
        return reverse(nums.begin()+firstSmallValueIndex+1,nums.end());
    }
};