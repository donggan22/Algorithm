typedef struct ana {
    char alpha[26] = { 0, };
    vector<string> str;
};

bool compare(char src[26], char dst[26])
{
    for (int i = 0; i < 26; i++)
    {
        if (src[i] != dst[i])
            return false;
    }
    return true;
}
char* make(char arr[26], string str)
{
    for (int i = 0; i < str.length(); i++)
        arr[str[i] - 'a']++;
    return arr;
}

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<ana> list;
        for (int i = 0; i < strs.size(); i++)
        {
            char arr[26] = { 0, };
            make(arr, strs[i]);
            bool flag = false;
            for (int j = 0; j < list.size(); j++)
            {
                if (compare(list[j].alpha, arr))
                {
                    list[j].str.push_back(strs[i]);
                    flag = true;
                    break;
                }
            }
            if (!flag)
            {
                ana tmp;
                make(tmp.alpha, strs[i]);
                tmp.str.push_back(strs[i]);
                list.push_back(tmp);
            }
        }

        vector<vector<string>> ans;
        for (int i = 0; i < list.size(); i++)
            ans.push_back(list[i].str);
        return ans;
    }
};
/*Runtime: 740 ms
Memory Usage: 21.2 MB 0*/