#include<iostream>
#include<queue>
#include<cstring>
using namespace std;
int T, t, n, m, k, tx, ty, cnt, dirnum;
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };
int dirchange[] = { 1,0,3,2 };
//  �̻�����, ����
typedef struct info {int ix, iy, ic, id;};
int main() {
	cin >> T;
	for (int t = 1; t <= T; t++) {
		cin >> n >> m >> k;
		queue<info> q;
		for (int i = 0; i < k; i++) {
			cin >> tx >> ty >> cnt >> dirnum;
			q.push({ tx,ty,cnt,dirnum - 1 });
		}
		//m�� �̻��� �̵�
		for (int s = 0; s < m; s++) {
			pair<int, int> a[101][101][4];
			int temp = q.size();
			while (temp--) {
				int x = q.front().ix, y = q.front().iy;
				int num = q.front().ic, dir = q.front().id;
				q.pop();
				int nx = x + dx[dir], ny = y + dy[dir];
				//�̻����� ���������� �ƴ��� üũ
				//�̻����� ��ġ�� ��� ������ ��ĥ�� ����!
				if (a[nx][ny][0].first != 0) {
					for (int i = 1; i < 4; i++) {
						if (a[nx][ny][i].first == 0) {
							a[nx][ny][i] = { num,dir };
							break;
						}
					}
				}
				//�̻����� �Ȱ�ġ�� ���
				else {
					//��ǰ�� ĥ���� �����̸�
					if (nx == 0 || ny == 0 || nx == n - 1 || ny == n - 1) 
						a[nx][ny][0] = { num / 2, dirchange[dir] };
					else 
						a[nx][ny][0] = { num , dir };
				}
			}
			//�̻����� queue�� ��´�.
			for (int i = 0; i < n; i++)
				for (int j = 0; j < n; j++) {
					if (a[i][j][0].first != 0) {
						int order = 0, tt = 0, sum = 0;
						for (int z = 0; z < 4; z++) {
							sum += a[i][j][z].first;
							if (a[i][j][z].first > tt) {
								tt = a[i][j][z].first;
								order = z;
							}
						}
						q.push({ i,j,sum,a[i][j][order].second });
					}
				}
		}
		int ans = 0;
		while (!q.empty()) {
			ans += q.front().ic;
			q.pop();
		}
		cout << '#' << t << ' ' << ans << '\n';
	}
}