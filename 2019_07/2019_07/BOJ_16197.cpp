/*BOJ 16197 두 동전*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int n, m, sel[10];
//           우 좌 상 하
int dx[] = { 0,0,-1,1 };
int dy[] = { 1,-1,0,0 };
int sx1, sx2, ey1, ey2;
char arr[20][20];
vector<pair<int, int>> v;
int ans;
int isFinish(int nx1, int ny1, int nx2, int ny2) {
	int cnt = 0;
	if (nx1 < 0 || ny1 < 0 || nx1 >= n || ny1 >= m) {
		cnt++;
	}

	if (nx2 < 0 || ny2 < 0 || nx2 >= n || ny2 >= m) {
		cnt++;
	}
	return cnt;
}

int simulation() {
	int dir;
	int x1 = sx1, y1 = ey1, x2 = sx2, y2 = ey2;
	for (int i = 0; i < 10; i++) {
		dir = sel[i];
		int nx1 = x1 + dx[dir], ny1 = y1 + dy[dir];
		int nx2 = x2 + dx[dir], ny2 = y2 + dy[dir];
		int flagNum = isFinish(nx1, ny1, nx2, ny2);
		if (flagNum == 1) {
			return i + 1;
		}
		else if (flagNum == 2) {
			return -1;
		}

		if (arr[nx1][ny1] == '#') {
			nx1 = x1, ny1 = y1;
		}
		else {
			x1 = nx1, y1 = ny1;
		}

		if (arr[nx2][ny2] == '#') {
			nx2 = x2, ny2 = y2;
		}
		else {
			x2 = nx2, y2 = ny2;
		}
	}
	return -2;
}

void go(int index) {
	if (index == 10) {
		int flag = simulation();
		//한개만 넘어간 경우
		if (flag > 0) {
			ans = min(ans, flag);
			return;
		}
		return;
	}
	for (int i = 0; i < 4; i++) {
		sel[index] = i;
		go(index + 1);
	}
}
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 'o') {
				v.push_back({ i,j });
				arr[i][j] = '.';
			}
		}
	}
	sx1 = v[0].first, ey1 = v[0].second;
	sx2 = v[1].first, ey2 = v[1].second;
	ans = 2147483647;
	go(0);
	if (ans == 2147483647) cout << -1;
	else cout << ans;
}