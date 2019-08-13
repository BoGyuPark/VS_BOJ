/*BOJ 1743  음식물 피하기*/
#include<iostream>
#include<queue>
using namespace std;
int n, m, k, ans;
int map[101][101], check[101][101];
int dx[] = { 0,0,-1,1 };
int dy[] = { 1,-1,0,0 };
queue<pair<int, int>> q;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m >> k;
	for (int i = 0; i < k; i++) {
		int t1, t2;
		cin >> t1 >> t2;
		map[t1 - 1][t2 - 1] = 1;
	}
	int Size = 1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if(map[i][j]==1 && !check[i][j]){
				Size = 1;
				q.push({ i,j });
				check[i][j] = true;
				while (!q.empty()) {
					int x = q.front().first, y = q.front().second;
					q.pop();
					for (int z = 0; z < 4; z++) {
						int nx = x + dx[z], ny = y + dy[z];
						if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
						if (check[nx][ny]) continue;
						if (map[nx][ny] == 1) {
							q.push({ nx,ny });
							check[nx][ny] = true;
							Size++;
						}
					}
				}
				if (ans < Size) ans = Size;
			}
		}
	}
	cout << ans;
}