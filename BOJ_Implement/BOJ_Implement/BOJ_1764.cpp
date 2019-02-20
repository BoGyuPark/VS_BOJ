#include<iostream>
#include<string>
#include<vector>
#include<map>
using namespace std;
int n, m;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m;
	map<string, int> a;
	vector<string> v;
	for (int i = 0; i < n + m; i++) {
		string s; cin >> s;
		a[s]++;
	}
	for (auto &i : a) if (i.second != 1) v.push_back(i.first);
	cout << v.size() << '\n';
	for (auto i : v) cout << i << '\n';
}