/* BOJ 14503 �κ� û�ұ� */
#include<iostream>
using namespace std;
int n, m, x, y, dir, map[51][51], check[51][51], ans;
//			�� �� �� ��
int dx[] = { -1,0,1,0 };
int dy[] = { 0,1,0,-1 };
int backDir[] = { 2,3,0,1 };

void simulate() {
	while (true) {
		if (map[x][y] == 0 && check[x][y]== 0) {
			ans++;
			check[x][y] = true;
		}
		
		//Search
		int cnt = 0;
		for (int i = 0; i < 4; i++) {
			dir = (dir + 3) % 4;
			int nx = x + dx[dir], ny = y + dy[dir];
			if (map[nx][ny] == 0 && check[nx][ny] == 0) {
				x = nx, y = ny;
				break;
			}
			else cnt++;
		}
		//�׹��� ���� �̵� ���� ���
		if (cnt == 4) {
			//���� ������ ���
			int ndir = backDir[dir];
			int nx = x + dx[ndir], ny = y + dy[ndir];
			if (map[nx][ny] == 0) {
				x = nx, y = ny;
			}
			//�ƴ� ���
			else return;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m >> x >> y >> dir;
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) cin >> map[i][j];
	}
	simulate();
	cout << ans;
}