// User function Template for C++

//Back-end complete function Template for C++

class Solution {
  public:
    long long solve(vector<int>& bt) {
        // code here
        	sort(bt.begin(), bt.end());
	long long totalWaitingTime = 0;
	vector<int> waitingTimes(bt.size());
	for (int i = 1;i < bt.size();i++) {
		waitingTimes[i] = bt[i-1]+waitingTimes[i-1];
		totalWaitingTime += waitingTimes[i];
	}
	return totalWaitingTime / bt.size();
    }
};