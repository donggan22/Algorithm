#include <vector>

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int ans = -1;
        int lIdx = 0;
        int rIdx = height.size()-1;

        while(lIdx < rIdx)
        {
            if(ans < (rIdx - lIdx) * min(height[lIdx],height[rIdx]))
                ans = (rIdx - lIdx) * min(height[lIdx],height[rIdx]);
            height[lIdx] > height[rIdx] ? rIdx-- : lIdx++;
        }
        return ans;
    }
};

//
// Created by 구동관 on 2021/05/25.
//