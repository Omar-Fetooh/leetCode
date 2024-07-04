class Solution {
public:
    int maxProfit(vector<int>& prices) {
    int mini=prices[0];
    int n=prices.size();
    int profit=0,cost=0;
    for(int i=1;i<n;i++){
        cost=prices[i]-mini;
        profit=max(profit,cost);
        mini=min(mini,prices[i]);
    }
    return profit;
    }
};

// MY INITIAL SOL
//  int n=prices.size(),profit=0;
//      set<int>st;
//      st.insert(prices[n-1]);
//      for(int i=n-2;i>=0;i--){
//         if((*(st.rbegin())-prices[i])>profit) {
//             profit=*(st.rbegin())-prices[i];
//         }
//         st.insert(prices[i]);
//      }
//      return profit;