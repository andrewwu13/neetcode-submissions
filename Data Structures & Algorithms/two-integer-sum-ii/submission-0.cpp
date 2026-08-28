class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        // basically just 2 pointers
        // if sum is too large, move left pointer right 1
        // if sum is too small, move right pointer left 1
        int i = 0, j = numbers.size() - 1;
        while (i < j) {
            if (numbers[i] + numbers[j] > target) {
                --j;
            } else if (numbers[i] + numbers[j] < target) {
                ++i;
            } else {
                return {i + 1, j + 1};
            }
        }
        return {i + 1, j + 1};
    }
};
