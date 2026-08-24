class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // build a frequency hash
        // append k largest to result array
        // for k 
        unordered_map<int, int> freq;
        for (int num : nums) {
            ++freq[num];
        }
        vector<int> res;
        for (int i = 0; i < k; ++i) {
            auto it = max_element(freq.begin(), freq.end(), [](const auto& p1, const auto& p2) {
                return p1.second < p2.second;
            });
            res.push_back(it->first);
            freq.erase(it);
        }
        return res;
    }
};
