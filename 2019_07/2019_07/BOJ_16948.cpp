/*BOJ 16948 데스나이트*/
#include<iostream>
#include<queue>
#include<cstring>
using namespace std;
int n, map[201][201], sx, sy, ex, ey;
int check[201][201];
int dx[] = { -2,-2,0,0,2,2 };
int dy[] = { -1,1,-2,2,-1,1 };
queue<pair<int, int>> q;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	cin >> sx >> sy >> ex >> ey;
	memset(check, -1, sizeof(check));
	q.push({ sx,sy });
	check[sx][sy] = 0;
	while (!q.empty()) {
		int x = q.front().first, y = q.front().second;
		q.pop();
		for (int i = 0; i < 6; i++) {
			int nx = x + dx[i], ny = y + dy[i];
			if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
			if (check[nx][ny] != -1) continue;
			q.push({ nx,ny });
			check[nx][ny] = check[x][y] + 1;
		}
	}

	cout << check[ex][ey];

}