/*BOJ 17472 다리 만들기 2*/
#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
int n, m, map[11][11], c[11][11], dist[7][7], checkRoad[7][7], parent[7];
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
queue<pair<int, int>> q;
vector<pair<int, int>> land[7];
struct road {
	int sNode, eNode, len;
};
vector<road> v;
bool cmp(road &a, road &b) {
	return a.len < b.len;
}

void markLand(int row, int col, int num) {
	land[num].push_back({ row,col });
	q.push({ row,col });
	c[row][col] = true;
	map[row][col] = num;
	while (!q.empty()) {
		int x = q.front().first, y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i], ny = y + dy[i];
			if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
			if (c[nx][ny] || map[nx][ny] == 0) continue;
			q.push({ nx,ny });
			c[nx][ny] = true;
			map[nx][ny] = num;
			land[num].push_back({ nx,ny });
		}
	}
}

int getParent(int x) {
	if (x == parent[x]) return x;
	return parent[x] = getParent(parent[x]);
}

void unionParent(int a, int b) {
	a = getParent(a);
	b = getParent(b);
	if (a < b) parent[b] = a;
	else parent[a] = b;
}

bool findParent(int a, int b) {
	a = getParent(a);
	b = getParent(b);
	return a == b;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
		}
	}

	//markLand
	int Num = 1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] == 1 && c[i][j] == false) {
				markLand(i, j, Num);
				Num++;
			}
		}
	}
	//각 섬에서 다른 섬으로 거리 측정
	for (int i = 1; i < Num; i++) {
		for (int j = 0; j < land[i].size(); j++) {

			int x = land[i][j].first, y = land[i][j].second;
			int myLandNum = map[x][y];
			for (int z = 0; z < 4; z++) {
				int cnt = 1;
				while (true) {
					int nx = x + dx[z] * cnt, ny = y + dy[z] * cnt;
					if (nx < 0 || ny < 0 || nx >= n || ny >= m) break;
					if (myLandNum == map[nx][ny]) break;
					//다른 섬과 거리
					if (map[nx][ny] != 0 && myLandNum != map[nx][ny]) {
						v.push_back({ myLandNum,map[nx][ny],cnt - 1 });
						v.push_back({ map[nx][ny],myLandNum,cnt - 1 });
						break;
					}
					cnt++;
				}
			}
		}
	}
	
	sort(v.begin(), v.end(), cmp);
	//크루스칼 알고리즘
	for (int i = 1; i < Num; i++) parent[i] = i;
	int possibleCnt = 0, ans = 0;
	for (int i = 0; i < v.size(); i++) {
		if (v[i].len > 1 && !findParent(v[i].sNode, v[i].eNode)) {
			unionParent(v[i].sNode, v[i].eNode);
			possibleCnt++;
			ans += v[i].len;
		}
	}
	if (possibleCnt != Num - 2) ans = -1;
	cout << ans;
}