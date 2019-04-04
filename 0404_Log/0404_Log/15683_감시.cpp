#include<iostream>
#include<vector>
using namespace std;
int n, m, a[8][8], cpy[8][8], zeroArea, sel[8], ans;
int dx[] = { -1,0,1,0 };
int dy[] = { 0,1,0,-1 };
vector<pair<int, int>> cctv;
int simulation(int i, int j, int dir) {
	int nx = i + dx[dir], ny = j + dy[dir];
	int cnt = 0;
	//벽이 아니고 밖이 아닌경우
	while (cpy[nx][ny] != 6 && (nx >= 0 && ny >= 0 && nx < n && ny < m)) {
		if (cpy[nx][ny] == 0) {
			cpy[nx][ny] = -1;
			cnt++;
		}
		nx += dx[dir]; ny += dy[dir];
	}
	return cnt;
}

void dfs(int index) {
	if (index == cctv.size()) {
		int checkCnt = 0;
		for (int j = 0; j < index; j++) {
			int x = cctv[j].first, y = cctv[j].second;
			int cctvNum = cpy[x][y];
			if (cctvNum == 5) {
				for (int z = 0; z < 4; z++)	checkCnt += simulation(x, y, z);
			}
			else if (cctvNum == 1) checkCnt += simulation(x, y, sel[j]);
			else if (cctvNum == 2) {
				int t = 0;
				if (sel[j] > 2) t = 1;
				for (int z = 0; z < 3; z += 2) checkCnt += simulation(x, y, t + z);
			}
			else if (cctvNum == 3) {
				for (int z = 0; z < 2; z++)	checkCnt += simulation(x, y, (sel[j] + z) % 4);
			}
			else if (cctvNum == 4) {
				for (int z = 0; z < 3; z++)	checkCnt += simulation(x, y, (sel[j] + z) % 4);
			}
		}
		if (ans > zeroArea - checkCnt) ans = zeroArea - checkCnt;
		for (int q = 0; q < n; q++) for (int w = 0; w < m; w++) cpy[q][w] = a[q][w];
		return;
	}
	for (int i = 0; i < 4; i++) {
		sel[index] = i;
		dfs(index + 1);
	}
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) 
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
			cpy[i][j] = a[i][j];
			if (a[i][j] > 0 && a[i][j] < 6) cctv.push_back({ i,j });
			else if (a[i][j] == 0) zeroArea++;
		}
	ans = 2147483647;
	dfs(0);
	cout << ans;
}