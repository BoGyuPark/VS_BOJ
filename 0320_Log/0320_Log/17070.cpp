#include<iostream>
#include<queue>
#include<vector>
#include<tuple>
using namespace std;
int n, a[17][17];
//            하,우,대각선
int dx[] = { 0,1,0,1 };
int dy[] = { 0,0,1,1 };
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) cin >> a[i][j];
	//시작을 항상 0,1에서 시작하고 dir = 2
	queue<tuple<int, int, int>> q;
	q.push({ 0,1,2 });
	int cnt = 0;
	while (!q.empty()) {
		int x, y, dir;
		tie(x, y, dir) = q.front();
		q.pop();
		if (x == n - 1 && y == n - 1) cnt++;
		int minus = 6 - dir - 3;
		if (dir == 3) minus = -1;
		for (int i = 1; i <= 3; i++) {
			if (i == minus) continue;
			int nx = x + dx[i], ny = y + dy[i];
			//벽인지 아닌지 체크
			if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
			if (a[nx][ny] == 1) continue;

			//대각선을 놓기전에 미리 체크하자
			if (i == 3) {
				if (a[nx][ny - 1] != 1 && a[nx - 1][ny] != 1) q.push({ nx,ny,i });
			}
			else q.push({ nx,ny,i });
			
		}
	}
	cout << cnt;
}