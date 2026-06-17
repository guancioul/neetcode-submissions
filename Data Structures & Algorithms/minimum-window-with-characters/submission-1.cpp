class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> tr(100), sr(100);
        for(auto c:t) tr[c-'A']++;
        int l = 0, r = 0, result = INT_MAX;
        string ans = "";
        while(r < s.size()) {
            sr[s[r++]-'A']++;
            bool contain = 1;
            for(int i=0; i<tr.size(); i++) {
                if(tr[i] != 0 && tr[i] > sr[i]) {
                    contain = 0;
                    break;
                }
            }
            while(contain) {
                result = min(result, r-l);
                if(r-l == result) ans = s.substr(l, r-l);
                sr[s[l++]-'A']--;
                for(int i=0; i<tr.size(); i++) {
                    if(tr[i] != 0 && tr[i] > sr[i]) {
                        contain = 0;
                        break;
                    }
                }
            }
        }
        return ans;
    }
};
