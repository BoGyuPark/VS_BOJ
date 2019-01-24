#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int n, m, k = 0, cnt[10], num[10], pos[10], ans[10];
void go(int index) {
	if (index == m) {
		for (int j = 0; j < m; j++) {
			cout << ans[pos[j]] << ' ';
		}cout << "\n";
		return;
	}
	for (int i = 0; i < k + 1; i++) {
		cnt[i] -= 1;
		pos[index] = i;
		go(index + 1);
		cnt[i] += 1;
	}
}
int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cnt[i] = 1;
		cin >> num[i];
	}
	sort(num, num + n);
	ans[0] = num[0];
	for (int i = 1; i < n; i++) {
		if (num[i] == num[i - 1]) {
			cnt[k]++;
		}
		else {
			k++;
			ans[k] = num[i];
		}
	}
	go(0);
	return 0;
}