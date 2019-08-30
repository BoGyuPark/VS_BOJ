/* BOJ 17142 ¿¬±¸¼Ò 3 */
#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;
int n, m, map[51][51], check[51][51], sel[11], c[251], emptyCnt, ans;
int dx[] = { 0,0,-1,1 };
int dy[] = { 1,-1,0,0 };
vector<pair<int, int>> v;
queue<pair<int, int>> q;

void simulate() {
	memset(check, -1, sizeof(check));
	for (int j = 0; j < m; j++) {
		int x = v[sel[j]].first, y = v[sel[j]].second;
		q.push({ x,y });
		check[x][y] = 0;
	}
	int cnt = 0, MAX = 0;
	while (!q.empty()) {
		int x = q.front().first, y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i], ny = y + dy[i];
			if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
			if (check[nx][ny] != -1) continue;
			if (map[nx][ny] != 1) {
				q.push({ nx,ny });
				check[nx][ny] = check[x][y] + 1;

				if (map[nx][ny] == 0) {
					if (MAX < check[nx][ny]) MAX = check[nx][ny];
					cnt++;
				}		
			}
		}
	}
	if (cnt == emptyCnt && ans > MAX) ans = MAX;
}

void go(int index, int start) {
	if (index == m) {
		simulate();
		return;
	}
	for (int i = start; i < v.size(); i++) {
		if (c[i]) continue;
		c[i] = true;
		sel[index] = i;
		go(index + 1, i);
		c[i] = false;
	}
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
			if (map[i][j] == 2) v.push_back({ i,j });
			else if (map[i][j] == 0) emptyCnt++;
		}
	}
	ans = 2147483647;
	go(0, 0);
	if (ans == 2147483647) ans = -1;
	cout << ans;
}