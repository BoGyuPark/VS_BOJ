/*BOJ 2529 ∫ŒµÓ»£*/
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
int n, arr[10], c[10], sel[11];
char ch;
vector<string> s;
void go(int index) {
	if (index == n + 1) {
		string t = "";
		for (int j = 0; j < n + 1; j++) t += sel[j] + '0';
		s.push_back(t);
		return;
	}
	for (int i = 0; i < 10; i++) {
		if (c[i]) continue;
		c[i] = true;
		sel[index] = i;
		if (index == 0) go(index + 1);
		else {
			// <
			if (arr[index - 1] == 1) {
				if(sel[index - 1] < i)	go(index + 1);
			}
			// >
			else {
				if (sel[index - 1] > i) go(index + 1);
			}
		}
		c[i] = false;
	}
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> ch;
		if (ch == '<') arr[i] = 1;	// > : 0, < : 1
	}
	go(0);
	sort(s.begin(), s.end());
	cout << s[s.size() - 1] << '\n' << s[0];
}