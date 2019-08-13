/*BOJ 6603 ·Î¶Ç*/
#include<iostream>
using namespace std;
int T, arr[14], sel[7], check[14];
void go(int index,int start) {
	if (index == 6) {
		for (int j = 0; j < 6; j++) cout << sel[j] << ' ';
		cout << '\n';
		return;
	}
	for (int i = start; i < T; i++) {
		if (check[i]) continue;
		check[i] = true;
		sel[index] = arr[i];
		go(index + 1,i);
		check[i] = false;
	}
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	while (true) {
		cin >> T;
		if (T == 0) break;
		for (int i = 0; i < T; i++) cin >> arr[i];
		go(0,0);
		cout << '\n';
	}
}