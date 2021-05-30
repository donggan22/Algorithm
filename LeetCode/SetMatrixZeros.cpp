//
// Created by 구동관 on 2021/05/29.
//

#include <vector>
#include <unordered_set>

using namespace std;

/* sol 1) O(M+N) Space complexity , O(MN) Time complexity
 * Memory Usage less than 42.39%
 */
/*
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int M = matrix.size();
        int N = matrix[0].size();
        vector<int> zeroRow;
        vector<int> zeroCol;
        zeroRow.resize(M);
        zeroCol.resize(N);

        for (int row = 0; row < M; row++)
            for (int col = 0; col < N; col++)
                if (matrix[row][col] == 0)
                    zeroRow[row] = zeroCol[col] = 1;

        for (int row = 0; row < M; row++)
            for (int col = 0; col < N; col++)
                if (zeroRow[row] || zeroCol[col])
                    matrix[row][col] = 0;

    }
};
*/

/* sol 2) Trying to use <unordered_set> data structure
 * O(M+N) Space complexity


class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        unordered_set<int> zeroRow;
        unordered_set<int> zeroCol;

        int M = matrix.size();
        int N = matrix[0].size();

        for (int row = 0; row < M; row++) {
            for (int col = 0; col < N; col++) {
                if (matrix[row][col] == 0) {
                    zeroRow.insert(row);
                    zeroCol.insert(col);
                }
            }
        }

        for (int row = 0; row < M; row++) {
            for (int col = 0; col < N; col++) {
                if (zeroRow.find(row) != zeroRow.end()
                    || zeroCol.find(col) != zeroCol.end()) {
                    matrix[row][col] = 0;
                }
            }
        }
    }
};*/

/* sol 3) no use more sapce
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        bool rowZero = false;
        bool colZero = false;
        for(int row = 0 ;row < matrix.size() ; row++)
        {
            for(int col = 0 ; col< matrix[0].size(); col++)
            {
                if(row == 0 && matrix[row][col] == 0)
                    rowZero = true;
                if(col == 0 && matrix[row][col] == 0)
                    colZero = true;
                if(matrix[row][col] == 0)
                    matrix[0][col] = matrix[row][0] = 0;
            }
        }
        for(int row = 1 ; row < matrix.size();row++)
        {
            for(int col = 1 ;col < matrix[0].size();col++)
            {
                if(matrix[0][col] == 0 || matrix[row][0] == 0)
                    matrix[row][col] = 0;
            }
        }
        if(rowZero)
            for(int col = 0 ; col < matrix[0].size(); col++)
                matrix[0][col] = 0;
        if(colZero)
            for(int row = 0 ; row < matrix.size(); row++)
                matrix[row][0] = 0;
    }
};
 */