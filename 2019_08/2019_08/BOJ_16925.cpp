/*BOJ 16925 문자열 추측*/
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
int n, check[21];
vector<string> v,one,nMinusOne;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	for (int i = 0; i < 2 * n - 2; i++) {
		string s;
		cin >> s;
		v.push_back(s);
	}
	string s;
	if (v.size() == 2) {
		s = v[0] + v[1];
		cout << s << '\n' << "PS";
	}
	else {
		//접두사 n-1문자열과 접미사 1문자열을 합치자.
		for (int i = 0; i < v.size(); i++) {
			if (v[i].size() == n - 1) nMinusOne.push_back(v[i]);
			else if (v[i].size() == 1) one.push_back(v[i]);
		}

		if (nMinusOne[0] + one[0] == one[1] + nMinusOne[1]) {
			s = nMinusOne[0] + one[0];
		}

		if (nMinusOne[0] + one[1] == one[0] + nMinusOne[1]) {
			s = nMinusOne[0] + one[1];
		}
		
		cout << s << '\n';
		//find prefic, suffix
		for (int i = 0; i < v.size(); i++) {
			string temp = v[i];
			//prefix
			if (s.substr(0, temp.size()) == temp) {
				if (!check[temp.size()]) {
					cout << "P";
					check[temp.size()] = true;
				}
				else cout << "S";
			}
			else cout << "S";
		}
	}
}