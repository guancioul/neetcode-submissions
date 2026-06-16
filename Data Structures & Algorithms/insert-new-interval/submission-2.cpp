class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        bool isInsert = 0;
        vector<vector<int>> temp;
        if(intervals.size() == 0) {
            temp.push_back(newInterval);
            return temp;
        }
        for(int i=0; i<intervals.size(); i++) {
            if(intervals[i][0] > newInterval[0] && !isInsert) {
                isInsert = 1;
                temp.push_back(newInterval);
            } 
            temp.push_back(intervals[i]);
        }
        if(!isInsert) temp.push_back(newInterval);

        vector<vector<int>> result;
        result.push_back(temp[0]);
        for(int i=1; i<temp.size(); i++) {
            if(temp[i][0] >= result.back()[0] && temp[i][0] <= result.back()[1]) {
                result.back()[0] = min(temp[i][0], result.back()[0]);
                result.back()[1] = max(temp[i][1], result.back()[1]);
            } else {
                result.push_back(temp[i]);
            }
        }

        return result;
    }
};
