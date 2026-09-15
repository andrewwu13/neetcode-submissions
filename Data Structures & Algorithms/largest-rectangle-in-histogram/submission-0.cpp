class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        // rectangles are formed at i like 2 stacks again
        // tracking where i is, then take the minimum height from it, multiply by length range 
        // of minimum height of all indexes in that range?

        // so basically we loop through all index, then for each index i
        // the height of the largest rectangle is of height heights[i]
        // width is then computed through getting left and right until we reach a height
        // less than heights[i] or reach respective end of array
        // thats o n^2, so instead of doing that for each, we can pre compute the left and right
        // boundaries for each index i. 
        // to do so, we use a stack to help create 2 boundary arrays where we store boundary index
        // algo is just: if heights[i] < stack.top() then pop 
        // use stack to store the indices of bars in increasing height order
        // basically just for each index i, store nearest smaller bar left & right
        // while height[i] < stack.top() { stack.pop() }
        // boundary[i] = stack.top()

        int res = 0;
        int n = heights.size();
        vector<int> l(n, -1);
        vector<int> r(n, n);
        stack<int> s;
        // left boundary
        for (int i = 0; i < n; i++) {
            while (!s.empty() && heights[i] <= heights[s.top()]) {
                s.pop();
            }
            if (!s.empty()) {
                l[i] = s.top();
            }
            s.push(i);
        }
        s = stack<int>();
        // right 
        for (int i = n - 1; i >= 0; i--) {
            while (!s.empty() && heights[i] <= heights[s.top()]) {
                s.pop();
            }
            if (!s.empty()) {
                r[i] = s.top();
            }
            s.push(i);
        }
        for (int i = 0; i < n; i++) {
            l[i] += 1;
            r[i] -= 1;
            res = max(res, heights[i] * (r[i] - l[i] + 1));
        }
        return res;

        
    }
};
