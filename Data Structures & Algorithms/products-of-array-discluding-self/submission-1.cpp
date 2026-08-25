class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        // track all seen nums
        int product = 1;
        int zeros = 0;
        for (int num : nums) {
            if (num == 0) {
                ++zeros;
                continue;
            }
            product *= num;
        }
        if (zeros > 1) {
            return vector<int>(nums.size());
        }
        vector<int> res;
        for (int num : nums) {
            if (zeros > 0) {
                res.push_back((num == 0) ? product : 0);
            } else {
                res.push_back(product / num);
            }
        }
        return res;
    }
};
