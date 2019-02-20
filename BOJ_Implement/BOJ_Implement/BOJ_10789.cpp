#include<iostream>
#include<string>
#include<vector>
using namespace std;
int main() {
	int maxsize = 0;
	vector<string> s;
	for (int i = 0; i < 5; i++) {
		string t; cin >> t;
		if (t.size() > maxsize) maxsize = t.size();
		s.push_back(t);
	}
	string ans = "";
	for (int j = 0; j < maxsize; j++) 
		for (int i = 0; i < 5; i++) if (s[i].size() > j) ans += s[i][j];
	cout << ans;
}