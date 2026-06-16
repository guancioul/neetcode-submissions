class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        set<int> s;
        for(auto num: nums) {
            s.insert(num);
        }

        vector<int> ts;
        for(auto i: s) {
            ts.push_back(i);
        }

        int result = 0, temp = 1;
        for(int i=1; i<ts.size(); i++) {
            if(ts[i] == ts[i-1]+1) temp ++;
            else {
                result = max(result, temp);
                temp = 1;
            }
        }
        return max(result, temp);
    }
};
