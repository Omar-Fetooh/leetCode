class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<string> st;
        for (auto token : tokens) {
            st.push(token);
            if (token == "+" || token == "-" || token == "*" || token == "/") {
                string optr = token;
                st.pop();
                string secondOperand = st.top();
                st.pop();
                string firstOperand = st.top();
                st.pop();

                int result = 0;
                if (optr == "+") {
                    result = stoi(firstOperand) + stoi(secondOperand);
                } else if (optr == "-") {
                    result = stoi(firstOperand) - stoi(secondOperand);
                } else if (optr == "*") {
                    result = stoi(firstOperand) * stoi(secondOperand);
                } else if (optr == "/") {
                    result = stoi(firstOperand) / stoi(secondOperand);
                }
                st.push(to_string(result));
            }
        }
        return stoi(st.top());
    }
};