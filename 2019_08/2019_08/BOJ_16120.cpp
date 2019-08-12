/*BOJ 16120 PPAP*/
// O(N)안에 풀어야 한다!!!!
#include<iostream>
#include<string>
#include<vector>
using namespace std;
vector<char> v;
int flag;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	string s, ans = "NP";
	cin >> s;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == 'P') {
			v.push_back(s[i]);
		}
		else if (s[i] == 'A') {
			int idx1 = v.size() - 2, idx2 = v.size() - 1;
			if (idx1 < 0 || idx2 < 0) {
				flag = true;
				break;
			}
			if (v[idx1] == 'P' && v[idx2] == 'P' && s[i + 1] == 'P') {
				v.pop_back();
				v.pop_back();
				v.push_back('P');
				i++;
			}
		}
	}
	if (!flag && v.size() == 1 && v[0] == 'P') ans = "PPAP";
	cout << ans;
}