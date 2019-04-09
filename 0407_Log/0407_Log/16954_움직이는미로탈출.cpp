#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
typedef struct info {
	int x, y, alive;
};
using namespace std;
vector<info> wList;
queue<info> q;
char a[8][8];
int sx = 7, sy = 0, ex = 0, ey = 7 , c[8][8], ans;
int dx[] = { -1,-1,-1,0,0,0,1,1,1 };
int dy[] = { -1,0,1,-1,0,1,-1,0,1 };
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			cin >> a[i][j];
			if (a[i][j] == '#') wList.push_back({ i,j,1 });
		}
	}
	q.push({ sx,sy,1 });
	c[sx][sy] = true;
	while (true) {
		int Qsize = q.size();
		memset(c, 0, sizeof(c));
		while (Qsize--) {
			//������ �̵������� ��ǥ�� push
			int x = q.front().x, y = q.front().y;
			q.pop();
			for (int i = 0; i < 9; i++) {
				int nx = x + dx[i], ny = y + dy[i];
				if (nx < 0 || ny < 0 || nx >= 8 || ny >= 8) continue;
				if (c[nx][ny] == true) continue;
				if (a[nx][ny] == '.') {
					if (nx == ex && ny == ey) {
						ans = 1;
						cout << ans;
						return 0;
					}
					q.push({ nx,ny,1 });
					c[nx][ny] = true;
				}
			}
		}
		//���� �̵���Ű�� ���� �ʿ��� ���� ����� ���� ��ĭ�� �Ʒ��� �̵�
		for (int i = 0; i < wList.size(); i++) {
			if (wList[i].alive == false) continue;
			a[wList[i].x][wList[i].y] = '.';
			wList[i].x++;
			if (wList[i].x == 8) wList[i].alive = false;
		}
		//���� �ٽ� �����.
		for (int i = 0; i < wList.size(); i++) {
			if (wList[i].alive == false) continue;
			a[wList[i].x][wList[i].y] = '#';
		}

		//ť�� �ִ� ��ǥ�� ���鼭 �ش� �ڸ��� �����ִ��� üũ
		int qSize = q.size();
		
		while (qSize--) {
			int x = q.front().x, y = q.front().y;
			q.pop();
			if (a[x][y] == '.') q.push({ x,y,1 });
		}
		//������ ������ ��ĭ���� �̵����Ұ��
		if (q.size() == 0) {
			ans = 0;
			break;
		}
	}
	cout << ans;
}