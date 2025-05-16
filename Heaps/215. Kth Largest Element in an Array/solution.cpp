class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>> pq;
        for(auto it:nums){
            pq.push(it);
        }
        k--;
        while(k){
            pq.pop();
            k--;
        }
        return pq.top();
    }
};