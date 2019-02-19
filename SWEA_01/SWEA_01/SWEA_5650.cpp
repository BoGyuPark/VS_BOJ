#include<iostream>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
int t, n, a[110][110], hit;
//          ��,��,��,��
int dx[] = { 0,0,-1,1 };
int dy[] = { 1,-1,0,0 };
int direction[5][4] = {
	{1,2,3,0},
	{1,3,0,2},
	{3,0,1,2},
	{2,0,3,1},
	{1,0,3,2}
};
void Running(int x, int y, int dir) {
	while (1) {
		int nx = x + dx[dir], ny = y + dy[dir];
		while (a[nx][ny] == 0) {
			nx += dx[dir];
			ny += dy[dir];
		}
		int t = a[nx][ny];
		if (t >= 1 && t <= 5) {
			dir = direction[t - 1][dir];
			hit++;
		}
		//��Ȧ�̰ų� �������� ��� ����
		else if (t == -1) return;
		//��Ȧ�� ���
		else {
			for (int i = 1; i <= n; i++) {
				for (int j = 1; j <= n; j++) {
					//�ٸ� ��Ȧ�� �̵�
					if (a[i][j] == t) {
						if (i == nx && j == ny) continue;
						else {
							nx = i; ny = j;
							//�ٸ� ��Ȧã������ ���� ����
							i = n + 1;
							break;
						}
					}
				}
			}
		}
		x = nx;
		y = ny;
	}
}

int main() {
	cin >> t;
	for (int q = 1; q <= t; q++) {
		memset(a, 0, sizeof(a));
		vector<int> v;
		cin >> n;
		for (int i = 0; i <= n + 1; i++)
			for (int j = 0; j <= n + 1; j++) a[i][j] = 5;
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++) cin >> a[i][j];
		//������� ��ġ���� �����Ͽ� dfs�Ѵ�.
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (a[i][j] == 0) {
					a[i][j] = -1;
					int hitMax = -1;
					for (int z = 0; z < 4; z++) {
						hit = 0;
						Running(i, j, z);
						if (hitMax < hit) hitMax = hit;
					}
					v.push_back(hitMax);
					a[i][j] = 0;
				}
			}
		}
		sort(v.begin(), v.end());
		cout << '#' << q << ' ' << v[v.size() - 1] << '\n';
	}
}