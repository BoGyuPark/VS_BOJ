#include<iostream>
#include<iomanip>
using namespace std;
int r1, c1, r2, c2, a[51][6], c = 0, maxi = 0;
int dx[] = { 0,-1,0,1 };
int dy[] = { 1,0,-1,0 };
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> r1 >> c1 >> r2 >> c2;
	int x = 5000, y = 5000, dir = 0;
	int sx = 5000 + r1, sy = 5000 + c1, ex = 5000 + r2, ey = 5000 + c2;
	if (x >= sx && y >= sy && x <= ex && y <= ey) a[x - sx][y - sy] = 1;
	//����̵� �����
	int len = 1, cnt = 0, turncnt = 0;
	for (int s = 1; s <= 10001*10001; s++) {
		if (s == 1) {
			x += dx[0]; y += dy[0];
			continue;
		}
		//�޸� �ʰ��� ���� ���Ͽ� ���ϴ� �κи� �迭�� ����.
		if (x >= sx && y >= sy && x <= ex && y <= ey) a[x-sx][y-sy] = s;
		cnt++;
		//����ٲ��ش�.
		if (len == cnt) {
			cnt = 0;
			dir = (dir + 1) % 4;
			turncnt++;
			if (turncnt == 2) {
				len++;
				turncnt = 0;
			}
		}
		x += dx[dir]; y += dy[dir];
	}
	//r1c1, r2c2���� ����ū ���� ã�� �ڸ����� ã�´�.
	for (int i = 0; i <= 51; i++) 
		for (int j = 0; j <= 5; j++) if (maxi < a[i][j]) maxi = a[i][j];
	while (maxi != 0) {
		c++;
		maxi /= 10;
	}
	//r1,c1, r2,c2�� �°� ���
	for (int i = 0; i <= r2 - r1; i++) {
		for (int j = 0; j <= c2 - c1; j++) {
			cout << setw(c) << a[i][j] << ' ';
		}
		cout << '\n';
	}
}