class Solution {
public:
    int maxArea(vector<int>& heights) {
        int l = 0, r = heights.size()-1, width = heights.size()-1;
        int result = 0;
        while(r > l) {
            result = max(min(heights[l], heights[r]) * width, result);
            if(heights[l] > heights[r]) r--;
            else l++;
            width--;
        }
        return result;
    }
};
