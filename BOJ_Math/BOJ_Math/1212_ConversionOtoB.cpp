//BOJ_1212_ConversionOtoB
#include<bits/stdc++.h>
using namespace std;
int main() {
	string s, ans = ""; cin >> s;
	int n = s.size();
	for (int i = 0; i < n; i++) {
		int t = s[i] - '0';
		string sub = "";
		while (t > 0) {
			sub += (char)(t % 2 + '0');
			t /= 2;
		}
		reverse(sub.begin(), sub.end());
		if (i != 0) {
			while (sub.size() != 3) {
				sub = "0" + sub;
			}
		}
		ans += sub;
	}
	if (s.compare("0") == 0)
		cout << "0";
	else {
		cout << ans;
	}
	return 0;
}