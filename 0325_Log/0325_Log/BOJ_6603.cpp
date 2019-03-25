#include<iostream>
#include<algorithm>
using namespace std;
int k, s[14], sel[6], c[14];
void dfs(int index,int start) {
	if (index == 6) {
		for (int j = 0; j < 6; j++) cout << sel[j] << ' ';
		cout << '\n';
		return;
	}
	for (int i = start; i < k; i++) {
		if (c[i] == true) continue;
		c[i] = true;
		sel[index] = s[i];
		dfs(index + 1, i);
		c[i] = false;
	}
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	while (true) {
		cin >> k;
		if (k == 0) break;
		for (int i = 0; i < k; i++) cin >> s[i];
		dfs(0, 0);
		cout << '\n';
		fill(s, s + k, 0);
		fill(c, c + k, 0);
	}
}