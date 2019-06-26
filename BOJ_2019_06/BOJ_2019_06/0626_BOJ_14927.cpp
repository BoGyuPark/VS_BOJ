#include<iostream>
using namespace std;
int map[19][19], cpy[19][19], n;
int sel[20], cnt = 0, ans;
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };

void printMap() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << map[i][j] << ' ';
		}
		cout << '\n';
	}
	cout << '\n';
}

void switching(int row, int col) {
	map[row][col] = (map[row][col] + 1) % 2;
	for (int i = 0; i < 4; i++) {
		int nx = row + dx[i], ny = col + dy[i];
		if (nx < 0 || ny < 0 || nx > n || ny > n) continue;
		map[nx][ny] = (map[nx][ny] + 1) % 2;
	}
}

void cpyMap() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			map[i][j] = cpy[i][j];
		}
	}
}

bool solvingProblem() {
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n; j++) {
			if (map[i][j] == 1) {
				switching(i + 1, j);
				cnt++;
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (map[i][j] == 1) {
				return false;
			}
		}
	}
	return true;
}

void dfs(int index) {
	if (index == n) {
		cnt = 0;
		for (int j = 0; j < n; j++) {
			if (sel[j] == 1){
				switching(0, j);
				cnt++;
			}
		}

		if (solvingProblem() && ans > cnt) {
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
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> cpy[i][j];
			map[i][j] = cpy[i][j];
		}
	}
	ans = 2147483647;
	dfs(0);
	if (ans == 2147483647) ans = -1;
	cout << ans;
}