class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, int> seen;
        // convert array to hash for O(1) lookups
        for (int num : nums) {
            if (!seen.count(num)) {
                seen[num] = 1;
            }
        }
        // starting  points of sequence have no seen[num - 1]
        int res = 0;
        for (const auto& [key, _] : seen) {
            if (seen.count(key - 1)) continue;
            int i = 1;
            res = max(res, 1);
            while (seen.count(key + i)) {
                res = max(res, i + 1);
                ++i;
            }
        }
        return res;
    }
};
