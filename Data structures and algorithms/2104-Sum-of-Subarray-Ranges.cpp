class Solution {
public:
    vector<int>findNSE(vector<int>arr) {
    stack<int>st;
    vector<int>ans;
    for (int i = arr.size() - 1;i >= 0;i--) {
        while (!st.empty() && arr[st.top()] >= arr[i]) st.pop();
        if (st.empty()) ans.push_back(arr.size());
        else ans.push_back(st.top());
        st.push(i);
    }
    reverse(ans.begin(), ans.end());
    return ans;
}
vector<int>findPSEE(vector<int>arr) {
    stack<int>st;
    vector<int>ans;
    for (int i = 0;i < arr.size();i++) {
        while (!st.empty() && arr[st.top()] > arr[i]) st.pop();

        if (st.empty()) ans.push_back(-1);
        else ans.push_back(st.top());
        st.push(i);
    }
    return ans;
}
long long sumSubarrayMins(vector<int>& arr) {
    vector<int>NSE = findNSE(arr);
    vector<int>PSEE = findPSEE(arr);
    long long int total = 0;
    int mod = (int)(1e9 + 7);
    for (int i = 0;i < arr.size();i++) {
        int left = i - PSEE[i];
        int right = NSE[i] - i;
        total = (total + (right * left * 1LL * arr[i]) ) ;
    }
    return total;
}
vector<int> findNGE(vector<int> arr) {
    stack<int>st;
    vector<int>ans;
    for (int i = arr.size() - 1;i >= 0;i--) {
        while (!st.empty() && arr[st.top()] <= arr[i]) st.pop();
        if (st.empty()) ans.push_back(arr.size());
        else ans.push_back(st.top());
        st.push(i);
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

vector<int> findPGEE(vector<int> arr) {
    stack<int>st;
    vector<int>ans;
    for (int i = 0;i < arr.size();i++) {
        while (!st.empty() && arr[st.top()] < arr[i]) st.pop();

        if (st.empty()) ans.push_back(-1);
        else ans.push_back(st.top());
        st.push(i);
    }
    return ans;
}
long long int  sumSubarrayMaxs(vector<int>& arr) {
    vector<int>NGE = findNGE(arr);
    vector<int>PGEE = findPGEE(arr);
   long long int total = 0;
    for (int i = 0;i < arr.size();i++) {
        int left = i - PGEE[i];
        int right = NGE[i] - i;
        total = (total + (right * left * 1LL * arr[i]) );
    }
    return total;
}
long long subArrayRanges(vector<int>& nums) {
    return  sumSubarrayMaxs(nums)- sumSubarrayMins(nums);
}
};