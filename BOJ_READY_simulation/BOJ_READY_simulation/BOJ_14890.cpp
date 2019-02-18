#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
int n, l, a[101][101], b[101][101], c[101][101];
bool go(int row, int map[101][101]) {
	for (int i = 1; i < n; i++) {
		if (map[row][i] != map[row][i - 1]) {
			int dif = map[row][i] - map[row][i - 1];
			if (dif < 0) dif = -dif;
			if (dif != 1) return false;
			//��� ���� �� ó��
			if (map[row][i] > map[row][i - 1]) {
				for (int j = 1; j <= l; j++) {
					//���θ� ���ٰ� ������ ����� ���
					if (i - j < 0) return false;
					//���� ������ ĭ�� ���̰� ��� ���� �ʰų�, L���� ���� ���� �ʴ� ���
					if (map[row][i - 1] != map[row][i - j]) return false;
					//��θ� ���� ���� �� ���θ� ���� ���
					if (c[row][i - j]) return false;
					c[row][i - j] = true;
				}		
			}
			else {
				for (int j = 0; j < l; j++) {
					//���θ� ���ٰ� ������ ����� ���
					if (i + j >= n) return false;
					//���� ������ ĭ�� ���̰� ��� ���� �ʰų�, L���� ���� ���� �ʴ� ���
					if (map[row][i] != map[row][i + j]) return false;
					//��θ� ���� ���� �� ���θ� ���� ���
					if (c[row][i + j]) return false;
					c[row][i + j] = true;
				}
			}
		}
	}
	return true;
}

int main() {
	cin >> n >> l;
	//a�迭�� �⺻ �迭, b�迭�� ��� ���� �ٲ�
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
			b[j][i] = a[i][j];
		}
	}
	int ans = 0;
	for (int i = 0; i < n; i++)	ans += go(i, a);
	memset(c, 0, sizeof(c));
	for (int i = 0; i < n; i++) ans += go(i, b);
	cout << ans;		
}