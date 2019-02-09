#include<iostream>
#include<queue>
#include<vector>
#include<cstring>
using namespace std;
int w, h, dis[101][101],sx,sy,ex,ey;
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
char map[101][101];
int main() {
	cin >> w >> h;
	//c의 x,y좌표를 얻어 저장 및 map의 정보 저장
	vector<pair<int, int>> cpos;
	for (int i = 0; i < h; i++) {
		cin >> map[i];
		for (int j = 0; j < w; j++)
			if (map[i][j] == 'C')	cpos.push_back(make_pair(i, j));
	}
	//직선의 개수를 저장할 2차원배열을 -1로 초기화
	memset(dis, -1, sizeof(dis));

	queue<pair<int, int> > q;
	sx = cpos[0].first; sy = cpos[0].second;
	ex = cpos[1].first; ey = cpos[1].second;
	//bfs
	q.push(make_pair(sx, sy));
	dis[sx][sy] = 0;
	while (!q.empty()) {
		int x = q.front().first, y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i], ny = y + dy[i];
			while ((nx >= 0 && nx < h && ny >= 0 && ny < w) && map[nx][ny] != '*' ) {
				if (dis[nx][ny] == -1) {
					dis[nx][ny] = dis[x][y] + 1;
					q.push(make_pair(nx, ny));
				}
				nx += dx[i];
				ny += dy[i];
			}
		}
	}
	cout << dis[ex][ey] - 1 << '\n';
}