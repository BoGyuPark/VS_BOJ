/*SWEA 5656 벽돌깨기*/
#include<iostream>
#include<cstring>
#include<queue>
using namespace std;
int T, n, m, tc, k,cnt, ans, BlockCnt;
int map[16][13], cpy[16][13], sel[5], check[16][13];
//          우 좌 상 하
int dx[] = { 0,0,-1,1 };
int dy[] = { 1,-1,0,0 };
struct info {
	int x, y, boomSize;
};
queue<info> q;
void printMap() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << map[i][j] << ' ';
		}
		cout << '\n';
	}
	cout << '\n';
}

void boom(int col) {
	//맨 위에 있는 구슬 찾기
	int topRow = -1;
	for (int i = 0; i < n; i++) {
		if (map[i][col] != 0) {
			topRow = i;
			break;
		}
	}
	
	//해당 열에 구슬이 없을 때
	if (topRow == -1) return;

	q.push({ topRow,col,map[topRow][col] - 1 });
	check[topRow][col] = true;

	while (!q.empty()) {
		int x = q.front().x, y = q.front().y, boomSize = q.front().boomSize;
		q.pop();
		map[x][y] = 0;
		cnt++;
		for (int i = 1; i <= boomSize; i++) {
			for (int j = 0; j < 4; j++) {
				int nx = x + dx[j] * i, ny = y + dy[j] * i;
				if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
				if (map[nx][ny] == 0 || check[nx][ny] == true) continue;
				q.push({ nx,ny,map[nx][ny] - 1 });
				check[nx][ny] = true;
			}
		}
	}
}

void down() {
	for (int c = 0; c < m; c++) {
		int emptyCnt = 0;
		for (int r = n - 1; r >= 0; r--) {
			if (map[r][c] == 0) emptyCnt++;
			else {
				swap(map[r + emptyCnt][c], map[r][c]);
			}
		}
	}
}

void cpyMapAndCount() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			map[i][j] = cpy[i][j];
		}
	}
}

void go(int index) {
	if (ans == 0) return;
	if (index == k) {
		cnt = 0;
		for (int j = 0; j < k; j++) {
			memset(check, 0, sizeof(check));
			boom(sel[j]);
			down();
		}
		if (ans > BlockCnt - cnt) ans = BlockCnt - cnt;
		cpyMapAndCount();
		return;
	}
	for (int i = 0; i < m; i++) {
		sel[index] = i;
		go(index + 1);
	}
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> T;
	for (tc = 1; tc <= T; tc++) {
		cin >> k >> m >> n;
		BlockCnt = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cin >> map[i][j];
				cpy[i][j] = map[i][j];
				if (map[i][j] != 0) BlockCnt++;
			}
		}
		ans = 2147483647;
		go(0);
		cout << '#' << tc << ' ' << ans << '\n';
	}
}