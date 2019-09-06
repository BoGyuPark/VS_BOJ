/*BOJ 16926 배열 돌리기 1*/
#include<iostream>
using namespace std;
int n, m, k, map[301][301];
void Rotate() {
	int sx = 0, sy = 0, ex = n - 1, ey = m - 1;
	while (true) {
		int r = sx, c = sy;
		int temp = map[sx][sy];
		int MaxRow = ex - sx;
		int MaxCol = ey - sy;
		
		if (MaxRow <= 0 || MaxCol <= 0) break;

		//왼
		for (int i = 0; i < MaxCol; i++) {
			map[r][c] = map[r][c + 1];
			c++;
		}
		//위
		for (int i = 0; i < MaxRow; i++) {
			map[r][c] = map[r + 1][c];
			r++;
		}
		//오
		for (int i = 0; i < MaxCol; i++) {
			map[r][c] = map[r][c - 1];
			c--;
		}
		//아
		for (int i = 0; i < MaxRow - 1; i++) {
			map[r][c] = map[r - 1][c];
			r--;
		}
		map[r][c] = temp;
		sx++; sy++; ex--; ey--;
	}
}

void printMap() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) cout << map[i][j] << ' ';
		cout << '\n';
	}
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m >> k;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) cin >> map[i][j];
	}
	for (int i = 0; i < k; i++) Rotate();
	printMap();
}