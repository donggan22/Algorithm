class Solution {
public:
    bool canJump(vector<int>& nums) {
        for (int i = 1; i < nums.size(); i++)
        {
            if (i > nums[i - 1])
                return false;
            nums[i] = max(i + nums[i], nums[i - 1]);
            if (nums[i] >= nums.size() - 1)
                return true;
        }
        return true;
    }
};
//Time complexity O(n)