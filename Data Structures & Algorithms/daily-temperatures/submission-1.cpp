class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<pair<int, int>> st;
        int s = temperatures.size();
        vector<int> result(s);
        for(int i=s-1; i>=0; i--) {
            while(!st.empty() && temperatures[i] >= st.top().first) {
                st.pop();
            }
            if(st.empty()) {
                result[i] = 0;
            } else {
                result[i] = st.top().second - i;
            }
            st.push({temperatures[i], i});
        }
        return result;
    }
};
