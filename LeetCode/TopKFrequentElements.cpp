//
// Created by 구동관 on 2021/08/09.
// O(NlogN)

#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <queue>

using namespace std;

const bool cmp(pair<int, int> a, pair<int, int> b) {
    return a.second > b.second;
}


class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> map;
        for (int i = 0; i < nums.size(); i++)
        {
            auto it = map.find(nums[i]);
            if (it == map.end())
                map[nums[i]] = 1;
            else
                map[nums[i]]++;
        }

        priority_queue<pair<int, int>> que;
        for (auto it = map.begin(); it != map.end(); it++)
        {
            que.push(pair<int, int>(it->second, it->first));
        }

        vector <int> ans;
        for (int i = 1; i <= k; i++)
        {
            ans.push_back(que.top().second);
            if (que.empty())
                return ans;
            que.pop();
        }
        return ans;
    }
};