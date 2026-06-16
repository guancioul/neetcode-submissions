class Solution {
public:
    bool valid(int index, int s) {
        return index >= 0 && index < s;
    }
    bool canJump(vector<int>& nums) {
        int s = nums.size();
        queue<int> q;
        vector<bool> visit(s, 0);
        q.push(0);
        visit[0] = 1;
        while(!q.empty()) {
            int curr = q.front();
            if(curr == s-1) return true;
            q.pop();
            for(int i=1; i<=nums[curr]; i++) {
                if(valid(curr-i, s) && visit[curr-i] == 0) {
                    visit[curr-i] = 1;
                    q.push(curr-i);
                }
                if(valid(curr+i, s) && visit[curr+i] == 0) {
                    visit[curr+i] = 1;
                    q.push(curr+i);
                }
            }


        }
        return false;
    }
};
