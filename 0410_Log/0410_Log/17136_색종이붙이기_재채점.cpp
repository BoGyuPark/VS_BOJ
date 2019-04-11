#include<iostream>
#include<vector>
using namespace std;
int a[10][10], info[6] = { 0,5,5,5,5,5 }, ans;
vector<pair<int, int>> v;
bool checkInsert(int row, int col, int Size) {
	if (row + Size > 10 || col + Size > 10) return false;
	for (int i = row; i < row + Size; i++) {
		for (int j = col; j < col + Size; j++) {
			if (i >= 10 || j >= 10 || a[i][j] != 1) return false;
		}
	}
	return true;
}

void paintMap(int row, int col, int Size, int value) {
	for (int i = row; i < row + Size; i++) {
		for (int j = col; j < col + Size; j++) {
			a[i][j] = value + 1;
		}
	}
}

void dfs(int index, int x, int y ,int reCnt, int SqCnt) {
	if (ans <= SqCnt) return;
	if (index == 25 || reCnt == 0) {
		if (ans > SqCnt) ans = SqCnt;
		return;
	}
	for (int i = 5; i > 0; i--) {
		if (info[i] > 0) {
			info[i]--;
			if (checkInsert(x, y, i)) {
				paintMap(x, y, i, i);
				int nx = x, ny = y;
				//´ÙÀ½ 1ÀÇ ÁÂÇ¥
				for (int j = 0; j < v.size(); j++) {
					if (a[v[j].first][v[j].second] == 1) {
						nx = v[j].first; ny = v[j].second;
						break;
					}
				}
				dfs(index + 1, nx, ny, reCnt - (i * i), SqCnt + 1);
				paintMap(x, y, i, 0);
			}
			info[i]++;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			cin >> a[i][j];
			if (a[i][j] == 1) v.push_back({ i,j });
		}
	}
	ans = 2147483647;
	if (v.size() > 0) {
		dfs(0, v[0].first, v[0].second, v.size(), 0);
		if (ans == 2147483647) ans = -1;
	}
	else ans = 0;
	cout << ans;
}