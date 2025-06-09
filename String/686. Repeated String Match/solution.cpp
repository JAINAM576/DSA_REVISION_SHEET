class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        vector<int> index;
        int n = a.size();
        int n1 = b.size();
        for (int i = 0; i < n; i++) {
            if (a[i] == b[0]) {
                index.push_back(i);
            }
        }
        int i = 0;
        while (i < index.size()) {
            int steps = 1;
            int j = 0;
            int StartingIndex = index[i];
    
            while (j < n1) {
               
                if (a[StartingIndex] == b[j]) {
                    j++;
                    if(j>=n1)break;
                    if (StartingIndex + 1 >= n) {
                        steps++;
                        StartingIndex = 0;
                    }
                    else{
                        StartingIndex++;
                    }
                }
                else{
                    break;
                }
            }
            
            if(j>=b.size())return steps;
            i++;
        }
        return -1;
    }
};

