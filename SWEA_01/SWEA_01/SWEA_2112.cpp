#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
int Test, T, n, m, k, a[14][21], cnt = 0;
void Check() {
	cnt = 0;
	for (int i = 0; i < m; i++) {
		int conse = 1, temp = 0;
		for (int j = 0; j < n-1; j++) {
			if (a[j][i] == a[j + 1][i]) conse++;
			else {
				if (temp < conse)	temp = conse;
				conse = 1;
			}
		}
		if (temp >= k || conse >= k) cnt++;
		//�߰��� ��������
		if (cnt < i + 1) return;
	}
}
int main() {
	cin >> Test;
	for (T = 1; T <= Test; T++) {
		cin >> n >> m >> k;
		for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) cin >> a[i][j];
			//��Ʈ��ŷ����ؾ��Ѵ�.....
			Check();
			if (cnt == m) break;


		}
		cout << '#' << T << ' ' << 1 << '\n';
	}
}