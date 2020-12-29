class Solution {
public:
    int trap(vector<int>& height) {
        int ans = 0;
        vector<int> left, right;
        left.resize(height.size());
        right.resize(height.size());
        for (int i = 0; i < height.size(); i++)
        {
            if (i == 0)
            {
                left[i] = height[i];
                right[height.size() - i - 1] = height[height.size() - i - 1];
            }
            else
            {
                if (height[i] > left[i - 1])
                    left[i] = height[i];
                else
                    left[i] = left[i - 1];
                if (height[height.size() - i - 1] > right[height.size() - i])
                    right[height.size() - i - 1] = height[height.size() - i - 1];
                else
                    right[height.size() - i - 1] = right[height.size() - i];
            }
        }
        for (int i = 0; i < height.size(); i++)
            ans += min(left[i], right[i]) - height[i];
        return ans;
    }
};
//Time Capacity : 2*height.size() + C