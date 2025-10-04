class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string merged;
        int i = 0, j = 0;
        for (; i < word1.size() && j < word2.size(); i++, j++) {
            merged += word1[i];
            merged += word2[j];
        }
        for (; i < word1.size(); i++) {
            merged += word1[i];
        }
        for (; j < word2.size(); j++) {
            merged += word2[j];
        }

        return merged;
    }
};