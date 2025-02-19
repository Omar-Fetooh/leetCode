class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        long long int maxi = *max_element(piles.begin(), piles.end());
        long long int low = 1, high = maxi;
        
        while (low <= high) {
            long long int mid = (low + high) / 2;
            long long int sum = 0;
            for (long long int i = 0; i < piles.size(); i++) {
                sum += ceil((double)piles[i] / (double)mid);
                if(sum>h) break;
            }    
            if (sum <= h) {  // eating fast 
                high = mid - 1;
            } else {        // eating slow
                low = mid + 1;
            }
        }
        return low;
    }
};
