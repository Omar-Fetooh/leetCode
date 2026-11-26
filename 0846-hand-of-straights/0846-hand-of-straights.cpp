class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if (hand.size() % groupSize != 0)
            return false;
        map<int, int> mp;
        for (int x : hand)
            mp[x]++;

        while (!mp.empty()) {
            int start = mp.begin()->first;

            for (int i = 0; i < groupSize; i++) {
                auto it = mp.find(start + i);

                if (it == mp.end())
                    return false;

                --it->second;

                if (it->second == 0)
                    mp.erase(it);
            }
        }
        return true;
    }
};