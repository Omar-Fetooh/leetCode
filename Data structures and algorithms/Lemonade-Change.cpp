class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
         int five_count = 0, ten_count = 0;
    int curr_cash = 0;
    for (int i = 0;i < bills.size();i++) {

        if (bills[i] == 5) five_count++;
        else if (bills[i] == 10) {
            if (!five_count) return false;
            five_count--;
            ++ten_count;
        }
        else {
            curr_cash = five_count * 5 + ten_count * 10;
            if (curr_cash < bills[i]-5) return false;
            if (ten_count) {
                bills[i] -= 10;
                --ten_count;
            }
             if (bills[i] > 5) {
                five_count -= ((bills[i] / 5) - 1);
                bills[i] -= ((bills[i] / 5) - 1) * 5;
            }
            if (bills[i]>5||five_count<0) return false;
        }
    }
    return true;   
    }
};