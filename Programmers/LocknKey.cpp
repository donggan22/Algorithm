#include <string>
#include <vector>
using namespace std;

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
	int keyN;
	int lockN;
	int map[60][60] = { 0, };
	int mkey[4][20][20] = { 0, };
	int mlock[20][20] = { 0, };
	int tmp1, tmp2;
	tmp1 = tmp2 = 0;
	keyN = key.size();
	lockN = lock.size();

	for (int row = 0; row < keyN; row++)
		for (int col = 0; col < keyN; col++)
			mkey[0][row][col] = key[row][col];

	for (int rotate = 0; rotate <= 2; rotate++)
		for (int row = 0; row < keyN; row++)
			for (int col = 0; col < keyN; col++)
				if (mkey[rotate][row][col])
					mkey[rotate + 1][col][keyN - 1 - row] = 1;

	for (int row = 0; row < lockN; row++)
		for (int col = 0; col < lockN; col++)
		{
			mlock[row][col] = lock[row][col];
			if (mlock[row][col] == 0)
				tmp1++;
		}

	for (int row = keyN - 1; row < keyN - 1 + lockN; row++)
		for (int col = keyN - 1; col < keyN - 1 + lockN; col++)
			map[row][col] = mlock[row - keyN + 1][col - keyN + 1];

	for (int r = 0; r < 4; r++)
	{
		for (int row = 0; row < keyN + lockN - 1; row++)
		{
			for (int col = 0; col < keyN + lockN - 1; col++)
			{
				bool flag = true;
				tmp2 = 0;
				for (int keyrow = row; keyrow < row + keyN; keyrow++)
				{
					for (int keycol = col; keycol < col + keyN; keycol++)
					{
						if (keyrow >= keyN - 1 && keyrow < keyN - 1 + lockN && keycol >= keyN - 1 && keycol < keyN - 1 + lockN)
						{
							if (mkey[r][keyrow - row][keycol - col] == 0)
							{
								if (map[keyrow][keycol] != 1)
									flag = false;
							}
							else if (mkey[r][keyrow - row][keycol - col] == 1)
							{
								if (map[keyrow][keycol] != 0)
									flag = false;
								else
									tmp2++;
							}
						}
						if (!flag)
							break;
					}
					if (!flag)
						break;
				}
				if (flag)
					if (tmp1 == tmp2)
						return true;

			}
		}
	}
	return false;
}