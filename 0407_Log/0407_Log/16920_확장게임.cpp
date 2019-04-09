#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int n, m, p, c[1000][1000], pList[10], ans[11], emptyCnt = 0;
int dx[] = { 0,0,-1,1 };
int dy[] = { 1,-1,0,0 };
char a[1000][1000];
vector < queue<pair<int, int>>> v(10);
void simulation() {
	int insertCnt = 0;
	while (true) {
		int flag = 0;
		for (int i = 1; i <= p; i++) {
			if (v[i].size() == 0) flag++;
			int temp = pList[i];
			while (temp--) {
				int Qsize = v[i].size();
				if (Qsize == 0) break;
				while (Qsize--) {
					int x = v[i].front().first, y = v[i].front().second;
					v[i].pop();
					for (int z = 0; z < 4; z++) {
						int nx = x + dx[z], ny = y + dy[z];
						if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
						if (c[nx][ny] == true) continue;
						if (a[nx][ny] == '.') {
							a[nx][ny] = a[x][y];
							v[i].push({ nx,ny });
							c[nx][ny] = true;
						}
					}
					
				}
			}
		}
		if(flag==p)	return;
	}
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m >> p;
	for (int i = 1; i <= p; i++) cin >> pList[i];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
			//v[index], index라는 숫자의 플레이어에 좌표를 집어넣는다.
			if (a[i][j] >= '1' && a[i][j] <= '9') {
				v[a[i][j] - '0'].push({ i,j });
				c[i][j] = true;
			}
			else if (a[i][j] == '.') emptyCnt++;
		}
	}
	simulation();
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			if(a[i][j]>='1' && a[i][j]<='9')	ans[a[i][j] - '0']++;
		}
	for (int i = 1; i <= p; i++) cout << ans[i] << ' ';
}