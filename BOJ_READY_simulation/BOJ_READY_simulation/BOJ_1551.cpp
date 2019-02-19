#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
int main() {
	int n, k;
	cin >> n >> k;
	vector<int> a, b;
	string s, now = ""; cin >> s;
	for (char c : s) {
		if (c == ',') {
			a.push_back(stoi(now));
			now = "";
		}
		else now += c;
	}
	a.push_back(stoi(now));

	for (int i = 1; i <= k; i++) {
		for (int j = 0; j < a.size() - 1; j++) {
			b.push_back(a[j + 1] - a[j]);
		}
		a.clear();		a = b;		b.clear();
	}
	for (int i = 0; i < a.size(); i++) {
		if (i == a.size() - 1) cout << a[i];
		else cout << a[i] << ',';
	}

}