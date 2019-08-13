/*BOJ 2583 영역 구하기*/
#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
int n, m, map[101][101], check[101][101], k, cnt;
int dx[] = { 0,0,-1,1 };
int dy[] = { 1,-1,0,0 };
queue<pair<int, int>> q;
vector<int> v;
void init(int sx, int sy, int ex, int ey) {
	for (int i = sx; i < ex; i++) 
		for (int j = sy; j < ey; j++) map[j][i] = 1;
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m >> k;
	for (int i = 0; i < k; i++) {
		int t1, t2, t3, t4;
		cin >> t1 >> t2 >> t3 >> t4;
		init(t1, t2, t3, t4);
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] == 0 && !check[i][j]) {
				cnt++;
				int Size = 1;
				q.push({ i,j });
				check[i][j] = true;
				while (!q.empty()) {
					int x = q.front().first, y = q.front().second;
					q.pop();
					for (int z = 0; z < 4; z++) {
						int nx = x + dx[z], ny = y + dy[z];
						if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
						if (check[nx][ny] || map[nx][ny] == 1) continue;
						q.push({ nx,ny });
						check[nx][ny] = true;
						Size++;
					}
				}
				v.push_back(Size);
			}
		}
	}
	cout << cnt << '\n';
	sort(v.begin(), v.end());
	for (int i = 0; i < v.size(); i++) cout << v[i] << ' ';
}