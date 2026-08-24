class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        std::unordered_map<int, int> seen;
        for (int i = 0; i < (int)nums.size(); i++) {
            if (seen.count(nums[i]) == 1) {
                return true;
            }
            seen[nums[i]] = 1;
        }
        return false;
    }
};