class Solution {
public:
    bool canFormArray(vector<int>& arr, vector<vector<int>>& pieces) {
        if (arr.size() == 0)
            return false;
        unordered_map<int, int> m;
        for (int i = 0; i < arr.size(); i++)
            m.insert(make_pair(arr[i], i));
        for (int i = 0; i < pieces.size(); i++)
        {
            int idx = 0;
            for (int j = 0; j < pieces[i].size(); j++)
            {
                if (j == 0)
                {
                    if (m.end() == m.find(pieces[i][j]))
                        return false;
                    idx = m.find(pieces[i][j])->second + 1;
                }
                else
                {
                    if (arr[idx] == pieces[i][j])
                        idx++;
                    else
                        return false;
                }
            }
        }
        return true;
    }
};