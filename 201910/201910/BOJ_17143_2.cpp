//³¬½Ã¿Õ feat. lovinix
#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
int map[101][101], n, m, k, ans;
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,1,-1 };
struct info {
	int x, y, s, d, z, isAlive;
};
vector<info> v;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	memset(map, -1, sizeof(map));
	cin >> n >> m >> k;
	for (int i = 0; i < k; i++) {
		int r, c, s, d, z;
		cin >> r >> c >> s >> d >> z;
		r--; c--; d--;
		v.push_back({ r,c,s,d,z,true });
		map[r][c] = i;
	}

	for (int c = 0; c < m; c++) {
		//kill shark
		for (int r = 0; r < n; r++) {
			if (map[r][c] != -1) {
				v[map[r][c]].isAlive = false;
				ans += v[map[r][c]].z;
				break;
			}
		}
		//init map, move shark
		memset(map, -1, sizeof(map));
		for (int i = 0; i < v.size(); i++) {
			if (!v[i].isAlive) continue;
			int x = v[i].x, y = v[i].y, d = v[i].d;
			int nx = x + (v[i].s * dx[d]) % (2 * (n - 1));
			int ny = y + (v[i].s * dy[d]) % (2 * (m - 1));
			for (int j = 0; j < 2; j++) {
				if (nx < 0) nx = -nx, d = 1;
				if (nx >= n) nx = (n - 1 - (nx - (n - 1))), d = 0;
				if (ny < 0) ny = -ny, d = 2;
				if (ny >= m) ny = (m - 1 - (ny - (m - 1))), d = 3;
			}
			v[i].x = nx, v[i].y = ny, v[i].d = d;

			//remove overlap
			if (map[nx][ny] == -1) map[nx][ny] = i;
			else {
				if (v[map[nx][ny]].z < v[i].z) {
					v[map[nx][ny]].isAlive = false;
					map[nx][ny] = i;
				}
				else v[i].isAlive = false;
			}
		}
	}
	cout << ans;
}