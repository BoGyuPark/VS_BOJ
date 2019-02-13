#include<iostream>
#include<queue>
#include<algorithm>
#include<vector>
using namespace std;
int n, m, k, sx, sy, ex, ey, sum, cnt = 0;
int dx[] = { 0,0,-1,1 };
int dy[] = { -1,1,0,0 };
int a[101][101], c[101][101];
void FILL(int s1, int s2, int e1, int e2) {
	for (int i = s1 + 1; i <= e1; i++)
		for (int j = s2 + 1; j <= e2; j++) a[i][j] = 1;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> m >> n >> k;
	for (int i = 0; i < k; i++) {
		cin >> sx >> sy >> ex >> ey;
		FILL(sx, sy, ex, ey);
	}
	queue<pair<int, int>> q;
	vector<int> v;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (a[i][j] == 0 && c[i][j] == false) {
				cnt++; sum = 1;
				q.push({ i,j }); c[i][j] = true;
				while (!q.empty()) {
					int x = q.front().first, y = q.front().second; q.pop();
					for (int z = 0; z < 4; z++) {
						int nx = x + dx[z], ny = y + dy[z];
						if (nx >= 1 && ny >= 1 && nx <= n && ny <= m) {
							if (a[nx][ny] == 0 && c[nx][ny] == false) {
								c[nx][ny] = true;
								sum++;
								q.push({ nx,ny });
							}
						}
					}
				}
				v.push_back(sum);
			}
		}
	}
	sort(v.begin(), v.end());
	cout << cnt << '\n';
	for (auto& i : v) cout << i << ' ';
	
}