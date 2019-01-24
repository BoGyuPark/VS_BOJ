#include<iostream>
#include<algorithm>
using namespace std;
int n, m, ans[10], num[10];
void go(int index, int start) {
	if (index == m) {
		for (int i = 0; i < m; i++)
			cout << ans[i] << ' ';
		cout << "\n";	return;
	}
	for (int j = start; j < n; j++) {
		ans[index] = num[j];
		go(index + 1, j);
	}
}
int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++)	cin >> num[i];
	sort(num, num + n);
	go(0,0);
	return 0;
}