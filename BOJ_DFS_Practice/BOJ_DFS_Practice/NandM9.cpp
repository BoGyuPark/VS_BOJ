#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;
int n, m, wait[8], c[8], sel[8];
vector<string> str;
void go(int index) {
	if (index == m) {
		string s = "";
		for (int j = 0; j < m; j++) s += sel[j] + '0';
		str.push_back(s);
		return;
	}
	for (int i = 0; i < n; i++) {
		if (c[i] == true) continue;
		c[i] = true;
		sel[index] = wait[i];
		go(index + 1);
		c[i] = false;
	}
}
int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> wait[i];
	sort(wait, wait + n);
	go(0);
	sort(str.begin(), str.end());
	str.erase(unique(str.begin(), str.end()), str.end());
	for (auto &i : str) {
		for (int j = 0; j < i.size(); j++) cout << i[j] - '0' << ' ';
		cout << '\n';
	}
}