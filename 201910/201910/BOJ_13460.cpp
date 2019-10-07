//BOJ 구슬 탈출 2
#include<iostream>
#include<algorithm>
using namespace std;
int n, m, srx, sry, sbx, sby, sel[11], ans;
char map[11][11], cpy[11][11];
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };
void cpyMap() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			map[i][j] = cpy[i][j];
		}
	}
}
bool moveBall(int *x, int *y, int dir) {
	while (true) {
		int nx = *x + dx[dir], ny = *y + dy[dir];
		if (map[nx][ny] != '.') break;
		swap(map[*x][*y], map[nx][ny]);
		*x = nx, *y = ny;
	}
	if (map[*x + dx[dir]][*y + dy[dir]] == 'O') {
		map[*x][*y] = '.';
		return true;
	}
	else return false;
}

bool whoFirst(int t1, int t2) {
	if (t1 > t2) return true;
	else return false;
}
void simulate() {
	int rx = srx, ry = sry, bx = sbx, by = sby;
	for (int i = 0; i < 10; i++) {
		int dir = sel[i];
		int blueFlag = false, redFlag = false;
		//누가 먼저 이동할지 판단.
		if (dir == 0) {
			if (whoFirst(rx, bx)) {
				blueFlag= moveBall(&bx, &by, dir);
				redFlag= moveBall(&rx, &ry, dir);
			}
			else {
				redFlag = moveBall(&rx, &ry, dir);
				blueFlag = moveBall(&bx, &by, dir);
			}
		}
		else if (dir == 1) {
			if (whoFirst(bx, rx)) {
				blueFlag = moveBall(&bx, &by, dir);
				redFlag = moveBall(&rx, &ry, dir);
			}
			else {
				redFlag = moveBall(&rx, &ry, dir);
				blueFlag = moveBall(&bx, &by, dir);
			}
		}
		else if (dir == 2) {
			if (whoFirst(ry, by)) {
				blueFlag = moveBall(&bx, &by, dir);
				redFlag = moveBall(&rx, &ry, dir);
			}
			else {
				redFlag = moveBall(&rx, &ry, dir);
				blueFlag = moveBall(&bx, &by, dir);
			}
		}
		else {
			if (whoFirst(by, ry)) {
				blueFlag = moveBall(&bx, &by, dir);
				redFlag = moveBall(&rx, &ry, dir);
			}
			else {
				redFlag = moveBall(&rx, &ry, dir);
				blueFlag = moveBall(&bx, &by, dir);
			}
		}
	
		if (redFlag && !blueFlag) {
			ans = min(ans, i+1);
		}
		if (redFlag || blueFlag) return;
	}
}

void go(int index) {
	if (index == 10) {
		simulate();
		cpyMap();
		return;
	}
	for (int i = 0; i < 4; i++) {
		if (index != 0) {
			if (sel[index - 1] <= 1) {
				if (i >= 2) {
					sel[index] = i;
					go(index + 1);
				}
			}
			else {
				if (i <= 1) {
					sel[index] = i;
					go(index + 1);
				}
			}
		}
		else {
			sel[index] = i;
			go(index + 1);
		}
	}
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
			cpy[i][j] = map[i][j];
			if (map[i][j] == 'R') { srx = i, sry = j; }
			else if (map[i][j] == 'B') { sbx= i, sby = j; }
		}
	}
	ans = 2147483647;
	go(0);
	if (ans == 2147483647) ans = -1;
	cout << ans;
}