class Solution {
   public:
    int characterReplacement(string s, int k) {
        vector<int> rec(26);
        int l = 0, r = 0, result = 0;
        while (r < s.size()) {
            rec[s[r++] - 'A']++;
            int tempMax = 0;
            for (int i = 0; i < 26; i++) {
                tempMax = max(tempMax, rec[i]);
            }
            while(r-l-tempMax > k) {
                rec[s[l++] - 'A']--;
                for (int i = 0; i < 26; i++) {
                    tempMax = max(tempMax, rec[i]);
                }
            }
            result = max(result, r-l);
        }
        return result;
    }
};
