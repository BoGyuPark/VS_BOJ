#include<iostream>
#include<string>
#include<queue>
using namespace std;
int tc, T, n;
int dx[] = { 0,0,-1,1 };
int dy[] = { 1,-1,0,0 };
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> tc;
	for (T = 1; T <= tc; T++) {
		cin >> n;
		int a[101][101] = { 0, }, d[101][101] = { 0, }, c[101][101] = { 0, };
		for (int i = 0; i < n; i++) {
			string s; cin >> s;
			for (int j = 0; j < n; j++) a[i][j] = s[j] - '0';
		}
		queue<pair<int, int>> q;
		c[0][0] = true;
		q.push({ 0,0 });
		while (!q.empty()) {
			int x = q.front().first, y = q.front().second;
			q.pop();
			for (int i = 0; i < 4; i++) {
				int nx = x + dx[i], ny = y + dy[i];
				if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
				//방문한적없을때, 방문한적있지만 새로운값이 더 작을때
				if (c[nx][ny] == false || d[x][y] + a[nx][ny] < d[nx][ny]) {
					d[nx][ny] = d[x][y] + a[nx][ny];
					c[nx][ny] = true;
					q.push({ nx,ny });
				}
			}
		}
		cout << '#' << T << ' ' << d[n-1][n-1] << '\n';
	}
}