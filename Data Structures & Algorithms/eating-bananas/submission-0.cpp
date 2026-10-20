class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        // it takes ceil(x/k) to finish x pile at rate of k
        // upper bound of k = max size of piles 
        // lower bound of k being 1
        // we want to minimize k, so we can check all values in piles from 1 to max pile size to find time takes for each and get a minimum
        // 
        int l = 1, r = *max_element(piles.begin(), piles.end());
        int res = r;
        while (l <= r) {
            int k = (l + r) / 2;
            long t = 0;
            for (int p : piles) {
                t += ceil(static_cast<double>(p)/k);
            }
            if (t <= h) {
                res = k;
                r = k - 1;
            } else {
                l = k + 1;
            }
        }
        return res;
    }
};
