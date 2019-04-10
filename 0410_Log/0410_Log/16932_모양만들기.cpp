#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;
int n, m, a[1000][1000], c[1000][1000];
int check[1000000];
int dx[] = { 0,0,-1,1 };
int dy[] = { 1,-1,0,0 };
vector<pair<int, int>> v, temp;
queue<pair<int, int>> q;
//  번호  크기
pair<int, int> info[1000][1000];
int num = 0;
void bfs() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int cnt;
			if (a[i][j] == 1 && c[i][j] == false) {
				q.push({ i,j });
				temp.push_back({ i,j });
				c[i][j] = true;
				cnt = 1;
				while (!q.empty()) {
					int x = q.front().first, y = q.front().second;
					q.pop();
					for (int z = 0; z < 4; z++) {
						int nx = x + dx[z], ny = y + dy[z];
						if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
						if (c[nx][ny]) continue;
						if (a[nx][ny] == 1) {
							temp.push_back({ nx,ny });
							q.push({ nx,ny });
							c[nx][ny] = true;
							cnt++;
						}
					}
				}
				//맵에 해당그룹의 크기를 입력한다.
				for (int z = 0; z < temp.size(); z++) {
					info[temp[z].first][temp[z].second] = { num, cnt };
				}
				temp.clear();
				num++;
			}
		}
	}
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
			if (a[i][j] == 0) v.push_back({ i,j });
		}
	}
	//bfs를 통해 1로 이루어진 모형들의 크기를 각각 구해서 좌료에 입력
	bfs();

	int ans = 0;
	for (int i = 0; i < v.size(); i++) {
		int x = v[i].first, y = v[i].second;
		int sum = 1;
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i], ny = y + dy[i];
			if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
			if (info[nx][ny].second > 0) {
				if (check[info[nx][ny].first] == true) continue;
				sum += info[nx][ny].second;
				check[info[nx][ny].first] = true;
			}
		}
		if (ans < sum) ans = sum;
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i], ny = y + dy[i];
			if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
			check[info[nx][ny].first] = false;
		}
	}
	cout << ans;
}