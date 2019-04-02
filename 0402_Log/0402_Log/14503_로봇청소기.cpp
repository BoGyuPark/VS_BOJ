#include<iostream>
using namespace std;
int n, m, r, c, dir, a[51][51], check[51][51];
int dx[] = { -1,0,1,0 };
int dy[] = { 0,1,0,-1 };
int overDirs[] = { 2,3,0,1 };
int visited[51][51][4];
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m >> r >> c >> dir;
	for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) cin >> a[i][j];
	int cnt = 0;

	while (true) {
		if (a[r][c] == 0 && check[r][c] == false) {
			check[r][c] = true;
			cnt++;
		}
		//�� ���� ��� û�Ұ� �̹� �Ǿ��ְų� ���� ���
		int flag = 0;
		for (int i = 0; i < 4; i++) {
			int nx = r + dx[i], ny = c + dy[i];
			if (a[nx][ny] == 1 || check[nx][ny] == true) flag++;
		}

		if (flag == 4) {
			//�ٶ󺸰��ִ� ������ �ݴ�� �̵� �����Ѱ�?
			//�ݺ��Ǳ��� �������� �ٲ۴�.
			if (a[r + dx[overDirs[dir]]][c + dy[overDirs[dir]]] == 0) {
				r += dx[overDirs[dir]];
				c += dy[overDirs[dir]];
				continue;
			}
			//�۵��� �����.
			else break;
		}
		else {
			dir = (dir + 3) % 4;
			int nx = r + dx[dir], ny = c + dy[dir];
			if (a[nx][ny] == 0 && check[nx][ny] == false) {
				r = nx; c = ny;
				continue;
			}
		}
	}
	cout << cnt;
}