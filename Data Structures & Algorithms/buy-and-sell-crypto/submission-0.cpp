class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int m = INT_MAX, result = 0;
        for(int i=0; i<prices.size(); i++) {
            m = min(m, prices[i]);
            result = max(result, prices[i] - m);
        }
        return result;
    }
};
