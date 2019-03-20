#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;
vector<string> v;
int n, m, wait[8], sel[8], c[8];
void dfs(int index, int start) {
	if (index == m) {
		string s = "";
		for (int j = 0; j < m; j++) s += sel[j] + '0';
		v.push_back(s);
		return;
	}
	for (int i = start; i < n; i++) {
		if (c[i] == true) continue;
		c[i] = true;
		sel[index] = wait[i];
		dfs(index + 1, i);
		c[i] = false;
	}
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> wait[i];
	sort(wait, wait + n);
	dfs(0, 0);
	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());
	for (auto i : v) {
		for(int j=0; j<i.size(); j++) cout << i[j] - '0' << ' ';
		cout << '\n';
	}
}