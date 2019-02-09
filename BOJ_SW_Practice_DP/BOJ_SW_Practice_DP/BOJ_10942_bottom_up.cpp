#include<iostream>
using namespace std;
int n, m, d[2001][2001];
int arr[2001];
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> n;
	for (int i = 1; i <= n; i++) 	cin >> arr[i];
	//���̰� 1�ΰ��� ������ �Ӹ����
	for (int i = 1; i <= n; i++) 	d[i][i] = true;
	//���̰� 2�ΰ�
	for (int i = 1; i < n; i++) 
		if (arr[i] == arr[i + 1])	d[i][i + 1] = true;
	//���̰� 3�̻��� �� (���̰� k)
	for (int k = 3; k <= n; k++) {
		for (int i = 1; i <= n - k + 1; i++) {
			int j = i + k - 1;
			if (arr[i] == arr[j] && d[i + 1][j - 1])	d[i][j] = true;
		}
	}
	cin >> m;
	while (m--) {
		int s, e;
		cin >> s >> e;
		cout << d[s][e] << '\n';
	}
}