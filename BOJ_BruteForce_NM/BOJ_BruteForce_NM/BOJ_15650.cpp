#include<iostream>
using namespace std;
int n, m, arr[10], c[10];
void go(int index, int start) {
	if (index == m) {
		for (int j = 0; j < m; j++) {
			cout << arr[j] << ' ';
		}
		cout << "\n";
		return;
	}
	for (int i = start; i <= n; i++) {
		if (c[i] == true) continue;
		c[i] = true; arr[index] = i;
		go(index + 1, i + 1);
		c[i] = false;
	}
}

int main() {
	cin >> n >> m;	go(0,1);
	return 0;
}