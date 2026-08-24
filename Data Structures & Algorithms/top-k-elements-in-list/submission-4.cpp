class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        for (int num : nums) {
            ++freq[num];
        }
        priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int,int>>> heap;
        for (const auto& p : freq) {
            heap.push({p.second, p.first});
            if (heap.size() > k) { 
                heap.pop();
            }
        }

        vector<int> res;
        for (int i = 0; i < k; ++i) {
            res.push_back(heap.top().second);
            heap.pop();
        }
        return res;
    }
};
