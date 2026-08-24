class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res = {};
        unordered_map<string, vector<string>> seen;
        for (const auto& s: strs) {
            vector<int> freq(26, 0);
            for (char c : s) {
                freq[c - 'a']++;
            }
            string key = to_string(freq[0]);
            for (int i = 1; i < 26; ++i) {
                key += "," + to_string(freq[i]);
            }
            seen[key].push_back(s);
        }
        for (const auto& [key, value] : seen) {
            res.push_back(value);
        }
        return res;
    }
};

// one pass?
// get frequency of chars in group[i] as array
// need to create a new frequency array for each new one
// store as frequency array: word
// if group[i] same frequency array, append to value
// finally, iterate through all frequency arrays, append all to a list
// {