#include<iostream>
using namespace std;
int n, s, sel[20], wait[20], cnt = 0, sum;
void dfs(int index) {
	if (index == n) {
		sum = 0;
		for (int j = 0; j < n; j++) 
			if (sel[j] == 1) sum += wait[j];

		//정답인 경우 증가
		if (sum == s) cnt++;
		return;
	}
	for (int i = 0; i < 2; i++) {
		sel[index] = i;
		dfs(index + 1);
	}
}
int main() {
	cin >> n >> s;
	for (int i = 0; i < n; i++) cin >> wait[i];
	dfs(0);
	cout << (s == 0 ? cnt - 1 : cnt);
}