#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;
char a[5][5];
int dx[] = { 0,0,-1,1 };
int dy[] = { 1,-1,0,0 };
int sel[7], c[25], d[5][5], check[5][5], ans = 0;
vector<pair<int, int>> v;

bool bfs(int i, int j) {
	int check[5][5] = { 0, };
	queue<pair<int, int>> q;
	q.push({ i,j });
	check[i][j] = true;
	int sum = 1;
	while (!q.empty()) {
		int x = q.front().first, y = q.front().second;
		q.pop();
		for (int z = 0; z < 4; z++) {
			int nx = x + dx[z], ny = y + dy[z];
			if (nx < 0 || ny < 0 || nx >= 5 || ny >= 5) continue;
			if (check[nx][ny] == true) continue;
			if (d[nx][ny] == 1) {
				q.push({ nx,ny });
				sum++;
				check[nx][ny] = true;
			}
		}
	}
	return (sum == 7);
}

void dfs(int index, int start) {
	if (index == 7) {
		int scnt = 0, ycnt = 0;
		for (int j = 0; j < 7; j++) {
			if (a[v[sel[j]].first][v[sel[j]].second] == 'S') scnt++;
			else ycnt++;
			d[v[sel[j]].first][v[sel[j]].second] = 1;
		}
		if (ycnt >= 4) {
			memset(d, 0, sizeof(d));
			return;
		}
		bool temp = bfs(v[sel[0]].first, v[sel[0]].second);
		//cout << temp << '\n';
		ans += temp;
		memset(d, 0, sizeof(d));
		return;
	}
	for (int i = start; i < 25; i++) {
		if (c[i] == true) continue;
		c[i] = true;
		sel[index] = i;
		dfs(index + 1, i);
		c[i] = false;
	}
}


int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	for (int i = 0; i < 5; i++) 
		for (int j = 0; j < 5; j++) {
			cin >> a[i][j];
			v.push_back({ i,j });
		}
	dfs(0, 0);	
	cout << ans;
}