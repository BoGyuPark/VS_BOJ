#include<iostream>
#include<algorithm>
using namespace std;
int n, m, wait[8], sel[8];
void go(int index, int start) {
	if (index == m) {
		for (int j = 0; j < m; j++) cout << sel[j] << ' ';
		cout << '\n';
		return;
	}
	for (int i = start; i < n; i++) {
		sel[index] = wait[i];
		go(index + 1, i);
	}
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> wait[i];
	sort(wait, wait + n);
	go(0, 0);
}