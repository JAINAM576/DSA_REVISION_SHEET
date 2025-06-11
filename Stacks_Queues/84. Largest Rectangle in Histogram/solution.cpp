class Solution {
public:
    void nextSmallerElement(vector<int>& ar, vector<int>& nse) {
        stack<int> st;
        int n = ar.size();
        nse[n - 1] = n;
        st.push(n-1);
        for (int i = n - 2; i >= 0; i--) {
            while (!st.empty() && ar[i] <= ar[st.top()]) {
                st.pop();
            }
            if (st.empty()) {
                nse[i] = n;
                st.push(i);
            } else {
                nse[i] = st.top();
                st.push(i);
            }
        }
    }
    void previousSmallerElement(vector<int>& ar, vector<int>& pse) {
        stack<int> st;
        int n = ar.size();
        pse[0] = -1;
        st.push(0);
        for (int i = 1; i < n; i++) {
            while (!st.empty() && ar[i] <= ar[st.top()]) {
                st.pop();
            }
            if (st.empty()) {
                pse[i] = -1;
                st.push(i);
            } else {
                pse[i] = st.top();
                st.push(i);
            }
        }
    }
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        vector<int> nse(n);
        vector<int> pse(n);
        nextSmallerElement(heights,nse);
        previousSmallerElement(heights,pse);

        int maxi=0;
        for(int i=0;i<n;i++){
            maxi=max(max(maxi,heights[i]*(nse[i]-pse[i]-1)),heights[i]);
        }
        return maxi;
    }
};
