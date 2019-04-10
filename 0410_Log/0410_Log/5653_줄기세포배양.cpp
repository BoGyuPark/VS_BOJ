#include<iostream>
#include<queue>
#include<vector>
#include<cstring>
#define BASE 150
using namespace std;
int T, tc, n, m, k;
int a[350][350];
typedef struct info {
	int x, y, ages;
};
int dx[] = { 0,0,-1,1 };
int dy[] = { 1,-1,0,0 };
queue<info> q[11];
int main() {
	cin >> T;
	for (tc = 1; tc <= T; tc++) {
		cin >> n >> m >> k;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cin >> a[BASE + i][BASE + j];
				//�ٱ⼼���� �����Ѵٸ�
				int value = a[BASE + i][BASE + j];
				if (value > 0) {
					q[a[BASE + i][BASE + j]].push({ BASE + i,BASE + j,value * 2 });
				}
			}
		}
		int aliveCnt = 0;
		for(int t=0; t<=k; t++) {
			//�ٱ⼼���� ū�ͺ��� ����
			for (int i = 10; i >= 1; i--) {
				int Qsize = q[i].size();
				for (int j = 0; j < Qsize; j++) {
					int x = q[i].front().x, y = q[i].front().y, remain_age = q[i].front().ages;
					q[i].pop();
					//��Ȱ��ȭ ����
					if (remain_age > i) {
						if (a[x][y] > 0) {
							aliveCnt++;
							a[x][y] = -a[x][y];		//��Ȱ��ȭ�϶��� -������ ����
						}
						q[i].push({ x,y,remain_age - 1 });
					}
					//Ȱ��ȭ ���� + ����
					else if (remain_age == i) {
						q[i].push({ x,y,remain_age - 1 });
						for (int z = 0; z < 4; z++) {
							int nx = x + dx[z], ny = y + dy[z];
							if (a[nx][ny] == 0) {	// ����ִ� ��쿡�� ����
								a[nx][ny] = i;
								q[i].push({ nx,ny,remain_age * 2 });
							}
						}
					}
					//Ȯ�� ���� Ȱ��ȭ
					else if (remain_age < i && remain_age > 0) {
						q[i].push({ x,y,remain_age - 1 });
					}
					//������ ���� �׾��� ���
					else aliveCnt--;
				}
			}
		}
		cout << '#' << tc << ' ' << aliveCnt << '\n';
		for (int i = 0; i < 11; i++) {
			while (!q[i].empty()) q[i].pop();
		}
		memset(a, 0, sizeof(a));
	}
}