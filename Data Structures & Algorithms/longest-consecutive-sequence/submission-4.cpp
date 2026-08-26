class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> seen(nums.begin(), nums.end());
        // starting  points of sequence have no seen[num - 1]
        int res = 0;
        for (int key : seen) {
            if (seen.count(key - 1)) continue;
            int i = 1;
            while (seen.count(key + i)) {
                ++i;
            }
            res = max(res, i);
        }
        return res;
    }
};
