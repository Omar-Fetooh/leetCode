class Solution {
public:
    string decodeString(string s) {
        stack<string> st;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] != ']') {
                st.push(string(1, s[i]));
            } else {
                string temp;
                while (!st.empty() && st.top() != "[") {
                    temp = st.top() + temp;
                    st.pop();
                }
                st.pop();
                string k;
                while (!st.empty() && isdigit(st.top()[0])) {
                    k = st.top() + k;
                    st.pop();
                }

                int repeatCount = stoi(k);
                string repeated = "";
                for (int j = 0; j < repeatCount; j++) {
                    repeated += temp;
                }

                st.push(repeated);
            }
        }
        string res;
        while (!st.empty()) {
            res = st.top() + res;
            st.pop();
        }

        return res;
    }
};