class Solution {
public:

	int leastInterval(vector<char>& tasks, int n) {

		map<char, int>mp;
		priority_queue<int> maxHeap;

		for (int i = 0;i < tasks.size();i++) {
			mp[tasks[i]]++;
		}
		
		for (auto x : mp) {
			maxHeap.push(x.second);
		}

		int time = 0;
		queue<pair<int, int>>q;

		while (!q.empty()||!maxHeap.empty())
		{
			++time;

			if (maxHeap.empty() ) {
				time = q.front().second;
			}
			else {
				int cnt = maxHeap.top() - 1;
				maxHeap.pop();
				if (cnt > 0) {
					q.push({ cnt,time + n });
				}
			}

			if (!q.empty() && q.front().second == time) {
				maxHeap.push(q.front().first);
				q.pop();
			}
		}
		return time;
	}

};