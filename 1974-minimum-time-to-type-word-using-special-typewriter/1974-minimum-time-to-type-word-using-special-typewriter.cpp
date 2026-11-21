class Solution {
public:
    int minTimeToType(string word) {
        map<char, int> mp;
        int sum = 0;
        for (int i = 0; i < 26; i++) {
            mp[char('a' + i)] = i;
        }
        for (int i = 0; i < word.size(); i++) {
            int diff = 0;
            if (i == 0)
                diff = abs(mp[word[i]] - mp['a']);
            else
                diff = abs(mp[word[i]] - mp[word[i - 1]]);
            diff = diff > 13 ? 26 - diff : diff;
            sum += diff + 1;
        }
        return sum;
    }
};