#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };
int T, tc, n, k, map[9][9], maxi, check[9][9], ans;
vector<pair<int, int>> v;
void go(int x, int y, int len) {
	ans = max(ans, len);
	check[x][y] = true;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i], ny = y + dy[i];
		if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
		if (check[nx][ny]) continue;
		if (map[x][y] > map[nx][ny])
		{
			go(nx, ny, len + 1);
			check[nx][ny] = false;
		}
	}
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> T;
	for (tc = 1; tc <= T; tc++) {
		cin >> n >> k;
		maxi = 0;
		ans = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> map[i][j];
				maxi = max(maxi, map[i][j]);
			}
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (map[i][j] == maxi) v.push_back({ i,j });
			}
		}

		for (int i = 0; i < v.size(); i++) {
			go(v[i].first, v[i].second, 1);
			memset(check, 0, sizeof(check));
			for (int j = 0; j < n; j++) {
				for (int z = 0; z < n; z++) {
					for (int depth = 1; depth <= k; depth++) {
						if (map[j][z] - depth >= 0) {
							map[j][z] -= depth;
							go(v[i].first, v[i].second, 1);
							memset(check, 0, sizeof(check));
							map[j][z] += depth;
						}
					}
				}
			}
		}
		cout << '#' << tc << ' ' << ans << '\n';
		v.clear();
	}
}