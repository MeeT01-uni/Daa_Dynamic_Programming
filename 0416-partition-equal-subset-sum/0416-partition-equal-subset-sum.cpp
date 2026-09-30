class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int total = 0;
        for (size_t i = 0; i < nums.size(); i++) total += nums[i];
        if (total % 2 != 0) return false;
        int target = total / 2;
        vector<bool> dp(target + 1, false);
        dp[0] = true;
        for (size_t i = 0; i < nums.size(); i++)
            for (int j = target; j >= nums[i]; j--)
                if (dp[j - nums[i]]) dp[j] = true;
        return dp[target];
    }
};