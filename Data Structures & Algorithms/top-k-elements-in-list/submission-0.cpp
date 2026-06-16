class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> map;
        for(int i=0; i<nums.size(); i++) {
            map[nums[i]]++;
        }
        priority_queue<pair<int, int>> pq;
        for(auto [key, value]: map) {
            pq.push({value, key});
        }

        vector<int> result;
        for(int i=0; i<k; i++) {
            result.push_back(pq.top().second);
            pq.pop();
        }
        return result;
    }
};
