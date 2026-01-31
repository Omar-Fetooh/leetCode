class Solution {
public:
    int ladderLength(string beginWord, string endWord,
                     vector<string>& wordList) {
        queue<pair<string, int>> q;
        unordered_set<string> st;
        q.push({beginWord, 1});

        for (auto word : wordList) {
            st.insert(word);
        }

        while (!q.empty()) {
            int steps = q.front().second;
            string word = q.front().first;
            q.pop();

            string temp = word;
            for (int i = 0; i < word.size(); i++) {
                for (char c = 'a'; c <= 'z'; c++) {
                    word[i] = c;
                    if (st.count(word)) {
                        if (word == endWord)
                            return steps + 1;
                        q.push({word, steps + 1});
                        st.erase(word);
                    }
                }
                word = temp;
            }
        }

        return 0;
    }
};