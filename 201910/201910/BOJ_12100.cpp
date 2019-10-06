/*BOJ 2048 (Easy)*/
#include<iostream>
#include<algorithm>
using namespace std;
int n, map[21][21], cpy[21][21], sel[6], ans;
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };
void upAndDown(int dir) {
	if (dir == 0) {
		//위로
		for (int j = 0; j < n; j++) {
			int emptyCnt = 0;
			for (int i = 0; i < n; i++) {
				if (map[i][j] == 0) emptyCnt++;
				else swap(map[i][j], map[i - emptyCnt][j]);
			}
		}
	}
	else {
		//아래로
		for (int j = 0; j < n; j++) {
			int emptyCnt = 0;
			for (int i = n - 1; i >= 0; i--) {
				if (map[i][j] == 0) emptyCnt++;
				else swap(map[i][j], map[i + emptyCnt][j]);
			}
		}
	}
}

void lefeAndRight(int dir) {
	if (dir == 2) {
		//왼쪽으로
		for (int i = 0; i < n; i++) {
			int emptyCnt = 0;
			for (int j = 0; j < n; j++) {
				if (map[i][j] == 0) emptyCnt++;
				else swap(map[i][j], map[i][j - emptyCnt]);
			}
		}
	}
	else {
		//오른쪽으로
		for (int i = 0; i < n; i++) {
			int emptyCnt = 0;
			for (int j = n-1; j >=0 ; j--) {
				if (map[i][j] == 0) emptyCnt++;
				else swap(map[i][j], map[i][j + emptyCnt]);
			}
		}
	}
}

void unionBlock(int dir) {
	if (dir == 0) {
		for (int j = 0; j < n; j++) {
			for (int i = 0; i < n - 1; i++) {
				if (map[i][j] == map[i + 1][j]) {
					map[i][j] += map[i + 1][j];
					map[i + 1][j] = 0;
				}
			}
		}
	}
	else if (dir == 1) {
		for (int j = 0; j < n; j++) {
			for (int i = n - 1; i > 0; i--) {
				if (map[i][j] == map[i - 1][j]) {
					map[i][j] += map[i - 1][j];
					map[i - 1][j] = 0;
				}
			}
		}
	}
	else if (dir == 2) {
		//왼쪽으로 합쳐
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n - 1; j++) {
				if (map[i][j] == map[i][j + 1]) {
					map[i][j] += map[i][j + 1];
					map[i][j + 1] = 0;
				}
			}
		}
	}
	else {
		//오른쪽으로
		for (int i = 0; i < n; i++) {
			for (int j = n - 1; j > 0; j--) {
				if (map[i][j] == map[i][j - 1]) {
					map[i][j] += map[i][j - 1];
					map[i][j - 1] = 0;
				}
			}
		}
	}
}

void printMap() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << map[i][j] << ' ';
		}
		cout << '\n';
	}
	cout << '\n';
}
void simulate() {
	for (int i = 0; i < 5; i++) {
		int dir = sel[i];
		if (dir <= 1) {
			//방향으로 기울이기
			upAndDown(dir);
			//합치기
			unionBlock(dir);
			//다시 방향으로 기울이기
			upAndDown(dir);
		}
		else {
			lefeAndRight(dir);
			unionBlock(dir);
			lefeAndRight(dir);
		}
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