/*BOJ 1194 ���� ����������,����.*/
#include<iostream>
#include<queue>
#include<cstring>
using namespace std;
int n, m, c[64][51][51], sx, sy, ans;
int dx[] = { 0,0,-1,1 };
int dy[] = { 1,-1,0,0 };
char map[51][51];
struct info {
	int x, y, key;
};
queue<info> q;
void bfs() {
	memset(c, -1, sizeof(c));
	c[0][sx][sy] = 0;
	q.push({ sx,sy,0 });
	while (!q.empty()) {
		int x = q.front().x, y = q.front().y, now_key = q.front().key;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i], ny = y + dy[i];
			if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
			if (c[now_key][nx][ny] != -1) continue;
			if (map[nx][ny] != '#') {
				//���� ��ġ�� ���� ���
				if (map[nx][ny] >= 'A' && map[nx][ny] <= 'F') {
					//�����Ʈ����ũ�� üũ
					if (now_key & (1 << map[nx][ny] - 'A')) {
						c[now_key][nx][ny] = c[now_key][x][y] + 1;
						q.push({ nx,ny,now_key });
					}
				}
				//���� ��ġ�� ������ ���
				else if (map[nx][ny] >= 'a' && map[nx][ny] <= 'f') {
					int next_key = now_key | (1 << map[nx][ny] - 'a');
					c[next_key][nx][ny] = c[now_key][x][y] + 1;
					q.push({ nx,ny,next_key });
				}
				//���� ��ġ�� 1�� ���
				else if (map[nx][ny] == '1') {
					ans = c[now_key][x][y] + 1;
					return;
				}
				else {
					c[now_key][nx][ny] = c[now_key][x][y] + 1;
					q.push({ nx,ny,now_key });
				}
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
			if (map[i][j] == '0') {
				sx = i, sy = j;
			}
		}
	}
	ans = -1;
	bfs();
	cout << ans;
}