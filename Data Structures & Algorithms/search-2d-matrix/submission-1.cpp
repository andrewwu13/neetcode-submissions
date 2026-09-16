class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        // there are 3 possibilities
        // 1. exists in the matrix
        // 2. not found between last integer of prev row and first int of curr row
        // 3. not found between first integer of row and last integer of row
        // 1 and 3 will be found with basic binary search within matrix row
        // we binary search amongst the columns to find the smallest row greater than target
        // then the row we search is actually the row before
        // then we can use BS to find target
        // if 2: then that means we check if row above[m] target > row below[0]: return false
        int low = 0, high = n - 1, mid = 0;
        while (low <= high) {
            int mid = (high + low) / 2;
            if (matrix[mid][m - 1] < target) {
                low = mid + 1;
            } else if (matrix[mid][0] > target) {
                high = mid - 1;
            } else {
                break;
            }
        }
        if (!(low <= high)) {
            return false;
        }
        int row = (low + high) / 2;
        low = 0, high = m - 1;
        while (low <= high) {
            mid = (high + low) / 2;
            if (matrix[row][mid] == target) {
                return true;
            } else if (matrix[row][mid] < target) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return false;
    }
};
