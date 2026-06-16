class Solution {
public:
    bool isPalindrome(string s) {
        string temp = "";
        for(auto c:s) {
            if(isalpha(c) || isdigit(c)) temp += tolower(c);
        }
        
        int l = 0, r = temp.size()-1;
        while(r > l) {
            if(temp[l] != temp[r]) return false;
            l++;
            r--;
        }
        return true;
    }
};
