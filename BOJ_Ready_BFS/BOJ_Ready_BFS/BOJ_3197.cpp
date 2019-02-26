#include<iostream>
#include<queue>
#include<vector>
using namespace std;
int dx[] = { 0,0,-1,1 };
int dy[] = { 1,-1,0,0 };
int n, m, c[1501][1501], sc[1501][1501], days = 0;
vector<pair<int, int> > swan;
char a[1501][1501];
//다음에 사라질 빙하를 nwq에 넣는다.
queue<pair<int, int>> wq, nwq, sq, nsq;
bool bfs() {
	while (!wq.empty()) {
		int x = wq.front().first, y = wq.front().second;
		wq.pop();
		for (int z = 0; z < 4; z++) {
			int nx = x + dx[z], ny = y + dy[z];
			if (nx >= 0 && ny >= 0 && nx < n && ny < m) {
				if (c[nx][ny] == false) {
					if (a[nx][ny] == '.') wq.push({ nx,ny });
					else {
						a[nx][ny] = '.';
						nwq.push({ nx,ny });
					}
					c[nx][ny] = true;
				}
			}
		}
	}
	wq = nwq;
	nwq = queue<pair<int, int> >();

	while (!sq.empty()) {
		int x = sq.front().first, y = sq.front().second;
		sq.pop();
		for (int z = 0; z < 4; z++) {
			int nx = x + dx[z], ny = y + dy[z];
			if (nx == swan[1].first && ny == swan[1].second) return true;
			if (nx >= 0 && ny >= 0 && nx < n && ny < m) {
				if (sc[nx][ny] == false) {
					if (a[nx][ny] == '.') {
						sq.push({ nx,ny });
					}
					else {
						nsq.push({ nx,ny });
					}
					sc[nx][ny] = true;
				}
			}
		}
	}
	sq = nsq;
	nsq = queue<pair<int, int> >();
	return false;
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
			if (a[i][j] == 'L') {
				swan.push_back({ i,j });
				a[i][j] = '.';
			}
			if (a[i][j] == '.') {
				wq.push({ i,j });
				c[i][j] = true;
			}
		}
	sq.push({ swan[0].first,swan[0].second });
	sc[swan[0].first][swan[0].second] = true;
	while (true) {
		days++;
		if (bfs()) break;
	}
	cout << days;
}