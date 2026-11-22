class Solution {
public:
    int rearrangeCharacters(string s, string target) {
        sort(s.begin(), s.end());
        sort(target.begin(), target.end());
        int mini = INT_MAX;
        int j = 0;
        for (int i = 0; i < target.size(); i++) {
            int counter = 0;
            int required = 1;
            while (i < target.size() && target[i] == target[i + 1]) {
                required++;
                ++i;
            }

            for (; j < s.size(); j++) {
                if (s[j] == target[i])
                    ++counter;
                else if (target[i] < s[j])
                    break;
                ;
            }
            mini = min(mini, counter / required);
        }
        return mini;
    }
};