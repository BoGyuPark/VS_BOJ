#include<iostream>
#include<queue>
#include<cstring>
#include<algorithm>
using namespace std;
int Test, T, n, m, k, a[21][21];
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
void bfs(int i, int j, vector<pair<int, int>> &v) {
	int c[21][21] = { 0, };
	queue<pair<int, int>> q;
	q.push({ i,j });
	c[i][j] = true;
	k = 1;
	int sum = 0;
	if (a[i][j] == 1) sum = 1;
	while (k <= n * 2) {
		if (q.empty()) break;
		//손해를 보지 않은 경우에 push한다.
		if (k*k + (k - 1)*(k - 1) <= m * sum)	v.push_back({ k,sum });
		k++;
		int Limit = q.size();
		while (Limit--) {
			int x = q.front().first, y = q.front().second;
			q.pop();
			for (int z = 0; z < 4; z++) {
				int nx = x + dx[z], ny = y + dy[z];
				if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
				if (c[nx][ny] == true) continue;
				//집인 경우
				if (a[nx][ny] == 1) sum++;
				c[nx][ny] = true;
				q.push({ nx,ny });
			}
		}

	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> Test;
	for (T = 1; T <= Test; T++) {
		cin >> n >> m;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++) cin >> a[i][j];
			
		vector<pair<int, int>> v;
		for (int i = 0; i < n; i++) 
			for (int j = 0; j < n; j++) bfs(i, j, v);

		sort(v.begin(), v.end());
		cout << '#' << T << ' ' << v[v.size() - 1].second << '\n';
		memset(a, 0, sizeof(0));
	}
}