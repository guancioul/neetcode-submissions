class Solution {
public:
    int dp(vector<int>& nums, int curr, bool first, unordered_map<string, int>& memo) {
        string key = to_string(curr) + "," + to_string(first);
        if(memo.find(key) != memo.end()) return memo[key];
        int result = nums[curr];
        for(int i=2; i<nums.size(); i++) {
            if(first && curr + i == nums.size()-1) continue;
            if(curr + i < nums.size()) {
                result = max(result, nums[curr] + dp(nums, curr+i, first, memo));
            }
        }
        return memo[key] = result;
    }
    int rob(vector<int>& nums) {
        unordered_map<string, int> memo;
        int result = 0;
        for(int i=0; i<nums.size(); i++) {
            if(i == 0) result = max(result, dp(nums, i, 1, memo));
            else result = max(result, dp(nums, i, 0, memo));
        }
        return result;
    }
};
