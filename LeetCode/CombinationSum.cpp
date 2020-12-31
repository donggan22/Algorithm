/*class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector < vector<int>> dp[501];
        sort(candidates.begin(), candidates.end());
        for (int i = 0; i < candidates.size(); i++)
        {
            for (int j = candidates[i]; j <= target; j++)
            {
                if (j - candidates[i] == 0)
                {
                    vector<int> tmp;
                    tmp.push_back(j);
                    dp[j].push_back(tmp);
                    continue;
                }
                if (dp[j - candidates[i]].size() == 0)
                    continue;

                for (int x = dp[j - candidates[i]].size() - 1; x >= 0; x--)
                {
                    vector<int> tmp;
                    tmp = dp[j - candidates[i]][x];
                    tmp.push_back(candidates[i]);
                    dp[j].push_back(tmp);
                }

            }
        }
        return dp[target];
    }
};*/

vector<vector <int>> ans;
void recursive(int sum,int target, int idx, vector<int>& list, vector<int>& candidates)
{
    if (sum == target)
        ans.push_back(list);
    for (int i = idx; i < candidates.size(); i++)
    {
        if (sum + candidates[i] <= target)
        {
            list.push_back(candidates[i]);
            recursive(sum + candidates[i],target, i, list, candidates);
            list.pop_back();
        }
    }
    return;
}

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        ans.clear();
        vector<int> list;
        recursive(0, target, 0, list, candidates);
        return ans;
    }
};
