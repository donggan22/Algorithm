/*class Solution {
public:
    int ans = 0;
    bool visit[16] = { false };
    int countArrangement(int n) {
        combi(1, n);
        return ans;
    }
    void combi(int idx, int n)
    {
        if (idx == n + 1)
            ans++;
        for (int i = 1; i <= n; i++)
        {
            if (!visit[i])
            {
                if (i % idx == 0 || idx % i == 0)
                {
                    visit[i] = true;
                    combi(idx + 1, n);
                    visit[i] = false;
                }
            }
        }
    }
};*/
//Runtime : 68ms , Memory 6.2 MB

class Solution {
public:
    int ans = 0;
    bool visit[16] = { false };
    int countArrangement(int n) {
        combi(n, n);
        return ans;
    }
    void combi(int idx, int n)
    {
        if (idx < 1)
            ans++;
        for (int i = 1; i <= n; i++)
        {
            if (!visit[i])
            {
                if (i % idx == 0 || idx % i == 0)
                {
                    visit[i] = true;
                    combi(idx - 1, n);
                    visit[i] = false;
                }
            }
        }
    }
};
//Runtime 8m , Memory 6.2 MB