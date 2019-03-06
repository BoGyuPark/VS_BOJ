#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int n, m, k, a[11][11], ad[11][11], dead[11][11];
int dx[] = { -1,-1,-1,0,0,1,1,1 };
int dy[] = { -1,0,1,-1,1,-1,0,1 };
vector<int> tree[11][11];
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m >> k;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> ad[i][j];
			a[i][j] = 5;
		}
	}
	int tx, ty, ta;
	for (int i = 0; i < m; i++) {
		cin >> tx >> ty >> ta;
		tree[tx - 1][ty - 1].push_back(ta);
	}
	//��,����,����,�ܿ�
	while (k--) {
		//v�� ������ �ִ� �� ��ǥ�� �������� ���̸� ���´�.
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				dead[i][j] = 0;
				//��ǥ�� ������ ������
				if (tree[i][j].size() == 0) continue;
				sort(tree[i][j].begin(), tree[i][j].end());
				int deadcnt = 0;
				for (int z = 0; z < tree[i][j].size(); z++) {
					if (a[i][j] - tree[i][j][z] >= 0) {
						a[i][j] -= tree[i][j][z];
						tree[i][j][z]++;
					}
					else {
						dead[i][j] += (tree[i][j][z] / 2);
						deadcnt++;
					}
				}
				//�տ��� ���̼����� �����߱⶧���� �ڿ��� deadcnt�� ��ŭ�� ��������
				while (deadcnt--) { tree[i][j].pop_back(); }	
			}
		}
		//�����̵Ǿ� 5�ǹ���� ������ �����Ѵ�.
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (tree[i][j].size() == 0) continue;
				for (int z = 0; z < tree[i][j].size(); z++) {
					if (tree[i][j][z] % 5 == 0) {
						for (int w = 0; w < 8; w++) {
							int nx = i + dx[w], ny = j + dy[w];
							if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
							tree[nx][ny].push_back(1);
						}
					}
				}
			}
		}
		//�ܿ� ó������ ��� �ٽ� �ִ´�.
		for (int i = 0; i < n; i++) 
			for (int j = 0; j < n; j++) 
				a[i][j] += (ad[i][j] + dead[i][j]);
	}
	int ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			ans += tree[i][j].size();
	}
	cout << ans;
}