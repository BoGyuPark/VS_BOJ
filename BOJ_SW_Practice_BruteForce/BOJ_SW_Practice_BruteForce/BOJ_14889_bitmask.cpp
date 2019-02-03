#include<iostream>
#include<vector>
using namespace std;
int s[21][21], n, cnt = 0, dif, ans = 10000000;
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)		cin >> s[i][j];
	}
	for (int i = 0; i < (1 << n); i++) {
		vector<int> st, li;
		cnt = 0;
		for (int j = 0; j < n; j++) {
			if (i&(1 << j))	cnt++;
		}
		if (cnt != n / 2) continue;
		for (int j = 0; j < n; j++) {
			if (i&(1 << j))	li.push_back(j);
			else st.push_back(j);
		}
		int stsum = 0, lisum = 0;
		for (int i = 0; i < n / 2; i++) {
			for (int j = 0; j < n / 2; j++) {
				if (i == j)	continue;
				stsum += s[st[i]][st[j]];
				lisum += s[li[i]][li[j]];
			}
		}
		dif = stsum - lisum;
		if (dif < 0)	dif = -dif;
		if (ans > dif)	ans = dif;
	}
	cout << ans;
}