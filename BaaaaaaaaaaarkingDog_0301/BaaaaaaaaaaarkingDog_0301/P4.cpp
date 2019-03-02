#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
#include<algorithm>
using namespace std;
int n, m, a[20][20], Limit;
int dx[] = { 0,0,-1,1 };
int dy[] = { 1,-1,0,0 };
vector<pair<int, int>> v, zero;
vector<int> ans;
void bfs() {
	int sum = 0;
	int c[20][20] = { 0, };
	for (int i = 0; i < v.size(); i++) {
		int cnt = 0;
		queue<pair<int, int>> q, con;
		if (c[v[i].first][v[i].second] == false) {
			c[v[i].first][v[i].second] = true;
			q.push({ v[i].first, v[i].second });
			con.push({ v[i].first, v[i].second });

			while (!q.empty()) {
				int x = q.front().first, y = q.front().second;
				q.pop();
				for (int i = 0; i < 4; i++) {
					int nx = x + dx[i], ny = y + dy[i];
					if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
					if (c[nx][ny] == true) continue;
					//'2'ÀÇ ¹ÙµÏµ¹ Å½¹æ
					if (a[nx][ny] == 2) {
						q.push({ nx,ny });
						c[nx][ny] = true;
						con.push({ nx,ny });
					}
				}
			}
			//¹Ù±ùÀÌ 1·Î µÑ·¯½Î¿©ÀÖ´ÂÁö Ã¼Å©
			int moved = 0;
			int bfsSize = con.size();
			while (!con.empty()) {
				int x = con.front().first, y = con.front().second;
				con.pop();
				for (int i = 0; i < 4; i++) {
					int nx = x + dx[i], ny = y + dy[i];
					if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
					if (a[nx][ny] == 0) {
						moved++;
					}
				}
			}
			if (moved == 0) sum += bfsSize;
		}
	}
	ans.push_back(sum);
}


int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
			if (a[i][j] == 2) v.push_back({ i,j });
			else if (a[i][j] == 0)	zero.push_back({ i,j });
		}
	}
	Limit = zero.size();
	int t[400] = { 0, };
	int cnt = 0;
	t[0] = t[1] = 1;

	do {
		vector<pair<int, int> > tempPos;
		//¸Ê º¯°æ
		for (int i = 0; i < Limit; i++) {
			if (t[i] == 1) {
				a[zero[i].first][zero[i].second] = 1;
				tempPos.push_back({ zero[i].first,zero[i].second });
			}
		}
		/*if (t[8] == 1 && t[9] == 1)
			cout << 'a';*/
		// '2'ÀÎ ÁÂÇ¥¿¡¼­ bfs¸¦ µ¹¸°´Ù.
		bfs();

		//¸Ê ¿ø»ó º¹±Í
		for (int i = 0; i < tempPos.size(); i++) {
			a[tempPos[i].first][tempPos[i].second] = 0;
		}

	} while (prev_permutation(t, t + Limit));

	sort(ans.begin(), ans.end());
	if (ans.size() == 0) cout << 0;
	else cout << ans[ans.size() - 1];
}