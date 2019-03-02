#include<iostream>
#include<algorithm>
using namespace std;
int n, m, wait[8], c[8], sel[8];
void go(int index, int start) {
	if (index == m) {
		for (int j = 0; j < m; j++) cout << sel[j] << ' ';
		cout << '\n';
		return;
	}
	for (int i = start; i < n; i++) {
		if (c[i] == true) continue;
		c[i] = true;
		sel[index] = wait[i];
		go(index + 1, i);
		c[i] = false;
	}
}
int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> wait[i];
	sort(wait, wait + n);
	go(0,0);
}