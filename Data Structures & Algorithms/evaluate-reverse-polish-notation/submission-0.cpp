class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        unordered_set<string> operators = {"+", "-", "*", "/"};
        st.push(stoi(tokens[0]));
        for (int i = 1; i < tokens.size(); ++i) {
            if (operators.count(tokens[i])) {
                int val = st.top();
                st.pop();
                if (tokens[i] == "+") st.top() += val;
                if (tokens[i] == "-") st.top() -= val;
                if (tokens[i] == "*") st.top() *= val;
                if (tokens[i] == "/") st.top() /= val;
            } else {
                st.push(stoi(tokens[i]));
            }
        }
        return st.top();
    }
};
