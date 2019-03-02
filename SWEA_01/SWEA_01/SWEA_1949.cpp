#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
int T, Test, n, k, a[8][8], c[8][8], ans;
int dx[] = { 0,0,-1,1 };
int dy[] = { -1,1,0,0 }; 
vector<pair<int, int>> v;
void dfs(int x, int y) {
	for (int j = 0; j < 4; j++) {
		int nx = x + dx[j], ny = y + dy[j];
		if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
		if (a[nx][ny] < a[x][y]) {
			if (c[nx][ny] < c[x][y] + 1) c[nx][ny] = c[x][y] + 1;
			dfs(nx, ny);
		}
	}
}
void solve() {
	for (int i = 0; i < v.size(); i++) {
		memset(c, -1, sizeof(c));
		c[v[i].first][v[i].second] = 1;
		dfs(v[i].first, v[i].second);
		int temp = -1;
		for (int j = 0; j < n; j++) {
			for (int z = 0; z < n; z++) 
				if (c[j][z] > temp) temp = c[j][z];
		}
		if (ans < temp) ans = temp;
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> Test;
	for (T = 1; T <= Test; T++) {
		cin >> n >> k;
		int maxi = -1;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> a[i][j];
				if (maxi < a[i][j]) maxi = a[i][j];
			}
		}
		//가장 높은 봉우리의 좌표를 구해놓는다.
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) 
				if (maxi == a[i][j]) v.push_back({ i,j });
		}
		ans = -1;
		solve();
		for (int q = 1; q <= k; q++) {
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					a[i][j] -= q;
					solve();
					a[i][j] += q;
				}
			}
		}
		cout << '#' << T << ' ' << ans << '\n';
		v.clear();
	}
}