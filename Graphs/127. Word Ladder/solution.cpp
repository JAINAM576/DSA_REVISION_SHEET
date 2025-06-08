class Solution {
public:
    int ladderLength(string beginWord, string endWord,
                     vector<string>& wordList) {

        queue<pair<string, int>> q;
        unordered_set<string> s(wordList.begin(), wordList.end());

        q.push({beginWord, 1});
        s.erase(beginWord);
        int n = beginWord.size();

        // BFS
        while (!q.empty()) {
            string word = q.front().first;
            int stepsTillNow = q.front().second;
            q.pop();

            // IF WORD == TARGET WORD
            if (word == endWord)
                return stepsTillNow;

            // FOR EACH WORD TRYING ALL POSSIBLE WORDS
            for (int i = 0; i < n; i++) {
                char original = word[i];
                for (char c = 'a'; c <= 'z'; c++) {
                    word[i] = c;

                    // IF WORD IN WORDLIST THEN ERASE THE CURRENT WORD AS WE
                    // USED AND PUSH TO QUEUE REMOVING THE WORD TO AVOID LOOPING
                    // AGAIN ON SAME WORD JUST LIKE WE DO WITH VISITED MARK
                    if (s.find(word) != s.end()) {
                        s.erase(word);
                        q.push({word, stepsTillNow + 1});
                    }
                }
                word[i] = original;
            }
        }
        return 0;
    }
};