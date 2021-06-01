//
// Created by 구동관 on 2021/06/01.
//

#include <vector>
#include <queue>
using namespace std;

static const int dir[4][2]{{-1,0},{1,0},{0,-1},{0,1}};

struct point {
    int row;
    int col;
    point(int r,int c){
        row = r;
        col = c;
    }
}typedef point;

int bfs(int row , int col,int m, int n, vector<vector<int>> &grid) {
    int cnt = 0;
    queue<point> que;
    que.push(point(row, col));
    grid[row][col] = 0;
    while (!que.empty()) {
        point p = que.front();
        que.pop();
        cnt++;
        for (int i = 0; i < 4; i++) {
            p.row += dir[i][0];
            p.col += dir[i][1];
            if (p.row >= 0 && p.row < m && p.col >= 0 && p.col < n && grid[p.row][p.col]) {
                grid[p.row][p.col] = 0;
                que.push(p);
            }
            p.row -= dir[i][0];
            p.col -= dir[i][1];
        }
    }
    return cnt;
}

class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int ans = 0;
        int m = grid.size();
        int n = grid[0].size();
        for(int row = 0 ; row < m ; row++)
        {
            for(int col = 0 ; col < n ; col++)
            {
                if(grid[row][col])
                {
                    int t = bfs(row,col,m,n,grid);
                    if(t > ans)
                        ans = t;
                }
            }
        }
        return ans;
    }
};
