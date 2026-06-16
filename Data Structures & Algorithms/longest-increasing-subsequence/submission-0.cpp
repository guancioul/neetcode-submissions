class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp(2001);
        for(int i=0; i<nums.size(); i++) {
            int temp = nums[i] + 1000;
            int max_inc = 0;
            for(int j=0; j<temp; j++) {
                max_inc = max(dp[j], max_inc);
            }
            dp[temp] = max_inc+1;
        }
        
        int result = 0;
        for(int i=0; i<dp.size(); i++) {
            result = max(result, dp[i]);
        }
        return result;
    }
};
