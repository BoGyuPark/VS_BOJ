#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
int n, m, k;
int dx[] = { 0,0,-1,1 };
int dy[] = { 1,-1,0,0 };
int c[201][201];
char a[201][201];
typedef struct info {
	int x, y, time;
};
vector<info> boom, wait;	//���� ��ź�� ��ǥ ����Ʈ, ������ ���� ��ź�� ��ǥ ����Ʈ
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m >> k;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
			if (a[i][j] == 'O') boom.push_back({ i,j,3 });
			else wait.push_back({ i,j,0 });
		}
	}
	for (int t = 1; t <= k; t++) {

		//��ġ�ϰ� ó���� ���
		if (boom.size() > 0) {
			if (boom[0].time > t) {
				for (int i = 0; i < boom.size(); i++) boom[i].time--;
			}
			//��ź ��ġ
			else if (boom[0].time == t) {
				for (int i = 0; i < wait.size(); i++) {
					a[wait[i].x][wait[i].y] = 'O';
				}
			}
			//��ź�� ������
			else {
				for (int i = 0; i < boom.size(); i++) {
					int x = boom[i].x, y = boom[i].y;
					a[x][y] = '.';
					c[x][y] = true;
					for (int j = 0; j < 4; j++) {
						int nx = x + dx[j], ny = y + dy[j];
						if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
						if (c[nx][ny] == true)  continue;
						a[nx][ny] = '.';
						c[nx][ny] = true;
					}
				}
				memset(c, 0, sizeof(c));		//�ʱ�ȭ
				boom.clear();
				wait.clear();
				//��ź�� ��ĭ�� ����
				for (int i = 0; i < n; i++) {
					for (int j = 0; j < m; j++) {
						if (a[i][j] == 'O') boom.push_back({ i,j,t + 1 });
						else wait.push_back({ i,j,0 });
					}
				}
			}
		}
		
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) cout << a[i][j];
		cout << '\n';
	}
}