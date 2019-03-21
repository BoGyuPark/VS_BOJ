#include<iostream>
#include<string>
using namespace std;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	for (int t = 1; t <= 10; t++) {
		int n; cin >> n;
		string s;	cin >> s;
		int sum = 0;
		for (int i = 0; i < s.size(); i++) 
			if (s[i] != '+') sum += s[i] - '0';
		cout << '#' << t << ' ' << sum << '\n';
	}
}