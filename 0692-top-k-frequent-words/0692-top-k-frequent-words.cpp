class Solution {
public:
    struct customP {
        bool operator()(const pair<string, int>& A,
                        const pair<string, int>& B) const {
            if (A.second != B.second) {
                return A.second < B.second;
            }
            return A.first > B.first;
        }
    };
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> mp;
        for (auto word : words) {
            mp[word]++;
        }
        priority_queue<pair<string, int>, vector<pair<string, int>>, customP>
            pq;
        for (auto entry : mp) {
            pq.push(entry);
        }
        vector<string> ans;
        while (k--) {
            ans.push_back(pq.top().first);
            pq.pop();
        }
        return ans;
    }
};