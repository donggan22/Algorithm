//
// Created by 구동관 on 2021/08/06.
// Time complexity O(N^2)
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int checkRow[9][10] = { 0 , };
        int checkCol[9][10] = { 0, };
        int checkMatrix[3][3][10] = { 0, };

        for (int row = 0; row < 9; row++)
        {
            for (int col = 0; col < 9; col++)
            {
                if (board[row][col] != '.')
                {
                    if (checkRow[row][board[row][col] - '0'] || checkCol[col][board[row][col] - '0'] ||
                        checkMatrix[row / 3][col / 3][board[row][col] - '0'])
                        return false;
                    checkRow[row][board[row][col] - '0'] = checkCol[col][board[row][col] - '0'] = checkMatrix[row / 3][col / 3][board[row][col] - '0'] = 1;
                }
            }
        }
        return true;
    }
};

