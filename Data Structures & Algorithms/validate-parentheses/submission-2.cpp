class Solution {
public:
    bool isValid(string s) {
        unordered_map<char, char> m;
        m['['] = ']';
        m['{'] = '}';
        m['('] = ')';
        stack<char> st;
        for(auto c:s) {
            if(m.find(c) != m.end()) {
                st.push(m[c]);
            } else {
                if(!st.empty() && st.top() == c) st.pop();
                else return false;
            }
        }
        return st.empty();
    }
};
