class Solution {
	public:
	// Function to find the maximum number of meetings that can
	// be performed in a meeting room.
	struct Meeting
	{
		int startTime;
		int endTime;
	};
	
 static	bool Comp(Meeting m1, Meeting m2) {
		return m1.endTime < m2.endTime;
	}
	
	int maxMeetings(vector<int>& start, vector<int>& end) {
		// Your code here
		vector<Meeting>v;
		for (int i = 0; i < start.size(); i++) {
			v.push_back({ start[i], end[i] });
		}
		sort(v.begin(), v.end(), Comp);
		int cnt = 1, freeTime = v[0].endTime;
		for (int i = 1; i < start.size(); i++) {
			if (v[i].startTime > freeTime) {
				++cnt;
				freeTime = v[i].endTime;
			}
		}
		return cnt;
	}
};
