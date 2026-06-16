class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int r = 0, l = 0, result = 0;
        vector<bool> temp(200, 0);
        while(l != s.size()) {
            if(!temp[s[l] - ' ']) {
                temp[s[l] - ' '] = 1;
                l++;
                result = max(result, l-r);
            } else {
                while(temp[s[l] - ' ']) {
                    temp[s[r] - ' '] = 0;
                    r++;
                }
            }
        }

        return result;
    }
};
