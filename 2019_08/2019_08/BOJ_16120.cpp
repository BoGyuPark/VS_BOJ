/*BOJ 16120 PPAP*/
#include<iostream>
#include<string>
using namespace std;
char str[] = "PPAP";
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	string s, temp, ans = "NP";
	cin >> s;
	int notChange = 0;
	while (s.size() > 4) {
		temp = "";
		for (int i = 0; i < s.size(); i++) {
			int cnt = 0;
			for (int j = 0; j < 4; j++) {
				if ((i + j < s.size()) && s[i + j] == str[j]) cnt++;
			}
			if (cnt == 4) {
				i += 3;
				temp += "P";
			}
			else {
				temp += s[i];
				notChange++;
			}
		}
		if (notChange == s.size()) break;
		notChange = 0;
		s = temp;
	}

	if (s == "PPAP" || s == "P") ans = "PPAP";
	cout << ans;
}