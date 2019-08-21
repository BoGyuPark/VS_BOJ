/*BOJ 5568 카드 놓기*/
#include<iostream>
#include<string>
#include<set>
using namespace std;
int n, k, sel[5], c[11], arr[11];
set<string> ans;
void go(int index) {
	if (index == k) {
		string s = "";
		for (int j = 0; j < k; j++) s += to_string(sel[j]);
		ans.insert(s);
		return;
	}
	for (int i = 0; i < n; i++) {
		if (c[i]) continue;
		c[i] = true;
		sel[index] = arr[i];
		go(index + 1);
		c[i] = false;
	}
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> k;
	for (int i = 0; i < n; i++) cin >> arr[i];
	go(0);
	cout << ans.size();
}