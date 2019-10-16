#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;
int T, tc, n = 10, m, A, Person[2][101], check[10][10], pSum0, pSum1;
vector<int> map[10][10];
queue<pair<int, int>> q;
struct info {
	int x, y, Size, value;
};
vector<info> power;
int dx[] = { 0,-1,0,1,0 };
int dy[] = { 0,0,1,0,-1 };
void fuse(int x, int y, int cnt, int idx) {
	int fuseCnt = 0;
	memset(check, 0, sizeof(check));
	q.push({ x,y });
	check[x][y] = true;
	map[x][y].push_back(idx);
	while (!q.empty()) {
		int Qsize = q.size();
		while (Qsize--) {
			int x = q.front().first, y = q.front().second;
			q.pop();
			for (int i = 1; i <= 4; i++) {
				int nx = x + dx[i], ny = y + dy[i];
				if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
				if (check[nx][ny]) continue;
				q.push({ nx,ny });
				check[nx][ny] = true;
				map[nx][ny].push_back(idx);
			}
		}
		fuseCnt++;
		if (cnt == fuseCnt) {
			while (!q.empty()) q.pop();
			return;
		}
	}
}

void calPower(int px0, int py0, int px1, int py1) {
	int p0Size = map[px0][py0].size(), p1Size = map[px1][py1].size();

	if (p0Size >= 1 && p1Size == 0) {
		int maxi = 0;
		for (int i = 0; i < p0Size; i++) {
			maxi = max(maxi, power[map[px0][py0][i]].value);
		}
		pSum0 += maxi;
	}
	else if (p1Size >= 1 && p0Size == 0) {
		int maxi = 0;
		for (int i = 0; i < p1Size; i++) {
			maxi = max(maxi, power[map[px1][py1][i]].value);
		}
		pSum1 += maxi;
	}
	else if(p0Size >= 1 && p1Size >= 1){
		int maxSum = 0;
		for (int i = 0; i < p0Size; i++) {
			for (int j = 0; j < p1Size; j++) {
				int tempSum = 0;
				if (map[px0][py0][i] == map[px1][py1][j]) {
					tempSum = power[map[px0][py0][i]].value;
				}
				else {
					tempSum = power[map[px0][py0][i]].value + power[map[px1][py1][j]].value;
				}
				maxSum = max(maxSum, tempSum);
			}
		}
		pSum0 += maxSum;
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> T;
	for (tc = 1; tc <= T; tc++) {
		cin >> m >> A;
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < m; j++) cin >> Person[i][j];
		}
		for (int i = 0; i < A; i++) {
			int x, y, Size, value;
			cin >> y >> x >> Size >> value;
			y--; x--;
			power.push_back({ x,y,Size,value });
			fuse(x, y, Size, i);
		}

		int px0 = 0, py0 = 0, px1 = 9, py1 = 9;
		pSum0 = pSum1 = 0;

		calPower(px0, py0, px1, py1);
		for (int i = 0; i < m; i++) {
			px0 += dx[Person[0][i]], py0 += dy[Person[0][i]];
			px1 += dx[Person[1][i]], py1 += dy[Person[1][i]];
			calPower(px0, py0, px1, py1);
		}
		cout << '#' << tc << ' ' << pSum0 + pSum1 << '\n';
		power.clear();
		memset(map, 0, sizeof(map));
	}
}