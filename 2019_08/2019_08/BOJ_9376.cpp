/*BOJ 9376 탈옥*/
#include<iostream>
#include<deque>
#include<vector>
#include<cstring>
using namespace std;
int T, n, m, ans, check[3][103][103]; // 0: OutIn, 1: p1 , 2 : p2 
int dx[] = { 0,0,-1,1 };
int dy[] = { 1,-1,0,0 };
char map[103][103];
/*
	외부에서 접근하는 경우, 탈옥1에서 접근하는 경우, 탈옥2에서 접근하는 경우
	에 대해서 각 문에 대한 최솟값
	'.'인 경우 가중치 0, '#'인 경우 가중치 1 이기때문에 deque를 사용
*/
deque<pair<int, int>> dq;
vector<pair<int, int>> v;

void bfs(int r, int c, int idx) {
	dq.push_back({ r,c });
	check[idx][r][c] = 0;
	while (!dq.empty()) {
		int x = dq.front().first, y = dq.front().second;
		dq.pop_front();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i], ny = y + dy[i];
			if (nx < 0 || ny < 0 || nx >= n + 2 || ny> m + 2) continue;
			if (check[idx][nx][ny] != -1) continue;
			if (map[nx][ny] == '.') {
				dq.push_front({ nx,ny });
				check[idx][nx][ny] = check[idx][x][y];
			}
			else if (map[nx][ny] == '#') {
				dq.push_back({ nx,ny });
				check[idx][nx][ny] = check[idx][x][y] + 1;
			}
		}
	}
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> T;
	for (int t = 0; t < T; t++) {
		v.clear();
		cin >> n >> m;
		for (int i = 0; i < n + 2; i++) {
			for (int j = 0; j < m + 2; j++) {
				if (i == 0 || i == n + 1 || j == 0 || j == m + 1) map[i][j] = '.';
				else {
					cin >> map[i][j];
					if (map[i][j] == '$') {
						v.push_back({ i,j });
						map[i][j] = '.';
					}
				}
			}
		}
		memset(check, -1, sizeof(check));
		bfs(0, 0, 0);
		bfs(v[0].first, v[0].second, 1);
		bfs(v[1].first, v[1].second, 2);

		ans = 2147483647;
		int sum = 0;
		/*
			벽이 아닌 모든 경우에서 세가지의 합의 최솟값을 찾는다.
			문인 경우 세 가지 경우중 하나만 문을 열면 되기 때문에 -2를 한다.

			************************************************
			세가지 시작점에서 하나의 목적지로 이동하는 최단거리
			************************************************

		*/
		for (int i = 0; i < n + 2; i++) {
			for (int j = 0; j < m + 2; j++) {
				if (map[i][j] == '*') continue;
				sum = check[0][i][j] + check[1][i][j] + check[2][i][j];
				if (map[i][j] == '#') sum -= 2;
				if (ans > sum) ans = sum;
			}
		}
		cout << ans << '\n';
	}
}