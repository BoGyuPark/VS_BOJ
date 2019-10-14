#include<iostream>
#include<algorithm>
using namespace std;
int n = 10, map[10][10], check[10][10], ans, OneCnt;
int paperCnt[] = { 0,5,5,5,5,5 };
struct Pos {
	int x, y;
};
bool isInsert(int row, int col, int Size) {
	for (int i = row; i < row + Size; i++) {
		for (int j = col; j < col + Size; j++) {
			if (i >= n || j >= n || map[i][j] == 0 || check[i][j] != 0) return false;
		}
	}
	return true;
}

void setArea(int row, int col, int Size, bool flag) {
	int value = (flag == true ? Size : 0);
	for (int i = row; i < row + Size; i++) {
		for (int j = col; j < col + Size; j++) {
			check[i][j] = value;
		}
	}
}

Pos findNextPos(int x, int y) {
	for (int i = x; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (check[i][j] == 0 && map[i][j] == 1) return Pos({ i, j });
		}
	}
}

void go(int index, int x, int y, int OneCnt) {

	if (ans <= index) return;

	if (OneCnt == 0) {
		ans = min(ans, index);
		return;
	}

	Pos p = findNextPos(x,y);
	for (int i = 5; i >= 1; i--) {
		if (paperCnt[i] > 0) {
			if (isInsert(p.x, p.y, i)) {
				setArea(p.x, p.y, i, true);
				paperCnt[i]--;
				go(index + 1, p.x, p.y, OneCnt - (i*i));
				paperCnt[i]++;
				setArea(p.x, p.y, i, false);
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
			if (map[i][j] == 1) OneCnt++;
		}
	}
	ans = 2147483647;
	go(0, 0, 0, OneCnt);
	if (ans == 2147483647) ans = -1;
	cout << ans;
}