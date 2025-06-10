class Solution {
public:
    int findPeakElement(vector<int>& nums) {

        int s = 0;
        int e = nums.size();
        int n = e;
        if (e == 1)
            return 0;
        int peak = -1;
        while (s <= e) {
            int mid = s + (e - s) / 2;
            if (mid == 0) {
                if (nums[mid] > nums[mid + 1])
                    return mid;

                s = mid + 1;
            } else if (mid == n - 1) {
                if (nums[mid] > nums[mid - 1])
                    return mid;

                e = mid - 1;
            }

            else if (nums[mid] > nums[mid + 1] && nums[mid] > nums[mid - 1])
                return mid;
            else if (nums[mid] > nums[mid + 1] && nums[mid] < nums[mid - 1])
                e = mid - 1;
            else if (nums[mid] < nums[mid + 1] && nums[mid] > nums[mid - 1])
                s = mid + 1;
            else {
                e = mid - 1;
            }
        }
        return peak;
    }
};

// x y z

// x!=y y!=z

// y>x y<z
// y<x y<z
//         y>x y>z
// y<x y>z

// 2 3 4