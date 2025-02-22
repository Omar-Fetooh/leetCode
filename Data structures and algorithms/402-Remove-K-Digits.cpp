class Solution {
public:
    string removeKdigits(string num, int k) {
         stack<char>st;
    for (int i = 0;i < num.size();i++) {
        while (!st.empty() &&k&& st.top() - '0' > num[i] - '0') {
            st.pop();
            k--;
        }
        st.push(num[i]);
    }
    while (k >0) {
        st.pop();
        k--;
    }
    num = \\;
    while (!st.empty()) {
        num += st.top();
        st.pop();
    }
    reverse(num.begin(), num.end());

    while (!num.empty() && num[0] == '0') {
        num.erase(num.begin() + 0);
    }
    if (num.size() == 0) return \0\;
    return num;
    }
};
