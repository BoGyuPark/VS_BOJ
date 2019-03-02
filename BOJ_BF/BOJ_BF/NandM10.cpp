#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;
int n, m, a[9],t[9];
int main() {
	vector<string> v;
	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0; i < m; i++) t[i] = 1;
	sort(a, a + n);
	do {
		string s = "";
		for (int i = 0; i < n; i++) 
			if (t[i] == 1) 	s += a[i] + '0';
		v.push_back(s);
	} while (prev_permutation(t, t + n));
	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());
	for (auto &i : v) {
		for (int j = 0; j < i.size(); j++) cout << i[j] - '0' << ' ';
		cout << '\n';
	}
}