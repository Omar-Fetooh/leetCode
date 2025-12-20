class Solution {
public:
    priority_queue<int> pq;
    int lastStoneWeight(vector<int>& stones) {
        for (int i = 0; i < stones.size(); i++) {
            pq.push(stones[i]);
        }

        if (pq.empty())
            return 0;
        while (pq.size() >= 1) {

            if (pq.empty())
                return 0;
            if (pq.size() == 1)
                return pq.top();
            int y = pq.top();
            pq.pop();
            int x = pq.top();
            pq.pop();
            if (x < y)
                pq.push(y - x);
        }
        return 0;
    }
};