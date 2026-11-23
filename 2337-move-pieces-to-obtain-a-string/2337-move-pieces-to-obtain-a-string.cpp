class Solution {
public:
    bool canChange(string start, string target) {
        int i = 0, j = 0;
        int n = start.size();

        string a, b;

        for (char c : start)
            if (c != '_')
                a += c;

        for (char c : target)
            if (c != '_')
                b += c;

        if (a != b)
            return false;

        while (i < n) {
            if (target[i] == 'L') {
                j = max(j, i);

                while (j < n && start[j] != 'L') {
                    if (start[j] == 'R')
                        return false;
                    ++j;
                }

                if (j == n)
                    return false;
                ++j;
            }
            ++i;
        }

        i = n - 1;
        j = n - 1;

        while (i >= 0) {
            if (target[i] == 'R') {
                j = min(j, i);

                while (j >= 0 && start[j] != 'R') {
                    if (start[j] == 'L')
                        return false;
                    --j;
                }

                if (j < 0)
                    return false;
                --j;
            }
            --i;
        }

        return true;
    }
};