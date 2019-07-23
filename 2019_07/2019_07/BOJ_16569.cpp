/*BOJ 16569 ȭ��⼳��*/
#include<iostream>
#include<queue>
#include<cstring>
using namespace std;
typedef struct info {
	int x, y, t;
};
struct cmp {
	bool operator()(info a, info b) {
		return a.t > b.t;
	}
};
priority_queue<info, vector<info>, cmp> volcano;
queue<pair<int, int>> q;
int n, m, V, t1, t2, t3, sx, sy, maxH, maxT;
int height[101][101], map[101][101], check[101][101];
int volcano_pos[101][101];
int dx[] = { 0,0,-1,1 };
int dy[] = { 1,-1,0,0 };
void bfs() {
	memset(check, -1, sizeof(check));
	q.push({ sx,sy });
	check[sx][sy] = 0;
	maxH = height[sx][sy];
	while (!q.empty()) {
		int x = q.front().first, y = q.front().second;
		if (maxH < height[x][y]) {
			maxH = height[x][y];
			maxT = check[x][y];
		}
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i], ny = y + dy[i];
			if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
			if (check[nx][ny] != -1) continue;
			if (map[nx][ny] > check[x][y] + 1 && !volcano_pos[nx][ny]) {
				q.push({ nx,ny });
				check[nx][ny] = check[x][y] + 1;
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m >> V >> sx >> sy;
	sx--; sy--;
	for (int i = 0; i < n; i++) 
		for (int j = 0; j < m; j++) cin >> height[i][j];
			
	for (int i = 0; i < V; i++) {
		cin >> t1 >> t2 >> t3;
		map[t1 - 1][t2 - 1] = t3;
		volcano_pos[t1 - 1][t2 - 1] = true;
		volcano.push({ t1 - 1,t2 - 1,t3 });
	}
	//�ð��� ���� ȭ�� ������ �̸� map�� �����صд�.
	while (!volcano.empty()) {
		int x = volcano.top().x, y = volcano.top().y, t = volcano.top().t;
		volcano.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i], ny = y + dy[i];
			if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
			if (check[nx][ny] == true) continue;
			if (map[nx][ny] > t + 1 || map[nx][ny] == 0) {	//ȭ���� �־ ȭ���簡 ���� �� ����
				volcano.push({ nx,ny,t + 1 });
				check[nx][ny] = true;
				map[nx][ny] = t + 1;
			}
		}
	}
	//������ map�� �������� ����̰� ��������.
	bfs();
	cout << maxH << ' ' << maxT;
}