class Solution {
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
};

//문제 해결법으로 재귀, dp를 생각했는데 dp가 훨씬 빠를 줄 알고 풀어봤는데 시간복잡도나 공간복잡도나 엉망이다. 잘못 푼거같다 다시 풀어보기.