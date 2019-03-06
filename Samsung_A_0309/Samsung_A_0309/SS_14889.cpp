#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int n, a[21][21], t[20], ans = 2147483647;
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) cin >> a[i][j];
	for (int i = 0; i < n / 2; i++) t[i] = 1;
	//start�� 0, link�� 1
	do {
		vector<int> link, start;
		//�� ������
		for (int i = 0; i < n; i++) {
			if (t[i]) link.push_back(i);
			else start.push_back(i);
		}
		int startSum = 0, linkSum = 0, dif;
		//start���� link�� �ó��� ���(��������)
		for (int i = 0; i < n / 2; i++) {
			for (int j = 0; j < n / 2; j++) {
				if (i == j) continue;
				linkSum += a[link[i]][link[j]];
				startSum += a[start[i]][start[j]];
			}
		}
		dif = linkSum - startSum;
		if (dif < 0) dif = -dif;
		if (dif < ans) ans = dif;
	} while (prev_permutation(t, t + n));
	cout << ans;
}