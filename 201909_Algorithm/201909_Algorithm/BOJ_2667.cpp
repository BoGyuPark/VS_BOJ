/*BOJ 2667 단지번호 붙이기*/
#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
int n, check[26][26];
char map[26][26];
int dx[] = { 0,0,-1,1 };
int dy[] = { 1,-1,0,0 };
vector<pair<int, int>> v;
vector<int> ans;
queue<pair<int, int>> q;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
			if (map[i][j] == '1') v.push_back({ i,j });
		}
	}
	for (int i = 0; i < v.size(); i++) {
		int r = v[i].first, c = v[i].second;
		if (map[r][c] == '1' && check[r][c]==false) {
			int cnt = 1;
			check[r][c] = true;
			q.push({ r,c });
			while (!q.empty()) {
				int x = q.front().first, y = q.front().second;
				q.pop();
				for (int j = 0; j < 4; j++) {
					int nx = x + dx[j], ny = y + dy[j];
					if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
					if (check[nx][ny] == false && map[nx][ny] == '1') {
						q.push({ nx,ny });
						check[nx][ny] = true;
						cnt++;
					}
				}
			}
			ans.push_back(cnt);
		}
	}
	sort(ans.begin(), ans.end());
	cout << ans.size() << '\n';
	for (auto i : ans) cout << i << '\n';
}