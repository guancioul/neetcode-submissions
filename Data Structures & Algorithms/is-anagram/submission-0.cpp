class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> sv(26), tv(26);
        for(auto c:s) sv[c-'a']++;
        for(auto c:t) tv[c-'a']++;
        return sv == tv;
    }
};
