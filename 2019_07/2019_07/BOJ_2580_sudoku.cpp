/*BOJ 2580 sudoku_≥≤±ÿ≈ª√‚*/
#include<iostream>
using namespace std;
int n = 9, map[9][9], finishFlag;
int row[10][10], col[10][10], sector[10][10];
void setSudoku(int x, int y, int value, bool boolValue) {
	row[x][value] = col[y][value] = sector[x / 3 * 3 + y / 3][value] = boolValue;	
}

void go(int index) {
	if (finishFlag) return;
	if (index == 81) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cout << map[i][j] << ' ';
			}
			cout << '\n';
		}
		finishFlag = true;
		return;
	}

	int x = index / 9, y = index % 9;
	if (map[x][y] != 0) go(index + 1);
	else {
		for (int i = 1; i <= 9; i++) {
			if (!row[x][i] && !col[y][i] && !sector[x / 3 * 3 + y / 3][i]) {
				map[x][y] = i;
				setSudoku(x, y, i, true);
				go(index + 1);
				setSudoku(x, y, i, false);
				map[x][y] = 0;
			}
		}
	}
}
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	for (int i = 0; i < n; i++) 
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
			if (map[i][j] != 0) setSudoku(i, j, map[i][j], true);
		}
	go(0);
}