class Solution {
public:
    bool isValid(string s) {
        stack<char> p;
        unordered_map<char,char> parentheses = {
            {')', '('}, {'}','{'}, {']','['}
        };
        for (char c : s) {
            if (parentheses.count(c)) {
                if (!p.empty() && p.top() == parentheses[c]) {
                    p.pop();
                } else {
                    return false;
                }
            } else {
                p.push(c);
            }
        }
        return p.empty();
    }
};
