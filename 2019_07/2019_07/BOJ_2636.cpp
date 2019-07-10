#include<iostream>
#include<queue>
using namespace std;
int n, m, a[101][101], ori_cheeze_cnt;
int check[101][101];
int dx[] = { 0,0,-1,1 };
int dy[] = { 1,-1,0,0 };
queue<pair<int, int>> q, waiting;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
			if (a[i][j] == 1) {
				ori_cheeze_cnt++;
			}
		}
	}
	q.push({ 0,0 });
	check[0][0] = true;
	int cheeze_cnt = 0, round_cnt = 0;
	while (true)
	{
		round_cnt++;
		cheeze_cnt = 0;
		while (!q.empty()) {
			int x = q.front().first, y = q.front().second;
			q.pop();
			for (int i = 0; i < 4; i++) {
				int nx = x + dx[i], ny = y + dy[i];
				if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
				if (check[nx][ny] == true) continue;
				if (a[nx][ny] == 0) {
					q.push({ nx,ny });
					check[nx][ny] = true;
				}
				else if (a[nx][ny] == 1) {
					a[nx][ny] = 2;
					waiting.push({ nx,ny });
					cheeze_cnt++;
				}
			}
		}

		q = waiting;
		while (!waiting.empty()) {
			int x = waiting.front().first, y = waiting.front().second;
			waiting.pop();
			a[x][y] = 0;
			ori_cheeze_cnt--;
		}
		if (ori_cheeze_cnt == 0) break;
	}
	
	cout << round_cnt << '\n' << cheeze_cnt;

}
