class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int res = nums[0], curMax = nums[0], curMin = nums[0];
        for (size_t i = 1; i < nums.size(); i++) {
            int x = nums[i];
            int tmpMax = max(x, max(curMax * x, curMin * x));
            curMin = min(x, min(curMax * x, curMin * x));
            curMax = tmpMax;
            res = max(res, curMax);
        }
        return res;
    }
};