class Solution {
public:
    int trap(vector<int>& height) {
        // for every index i, the area of water that it can contain is
        // min(max height left, max height right) - height[i]
        // we can then make this approach linear time by pre computing
        // max left and max right heights for every index
        // so total will be 3 passes
        vector<int> maxLeft(height.size());
        vector<int> maxRight(height.size());
        int h = 0;
        for (int i = 0; i < height.size(); i++) {
            h = max(h, height[i]);
            maxLeft[i] = h;
        }
        h = 0;
        for (int i = height.size() - 1; i >= 0; i--) {
            h = max(h, height[i]);
            maxRight[i] = h;
        }
        int area = 0;
        for (int i = 0; i < height.size(); i++) {
            area += min(maxLeft[i], maxRight[i]) - height[i];
        }
        return area;
    }
};
