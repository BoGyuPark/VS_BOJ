#include<iostream>
using namespace std;
int n, a[16][16], c[16][16], outof[3] = { 1,0,3 };
int dx[] = { 0,1,1 };
int dy[] = { 1,0,1 };
int cnt = 0;
void dfs(int i, int j, int nowdir) {
	if (i == n - 1 && j == n - 1) {
		cnt++;
		return;
	}
	c[i][j] = true;
	for (int z = 0; z < 3; z++) {
		if (z == outof[nowdir]) continue;
		int nx = i + dx[z], ny = j + dy[z];
		if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
		if (c[nx][ny] == true) continue;
		if (a[nx][ny] == 1) continue;	//���� ��ǥ�� ���ΰ��
		//�밢���� ��� ������ǥ���� üũ���ش�.
		if (z == 2) {
			if (a[nx - 1][ny] == 1 || a[nx][ny - 1] == 1) continue;
		}
		dfs(nx, ny, z);
		c[nx][ny] = false;
	}
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) cin >> a[i][j];
	}
	dfs(0, 1, 0);	//0 : ������, 1 : �Ʒ�, 2: �밢��
	cout << cnt;
}