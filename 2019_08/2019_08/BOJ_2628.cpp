/* 2628번 - 종이자르기 */
#include<iostream>
#include<queue>
using namespace std;
int n, m, k, map[205][205], check[205][205], ans;
int dx[] = { 0,0,-1,1 };
int dy[] = { 1,-1,0,0 };
queue<pair<int, int>> q;

void setLine(int order, int idx) {
	//가로
	if (order == 0) {
		for (int i = 0; i <= m; i++) map[idx][i] = -1;
	}
	//세로
	else {
		for (int i = 0; i <= n; i++) map[i][idx] = -1;
	}
}
void printMap() {
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= m; j++) {
			cout << map[i][j] << " ";
		}
		cout << '\n';
	}
	cout << '\n';
}
void findArea() {
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] == 0 && check[i][j] == false) {
				cnt = 1;
				check[i][j] = true;
				q.push({ i,j });
				while (!q.empty()) {
					int x = q.front().first, y = q.front().second;
					q.pop();
					for (int z = 0; z < 4; z++) {
						int nx = x + dx[z], ny = y + dy[z];
						if (nx < 0 || ny < 0 || nx > n || ny > m) continue;
						if (check[nx][ny]) continue;
						if (map[nx][ny] == 0) {
							q.push({ nx,ny });
							check[nx][ny] = true;
							if (nx % 2 == 1 || ny % 2 == 1) {

							}else cnt++;
						}
					}
				}
				if (ans < cnt) ans = cnt;
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> m >> n >> k;
	m = (m - 1) * 2, n = (n - 1) * 2;
	for (int i = 0; i < k; i++) {
		int order, value;
		cin >> order >> value;
		setLine(order, value * 2 - 1);
		//printMap();
	}
	findArea();
	cout << ans;
}