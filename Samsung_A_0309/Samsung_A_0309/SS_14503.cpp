#include<iostream>
using namespace std;
int n, m, rx, ry, dir, a[51][51], clean = 0;
int dx[] = { -1,0,1,0 };
int dy[] = { 0,1,0,-1 };
int ro[] = { 3,0,1,2 };
int ba[] = { 2,3,0,1 };
int main() {
	cin >> n >> m >> rx >> ry >> dir;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) cin >> a[i][j];
	}
	a[rx][ry] = 2;
	while (true) {
		bool found = false;
		for (int i = 0; i < 4; i++) {
			//���� ������ ���� ������ Ž��
			int nx = rx + dx[ro[dir]], ny = ry + dy[ro[dir]];
			if (a[nx][ny] == 0) {
				//�������� ȸ�� �� �� �������� ����.
				dir = ro[dir];
				a[nx][ny] = 2;
				rx = nx; ry = ny;
				found = true;
				break;
			}
			else dir = ro[dir];
		}
		//�� ���� ��� û�Ұ� �̹� �Ǿ��ְų� ���� ���
		if (!found) {
			int nx = rx + dx[ba[dir]], ny = ry + dy[ba[dir]];
			//���� ����
			if (a[nx][ny] != 1) { rx = nx; ry = ny; }
			//�۵��� ���� ��
			else break;
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) if (a[i][j] == 2) clean++;
	}
	cout << clean;
}