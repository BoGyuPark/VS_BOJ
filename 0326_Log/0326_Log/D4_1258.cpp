#include<iostream>
#include<queue>
#include<vector>
#include<tuple>
#include<algorithm>
using namespace std;
int tc, T, n;
int dx[] = { 0,0,-1,1 };
int dy[] = { 1,-1,0,0 };
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> T;
	for (tc = 1; tc <= T; tc++) {
		cin >> n;
		int a[100][100] = { 0, };
		int c[100][100] = { 0, };
		queue<pair<int, int>> q;
		for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) cin >> a[i][j];
		
		vector<tuple<int, int, int>> v;
		int sum = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (a[i][j] != 0 && c[i][j]==false) {
					sum++;
					q.push({ i,j });
					c[i][j] = true;
					int colMax = 0, rowMax = 0;
					while (!q.empty()) {
						int x = q.front().first, y = q.front().second;
						q.pop();
						for (int z = 0; z < 4; z++) {
							int nx = x + dx[z], ny = y + dy[z];
							if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
							if (c[nx][ny] == true) continue;
							if (a[nx][ny] == 0) continue;
							if (nx > rowMax) rowMax = nx;
							if (ny > colMax) colMax = ny;
							c[nx][ny] = true;
							q.push({ nx,ny });
						}
					}
					rowMax = rowMax - i + 1;
					colMax = colMax - j + 1;
					v.push_back(make_tuple(rowMax * colMax, rowMax, colMax));
				}
			}
		}
		sort(v.begin(), v.end());
		cout << '#' << tc << ' ' << sum << ' ';
		for (auto i : v) cout << get<1>(i) << ' ' << get<2>(i)<<' ';
		cout << '\n';
	}
}