#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
int tc, T, n, k, a[8][8], c[8][8], ans;
int dx[] = { 0,0,-1,1 };
int dy[] = { 1,-1,0,0 };
vector<pair<int, int>> TopPos;
void dfs(int x, int y) {
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i], ny = y + dy[i];
		if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
		if (c[nx][ny] != -1) continue;
		if (a[x][y] > a[nx][ny]) {
			c[nx][ny] = c[x][y] + 1;
			if (ans < c[nx][ny]) ans = c[nx][ny];
			dfs(nx, ny);
			c[nx][ny] = -1;
		}
	}
}

void simulation() {
	for (int z = 0; z < TopPos.size(); z++) {
		memset(c, -1, sizeof(c));
		c[TopPos[z].first][TopPos[z].second] = 1;
		dfs(TopPos[z].first, TopPos[z].second);
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> T;
	for (tc = 1; tc <= T; tc++) {
		cin >> n >> k;
		int MaxNum = -1;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> a[i][j];
				if (a[i][j] > MaxNum) MaxNum = a[i][j];
			}
		}
	
		for (int i = 0; i < n; i++) 
			for (int j = 0; j < n; j++) 
				if (a[i][j] == MaxNum) TopPos.push_back({ i,j });
			
		ans = -1;
		//깊이가 0인 경우
		simulation();
		//깊이가 1부터 k까지
		for (int i = 1; i <= k; i++) {
			for (int x = 0; x < n; x++) {
				for (int y = 0; y < n; y++) {
					a[x][y] -= i;
					simulation();
					a[x][y] += i;
				}
			}
		}
		cout << '#' << tc << ' ' << ans << '\n';
		TopPos.clear();
	}
}