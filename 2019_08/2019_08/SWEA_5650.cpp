/*5650. [모의 SW 역량테스트] 핀볼 게임*/
#include<iostream>
#include<vector>
using namespace std;
int T, tc, n, map[105][105], ans;
typedef struct {
	int x, y;
}info;
vector<info> warmHall[11];
vector<pair<int, int>> v;
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };
int transDir[6][4] = {
	{0,0,0,0},
	{1,3,0,2},
	{3,0,1,2},
	{2,0,3,1},
	{1,2,3,0},
	{1,0,3,2}
};
info findNextPos(int num, int x, int y) {
	info t;
	for (int i = 0; i < warmHall[num].size(); i++) {
		if (warmHall[num][i].x == x && warmHall[num][i].y == y) continue;
		t.x = warmHall[num][i].x;
		t.y = warmHall[num][i].y;
	}
	return t;
}

void simulate(int sx, int sy, int dir) {
	int x = sx, y = sy;
	int score = 0;
	int nx = x + dx[dir], ny = y + dy[dir];

	while(true)
	{
		//종료조건
		if (map[nx][ny] == -1 || (nx == sx && ny == sy)) break;
		//웜홀
		else if (map[nx][ny] >= 6 && map[nx][ny] <= 10) {
			info t = findNextPos(map[nx][ny], nx, ny);
			x = t.x, y = t.y;
			nx = x + dx[dir], ny = y + dy[dir];
		}
		//블록
		else if(map[nx][ny] >= 1 && map[nx][ny] <= 5) {
			dir = transDir[map[nx][ny]][dir];
			x = nx, y = ny;
			nx = x + dx[dir], ny = y + dy[dir];
			score++;
		}
		else {
			x = nx, y = ny;
			nx += dx[dir], ny += dy[dir];
		}
	}
	if (ans < score) ans = score;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> T;
	for (tc = 1; tc <= T; tc++) {
		cin >> n;
		for (int i = 0; i <= n+1; i++) {
			for (int j = 0; j <= n+1; j++) {
				//외부 벽을 5로 세팅
				if (i == 0 || j == 0 || i == n + 1 || j == n + 1) map[i][j] = 5;
				else {
					cin >> map[i][j];
					if (map[i][j] >= 6) warmHall[map[i][j]].push_back({ i,j });
					else if (map[i][j] == 0) v.push_back({ i,j });
				}
			}
		}
		ans = 0;
		for (int i = 0; i < v.size(); i++) {
			int sx = v[i].first, sy = v[i].second;
			for (int j = 0; j < 4; j++) {
				simulate(sx, sy, j);
			}
		}
		cout << '#' << tc << ' ' << ans << '\n';
		v.clear();
	}
}