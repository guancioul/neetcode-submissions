class Solution {
public:

    string encode(vector<string>& strs) {   
        string temp = "";
        for(int i=0; i<strs.size(); i++) {
            temp += to_string(strs[i].size());
            temp += "#";
            temp += strs[i];
        }
        return temp;
    }

    vector<string> decode(string s) {
        vector<string> result;
        string temp = "";
        int num = 0;
        for(int i=0; i<s.size(); i++) {
            if(isdigit(s[i])) {
                num *= 10;
                num += s[i]-'0';
            } 
            if (s[i] == '#'){
                temp = s.substr(i+1, num);
                result.push_back(temp);
                i += num;
                num = 0;
                temp = "";
            }
        }
        return result;
    }
};
