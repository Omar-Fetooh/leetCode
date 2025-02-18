class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
            stack<int>st;
        vector<int>ans;
        for (size_t i = 0; i < asteroids.size(); i++)
        {
            if (asteroids[i] > 0) st.push(asteroids[i]);
            else {
                while (!st.empty() && st.top() > 0 && abs(st.top()) < abs(asteroids[i])) st.pop();
                if (st.empty()||st.top()<0) st.push(asteroids[i]);
                else if (abs(st.top()) == abs(asteroids[i])) st.pop();
                else if (abs(st.top()) < abs(asteroids[i])) st.push(asteroids[i]);
            }
        }

        while (!st.empty())
        {
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans; 
    }
};