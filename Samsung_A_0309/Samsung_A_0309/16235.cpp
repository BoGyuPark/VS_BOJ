#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int n, m, k, t1, t2, t3;
int ad[11][11], a[11][11];
int dx[] = { -1,-1,-1,0,0,1,1,1 };
int dy[] = { -1,0,1,-1,1,-1,0,1 };
vector<int> map[11][11];
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m >> k;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> ad[i][j];
			a[i][j] = 5;
		}
	}
	for (int i = 0; i < m; i++) {
		cin >> t1 >> t2 >> t3;
		map[t1 - 1][t2 - 1].push_back(t3);
	}
	while (k--) {
		//�� �ڽ��� ���̸�ŭ ����� �԰� ���̰� 1����
		// ���̰� � �������� ����� �Դ´�.
		//����� �����ϸ� ���
		int dead[11][11] = { 0, };
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				int Size = map[i][j].size();
				if (Size > 0) {
					int removecnt = 0;
					sort(map[i][j].begin(), map[i][j].end());
					for (int z = 0; z < Size; z++) {
						if (map[i][j][z] <= a[i][j]) {
							a[i][j] -= map[i][j][z];
							map[i][j][z]++;
						}
						else {
							removecnt++;
							dead[i][j] += (map[i][j][z] / 2);
						}
					}
					while (removecnt--) {
						map[i][j].pop_back();
					}
				}
			}
		}
		//���� ������ ���̰� %5==0 �̸� ���� 8�ڸ��� ���̰� 1�� ���� ����
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				int Size = map[i][j].size();
				if (Size > 0) {
					for (int z = 0; z < Size; z++) {
						if (map[i][j][z] % 5 == 0) {
							for (int s = 0; s < 8; s++) {
								int nx = i + dx[s], ny = j + dy[s];
								if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
								map[nx][ny].push_back(1);
							}
						}
					}
				}
			}
		}
		//���� ���������� ����/2 �� ��� �߰�
		//�ܿ� �� ����� �����ش�.
		for (int i = 0; i < n; i++) 
			for (int j = 0; j < n; j++) 
				a[i][j] += (dead[i][j] + ad[i][j]);
	}
	int ans = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			ans += map[i][j].size();
	cout << ans;
}