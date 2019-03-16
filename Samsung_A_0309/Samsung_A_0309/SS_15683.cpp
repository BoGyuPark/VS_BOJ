#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int n, m, a[9][9], cpy[9][9], sel[8], zerocnt = 0, excnt;
//          상 우 하 좌
int dx[] = { -1,0,1,0 };
int dy[] = { 0,1,0,-1 };
vector<pair<int, int>> cctvlist;
vector<int> ans;
void CCTV(int i, int j, int dir) {
	int x = i, y = j;
	int nx = x + dx[dir], ny = y + dy[dir];
	while (nx >= 0 && ny >= 0 && nx < n && ny < m) {
		if (cpy[nx][ny] != 0) {
			if (cpy[nx][ny] == 6) break;
			nx += dx[dir];
			ny += dy[dir];
			continue;
		}
		cpy[nx][ny] = 9;
		excnt++;
		nx += dx[dir];
		ny += dy[dir];
	}
}

void dfs(int index) {
	if (index == cctvlist.size()) {
		excnt = 0;
		//각 cctv번호에 각 방향에 따라 수행한다.
		for (int j = 0; j < cctvlist.size(); j++) {
			int x = cctvlist[j].first, y = cctvlist[j].second;

			if (cpy[x][y] == 1) CCTV(x, y, sel[j]);
			else if (cpy[x][y] == 2) {
				if (sel[j] % 2 == 0) {CCTV(x, y, 0); CCTV(x, y, 2);	}
				else {CCTV(x, y, 1); CCTV(x, y, 3);	}
			}
			else if (cpy[x][y] == 3) {
				CCTV(x, y, sel[j]);
				CCTV(x, y, (sel[j] + 1) % 4);
			}
			else if (cpy[x][y] == 4) {
				CCTV(x, y, sel[j]);
				CCTV(x, y, (sel[j] + 1) % 4);
				CCTV(x, y, (sel[j] + 2) % 4);
			}
			else{
				for (int k = 0; k < 4; k++) CCTV(x, y, k);
			}
		}
		//CCTV 설치후 사각지대의 크기
		int area = zerocnt - excnt;
		ans.push_back(area);

		//다시복사
		for (int j = 0; j < n; j++) {
			for (int z = 0; z < m; z++) cpy[j][z] = a[j][z];
		}
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
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
			cpy[i][j] = a[i][j];
			if (a[i][j] == 0) zerocnt++;
			if (a[i][j] > 0 && a[i][j] < 6) cctvlist.push_back({ i,j });
		}
	}
	dfs(0);
	sort(ans.begin(), ans.end());
	cout << ans[0];
}