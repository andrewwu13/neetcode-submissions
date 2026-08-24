class Solution {
public:
    bool isAnagram(string s, string t) {
        int seen_s[128] = {};
        int seen_t[128] = {};
                
        if (s.size() != t.size()) {
            return false;
        }
        for (char c : s) {
            ++seen_s[c];
        }
        for (char c : t) {
            ++seen_t[c];
        }
        for (int i = 0; i < 128; i++) {
            if (seen_s[i] != seen_t[i]) {
                return false;
            }
        }
        return true;
    }
};
