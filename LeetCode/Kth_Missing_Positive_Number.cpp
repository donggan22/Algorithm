class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int idx = 0;
        int num = 0;
        while (k > 0)
        {
            num++;
            if (num == arr[idx])
                idx++;
            else
                k--;
            if (idx >= arr.size())
                return num + k - ;
        }
        return num;
    }
};