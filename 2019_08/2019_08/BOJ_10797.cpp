/*BOJ 1926 그림*/
#include<iostream>
#include<queue>
using namespace std;
int n, m, map[501][501], check[501][501], cnt, MAX;
int dx[] = { 0,0,-1,1 };
int dy[] = { 1,-1,0,0 };
queue<pair<int, int>> q;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) cin >> map[i][j];
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] == 1 && !check[i][j]) {
				cnt++;
				q.push({ i,j });
				check[i][j] = true;
				int temp = 1;
				while (!q.empty()) {
					int x = q.front().first, y = q.front().second;
					q.pop();
					for (int z = 0; z < 4; z++) {
						int nx = x + dx[z], ny = y + dy[z];
						if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
						if (check[nx][ny]) continue;
						if (map[nx][ny] == 0) continue;
						q.push({ nx,ny });
						check[nx][ny] = true;
						temp++;
					}
				}
				if (MAX < temp) MAX = temp;
			}
		}
	}
	cout << cnt << '\n' << MAX;
}
///*BOJ 10797 10부제*/
//#include<iostream>
//using namespace std;
//int n, t, cnt;
//int main() {
//	cin >> n; n %= 10; for (int i = 0; i < 5; i++) {cin >> t; if (t % 10 == n) cnt++;}cout << cnt;
//}