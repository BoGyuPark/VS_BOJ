#include<iostream>
#include<string>
using namespace std;
int k, c[10], sel[10];
char a[10];
string MIN = "9999999999", MAX = "0000000000";
void dfs(int index) {
	if (index > 1) {
		if (a[index-2] == '<') {
			if (sel[index - 2] > sel[index-1]) return;
		}
		else {
			if (sel[index - 2] < sel[index-1]) return;
		}
	}
	
	if (index == k + 1) {
		string s = "";
		for (int j = 0; j < index; j++) s += to_string(sel[j]);
		if (s > MAX) MAX = s;
		if (s < MIN) MIN = s;
		return;
	}

	for (int i = 0; i < 10; i++) {
		if (c[i] == true) continue;
		c[i] = true;
		sel[index] = i;
		dfs(index + 1);
		c[i] = false;
	}
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> k;
	for (int i = 0; i < k; i++) cin >> a[i];
	dfs(0);
	cout << MAX << '\n' << MIN;
}