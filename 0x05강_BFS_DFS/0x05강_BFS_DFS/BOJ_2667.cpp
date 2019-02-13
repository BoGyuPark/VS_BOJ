#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
int n, c[26][26], cnt, total = 0;
int dx[] = { 0,0,-1,1 };
int dy[] = { 1,-1,0,0 };
char a[26][26];
int main() {
	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) cin >> a[i][j];
	queue<pair<int, int>> q;
	vector<int> v;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (a[i][j] == '1'&&c[i][j] == false) {
				q.push({ i,j });
				c[i][j] = true;
				cnt = 1;
				total++;
				while (!q.empty()) {
					int x=q.front().first, y=q.front().second; q.pop();
					for (int z = 0; z < 4; z++) {
						int nx = x + dx[z], ny = y + dy[z];
						if (nx >= 0 && ny >= 0 && nx < n && ny < n) {
							if (a[nx][ny] == '1' && c[nx][ny] == false) {
								c[nx][ny] = true;
								cnt++;
								q.push({ nx,ny });
							}
						}
					}
				}
				v.push_back(cnt);
			}
		}
	}
	cout << total << '\n';
	sort(v.begin(), v.end());
	for (auto& i : v) cout << i << '\n';
}