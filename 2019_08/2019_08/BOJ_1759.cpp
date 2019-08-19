/*BOJ 1759 암호 만들기*/
#include<iostream>
#include<algorithm>
using namespace std;
int n, m, sel[16], c[15], alpha[40];
char arr[16];
void go(int index,int start) {
	if (index == n) {
		int mo = 0, ja = 0;
		for (int j = 0; j < n; j++) {
			if (alpha[arr[sel[j]] - 'a'] == true) mo++;
			else ja++;
		}
		if (mo >= 1 && ja >= 2) {
			for (int j = 0; j < n; j++) cout << arr[sel[j]];
			cout << '\n';
		}
		return;
	}
	for (int i = start; i < m; i++) {
		if (c[i]) continue;
		c[i] = true;
		sel[index] = i;
		go(index + 1, i);
		c[i] = false;
	}
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < m; i++) cin >> arr[i];
	sort(arr, arr + m);
	alpha['a' - 'a'] = alpha['e' - 'a'] = alpha['u' - 'a'] = alpha['i' - 'a'] = alpha['o' - 'a'] = true;
	go(0, 0);
}