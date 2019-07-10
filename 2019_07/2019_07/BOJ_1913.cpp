#include<iostream>
using namespace std;
int n, a[1000][1000], find_num;
//			╩С,©Л,го,аб
int dx[] = { -1,0,1,0 };
int dy[] = { 0,1,0,-1 };
int num = 1, cnt = 1, nx, ny;
int ans_x, ans_y;

void printMap() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << a[i][j] << ' ';
		}
		cout << '\n';
	}
}
void insert_num(int dir) {
	for (int i = 0; i < cnt; i++) {
		nx += dx[dir], ny += dy[dir];
		if (num == find_num) {
			ans_x = nx, ans_y = ny;
		}
		if (num > n*n) break;
		a[nx][ny] = num;
		num++;
	}
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> find_num;
	int sx = n / 2, sy = n / 2;
	a[sx][sy] = num;
	num++;

	nx = sx, ny = sy;
	while (num<=(n*n)) {
		if (cnt % 2 == 0) {
			insert_num(2);
			insert_num(3);
		}
		else {
			insert_num(0);
			insert_num(1);
		}
		cnt++;
	}

	printMap();
	cout << ans_x + 1 << ' ' << ans_y + 1;
}