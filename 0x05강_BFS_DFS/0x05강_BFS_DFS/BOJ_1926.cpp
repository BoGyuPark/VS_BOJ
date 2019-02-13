#include<iostream>
#include<cstring>
#include<vector>
using namespace std;
int n, m, a[501][501], c[501][501], cnt = 0, area;
int dx[] = { 0,0,-1,1 };
int dy[] = { 1,-1,0,0 };
void dfs(int x, int y) {
	c[x][y] = true;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i], ny = y + dy[i];
		if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
			if (a[nx][ny] != 0 && c[nx][ny] == 0) {
				area++;
				dfs(nx, ny);
			}
		}
	}
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) cin >> a[i][j];	
	vector<int> areas;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (a[i][j] == 1 && c[i][j] == 0) {
				cnt++; area = 1;
				dfs(i, j);
				areas.push_back(area);
			}
		}
	}
	int maxi = 0;
	for (auto&i : areas) if (maxi < i) maxi = i;
	cout << cnt << '\n' << maxi;
}