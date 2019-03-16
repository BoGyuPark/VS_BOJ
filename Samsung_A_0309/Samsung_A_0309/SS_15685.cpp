#include<iostream>
#include<vector>
using namespace std;
int n, a[105][105], x, y, d, g;
int dx[] = { 0,-1,0,1 };
int dy[] = { 1,0,-1,0 };
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> y >> x >> d >> g;
		a[x][y] = 1;
		vector<int> dirs;
		dirs.push_back(d);
		for (int j = 0; j < g; j++) {
			int dirsSize = dirs.size();
			for (int z = dirsSize - 1; z >= 0; z--) {
				dirs.push_back((dirs[z] + 1) % 4);
			}
		}
		for (int j : dirs) {
			a[x + dx[j]][y + dy[j]] = 1;
			x += dx[j]; y += dy[j];
		}
	}
	int ans = 0;
	for (int i = 0; i < 101; i++) {
		for (int j = 0; j < 101; j++) {
			if (i + 1 >= 101 || j + 1 >= 101) continue;
			if (a[i][j] == 1 && a[i][j + 1] == 1 && a[i + 1][j] == 1 && a[i + 1][j + 1] == 1)
				ans++;
		}
	}
	cout << ans;
}