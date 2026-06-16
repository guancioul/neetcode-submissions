class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int is_zero = 0, multi = 1, zero_index = 0;
        int size = nums.size();
        vector<int> result(size);
        for(int i=0; i<nums.size(); i++) {
            if(nums[i] == 0) {
                is_zero++;
                zero_index = i;
            } else {
                multi *= nums[i];
            }
        }

        if(is_zero > 1) return result;
        else if(is_zero == 1) {
            result[zero_index] = multi;
            return result;
        } else {
            for(int i=0; i<size; i++) {
                result[i] = multi / nums[i];
            }
        }
        return result;
    }
};
