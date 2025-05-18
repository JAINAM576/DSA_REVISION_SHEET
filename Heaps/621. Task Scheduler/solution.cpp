class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        priority_queue<int> pq;

        vector<int> vec(26, 0);
        for (auto it : tasks) {
            vec[it - 'A']++;
        }
        for (int i = 0; i < 26; i++) {
            if (vec[i] >= 1) {
                pq.push(vec[i]);
            }
        }
        int time = 0;
        while (!pq.empty()) {
            vector<int> temp;

            for (int i = 1; i <= n + 1; i++) {
                if (!pq.empty()) {
                    int freq = pq.top();
                    pq.pop();
                    freq--;
                    temp.push_back(freq);
                }
            }

            for (auto& f : temp) {
                if (f > 0) {
                    pq.push(f);
                }
            }

            if (pq.empty()) {
                time += temp.size();
            } else {
                time += (n + 1);
            }
        }
        return time;
    }
};
