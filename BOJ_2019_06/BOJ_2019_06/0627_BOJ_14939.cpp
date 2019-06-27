#include<iostream>
using namespace std;
int map[10][10], cpy[10][10], sel[11], cnt, ans;
int dx[] = { 0,0,-1,1 };
int dy[] = { 1,-1,0,0 };

void cpyMap() {
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			map[i][j] = cpy[i][j];
		}
	}
}

void switching(int r, int c) {
	map[r][c] = (map[r][c] + 1) % 2;
	for (int i = 0; i < 4; i++) {
		int nx = r + dx[i], ny = c + dy[i];
		if (nx < 0 || ny < 0 || nx >= 10 || ny >= 10) continue;
		map[nx][ny] = (map[nx][ny] + 1) % 2;
	}
}

bool cal_cnt() {
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 10; j++) {
			if (map[i][j] == 1) {
				switching(i + 1, j);
				cnt++;
			}
		}
	}

	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			if (map[i][j] == 1) {
				return false;
			}
		}
	}
	return true;
}



void dfs(int index) {
	if (index == 10) {
		cnt = 0;
		for (int j = 0; j < 10; j++) {
			if (sel[j] == 1) {
				switching(0, j);
				cnt++;
			}
		}

		if (cal_cnt()) {
			if (ans > cnt) ans = cnt;
		}

		cpyMap();
		return;
	}
	for (int i = 0; i < 2; i++) {
		sel[index] = i;
		dfs(index + 1);
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	for (int i = 0; i < 10; i++)
		for (int j = 0; j < 10; j++) {
			char t;
			cin >> t;
			int value = (t == '#' ? 0 : 1);	//0 : ²¨Áü, 1:ÄÑÁü
			cpy[i][j] = map[i][j] = value;
		}
	ans = 987654321;
	dfs(0);
	if (ans == 987654321) ans = -1;
	cout << ans;
}