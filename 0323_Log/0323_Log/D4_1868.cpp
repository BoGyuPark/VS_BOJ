#include<iostream>
#include<queue>
#include<vector>
#include<cstring>
using namespace std;
int tc, T, n;
int dx[] = { -1,-1,-1,0,0,1,1,1 };
int dy[] = { -1,0,1,-1,1,-1,0,1 };
char map[301][301] = { 0, };
int boom[301][301] = { 0, };
vector<pair<int, int>> Click;
queue<pair<int, int>> q;
bool check[90000];
int ClickCnt = 0, Limit;
int totalBoom = 0;
int temp;

int bfs(int index) {
	int c[301][301] = { 0, };
	int boomcnt = 0;
	q.push({ Click[index].first,Click[index].second });
	int x, y;
	c[Click[index].first][Click[index].second] = true;
	while (!q.empty()) {
		int cnt = 0;
		x = q.front().first; y = q.front().second;
		q.pop();
		boomcnt++;
		for (int i = 0; i < 8; i++) {
			int nx = x + dx[i], ny = y + dy[i];
			if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
			if (map[nx][ny] == '*') cnt++;
		}
		if (cnt == 0) {
			boom[x][y] = 0;
			for (int i = 0; i < 8; i++) {
				int nx = x + dx[i], ny = y + dy[i];
				if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
				if (boom[nx][ny] == -1 && c[nx][ny] == false) {
					q.push({ nx,ny });
					c[nx][ny] = true;
				}
			}
		}
		else {
			boom[x][y] = cnt;
		}
	}
	return boomcnt;
}

void dfs(int index) {
	if (totalBoom == Limit) {
		cout << ClickCnt << '\n';
		//cout << '\n';
		memset(boom, -1, sizeof(boom));
		return;
	}
	for (int i = 0; i < Click.size(); i++) {
		if (boom[Click[i].first][Click[i].second] != -1) continue;
		if (check[i] == true) continue;
		check[i] = true;
		ClickCnt++;
		temp = bfs(index);
		totalBoom += temp;
		//cout << index << ' ';

		dfs(index + 1);
		totalBoom = 0;
		ClickCnt=0;
		check[i] = false;
	}
}
int main() {
	cin >> tc;
	for (T = 1; T <= tc; T++) {
		cin >> n;
		memset(boom, -1, sizeof(boom));
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> map[i][j];
				if (map[i][j] == '.') Click.push_back({ i,j });
				else if (map[i][j] == '*') boom[i][j] = -2;
			}
		}
		int ans = 2147483647;
		Limit = Click.size();
		//dfs(0);
		for (int i = 0; i < Limit; i++) {
			//totalBoom = 0;
			dfs(i);
			//memset(boom, -1, sizeof(boom));
		}

		//dfs(0);
		//for (int i = 17; i < Click.size(); i++) {
		//	//첫번째로 클릭
		//	int ClickCnt = 1;
		//	int totalBoom = bfs(i);
		//	for (int j = 0; j < Limit; j++) {
		//		//두번째부터 끝까지 클릭
		//		int nowx = Click[j].first, nowy = Click[j].second;
		//		if (boom[nowx][nowy] != -1) continue;
		//		totalBoom += bfs(j);
		//		ClickCnt++;
		//	}
		//	cout << i << "번째 : " << ClickCnt << '\n';
		//	if (totalBoom == Limit) {
		//		if (ans > ClickCnt) ans = ClickCnt;
		//	}
		//	memset(boom, -1, sizeof(boom));
		//}
		cout << '#' << T << ' ' << ans << '\n';
	}
}