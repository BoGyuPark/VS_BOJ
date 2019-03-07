#include<iostream>
#include<cstring>
using namespace std;
int n, l, a[101][101], b[101][101], c[101][101];
bool cal(int r, int m[][101]) {
	for (int col = 1; col < n; col++) {
		if (m[r][col] != m[r][col - 1]) {
			int dif = abs(m[r][col] - m[r][col - 1]);
			if (dif != 1) return false;
			//������ ���� ���
			if (m[r][col] > m[r][col - 1]) {
				for (int z = 1; z <= l; z++) {
					//���� �� �Ǵ�
					if (col - z < 0) return false;
					//�����Ǵ�
					if (m[r][col - 1] != m[r][col - z]) return false;
					//���� �ߺ��� �Ǵ�
					if (c[r][col - z]) 	return false;
					c[r][col - z] = true;
				}
			}
			//������ ū ���
			else {
				for (int z = 0; z < l; z++) {
					//���� �� �Ǵ�
					if (col + z >= n) return false;
					//�����Ǵ�
					if (m[r][col] != m[r][col + z]) return false;
					//���� �ߺ��� �Ǵ�
					if (c[r][col + z]) 	return false;
					c[r][col + z] = true;
				}
			}
		}
	}
	return true;
}

int main() {
	cin >> n >> l;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
			b[j][i] = a[i][j];
		}
	}
	int ans = 0;
	for (int i = 0; i < n; i++) ans += cal(i, a);
	memset(c, 0, sizeof(c));
	for (int i = 0; i < n; i++) ans += cal(i, b);
	cout << ans;
}