#include<iostream>
#include<queue>
using namespace std;
int T, tc, n, m;
int dx[] = { 0,0,-1,1 };
int dy[] = { 1,-1,0,0 };
int a[21][21];
int bfs(int i, int j) {
	//서비스 영역을 k=n일때까지
	int t = n * 2;
	queue<pair<int, int>> q;
	int c[21][21] = { 0, };
	q.push({ i,j }); c[i][j] = true;
	int cost = 0, k = 2, cnt = 0, MaxCnt = 0;
	if (a[i][j] == 1) { cost += m; cnt++; MaxCnt++; }
	while (t--) {
		int Qsize = q.size();
		while(Qsize--) {
			int x = q.front().first, y = q.front().second;
			q.pop();
			for (int z = 0; z < 4; z++) {
				int nx = x + dx[z], ny = y + dy[z];
				if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
				if (c[nx][ny]) continue;
				q.push({ nx,ny });
				c[nx][ny] = true;
				if (a[nx][ny] == 1) { cost += m; cnt++; }
			}
		}
		if (cost >= (k*k + (k - 1)*(k - 1))) {
			if (MaxCnt < cnt) MaxCnt = cnt;
		}
		k++;
	}
	return MaxCnt;
}


int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> T;
	for (tc = 1; tc <= T; tc++) {
		cin >> n >> m;
		for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) cin >> a[i][j];
		int ans = 0;
		//모든 좌표 완탐
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				int temp = bfs(i, j);
				if (temp > ans) ans = temp;
				//cout << temp << ' ';
			}
		}
		cout << '#' << tc << ' ' << ans << '\n';
	}
}