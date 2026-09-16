class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;
        while (l <= r) {
            int n = (r + l) / 2;
            if (nums[n] < target) {
                l = n + 1; 
            } else if (nums[n] > target) {
                r = n - 1;
            } else {
                return n;
            }
        }
        return -1;
    }
};


