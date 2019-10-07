/*BOJ 2048 (Easy)*/
#include<iostream>
#include<algorithm>
using namespace std;
int n, map[21][21], cpy[21][21], sel[6], ans;
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };
void moveBoard(int rowFlag, int start, int op) {
	if (rowFlag) {
		for (int j = 0; j < n; j++) {
			int emptyCnt = 0;
			int i = start;
			while (0 <= i &&  i < n) {
				if (map[i][j] == 0) emptyCnt++;
				else swap(map[i][j], map[i + emptyCnt * op][j]);
				i += (op*-1);
			}
		}
	}
	else {
		for (int i = 0; i < n; i++) {
			int emptyCnt = 0;
			int j = start;
			while (0 <= j && j < n) {
				if (map[i][j] == 0) emptyCnt++;
				else swap(map[i][j], map[i][j + emptyCnt * op]);
				j += (op*-1);
			}
		}
	}
}

void unionBlock(int rowFlag, int value, int s, int e, int op) {
	if (rowFlag) {
		for (int j = 0; j < n; j++) {
			int i = value;
			while (s <= i && i < e) {
				if (map[i][j] == map[i + op][j]) {
					map[i][j] += map[i + op][j];
					map[i + op][j] = 0;
				}
				i += op;
			}
		}
	}
	else {
		for (int i = 0; i < n; i++) {
			int j = value;
			while (s <= j && j < e) {
				if (map[i][j] == map[i][j + op]) {
					map[i][j] += map[i][j + op];
					map[i][j + op] = 0;
				}
				j += op;
			}
		}
	}
}

void simulate() {
	for (int i = 0; i < 5; i++) {
		int dir = sel[i];
		if (dir == 0) moveBoard(1, 0, -1), unionBlock(1,0,0,n-1,1), moveBoard(1, 0, -1);
		else if (dir == 1) moveBoard(1, n - 1, 1), unionBlock(1,n-1,1,n,-1), moveBoard(1, n - 1, 1);
		else if (dir == 2) moveBoard(0, 0, -1), unionBlock(0,0,0,n-1,1), moveBoard(0, 0, -1);
		else moveBoard(0, n - 1, 1), unionBlock(0,n-1,1,n,-1), moveBoard(0, n - 1, 1);
	}
}

void go(int index) {
	if (index == 5) {
		simulate();
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				ans = max(ans, map[i][j]);
				map[i][j] = cpy[i][j];
			}
		}
		return;
	}
	for (int i = 0; i < 4; i++) {
		sel[index] = i;
		go(index + 1);
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
			cpy[i][j] = map[i][j];
			ans = max(map[i][j], ans);
		}
	}
	go(0);
	cout << ans;
}