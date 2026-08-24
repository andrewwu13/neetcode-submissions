class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res = {};
        map<vector<int>, vector<string>> seen;
        for (int i = 0; i < strs.size(); i++) {
            vector<int> freq(26, 0);
            for (char s : strs[i]) {
                freq[s - 'a']++;
            }
            seen[freq].push_back(strs[i]);
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