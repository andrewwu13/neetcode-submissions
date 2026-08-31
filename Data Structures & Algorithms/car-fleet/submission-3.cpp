class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        // should just be a o(n) time complexity and memory
        // we can get the number of different car fleets by
        // push farthest position to stack: stack.push(pair(position, speed))
        // then for the next, if it can catch up to the car in stack
        // if ((target - position[i]) / speed[i] > (target - position[j]) / speed[j]))
        // then we push to stack, else we can ignore then, return size of stack
        // to catch up: 
        // n = ((target - position[i]) / speed[i])
        stack<double> s;
        int n = position.size();
        vector<pair<int, int>> cars(n);
        for (int i = 0; i < n; i++) {
            cars[i] = {position[i], speed[i]};
        }
        sort(cars.begin(), cars.end(), greater<pair<int, int>>());
        s.push((double)(target - cars[0].first) / cars[0].second);
        for (int i = 1; i < n; i++) {
            double t = (double)(target - cars[i].first) / cars[i].second;
            if (t > s.top()) {
                s.push(t);
            }
        }
        return s.size();
    }
};
