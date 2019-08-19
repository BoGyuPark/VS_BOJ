/*BOJ 11723 С§Че*/
#include<iostream>
#include<string>
#include<vector>
using namespace std;
int m;
string order[4] = { "add","remove","check","toggle" };
vector<int> pull, v;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	pull.resize(21);
	v.resize(21);
	for (int i = 1; i < 21; i++) pull[i] = i;

	cin >> m;
	for (int i = 0; i < m; i++) {
		string s; int num;
		cin >> s;
		if (s == "all" || s == "empty") {
			if (s == "all") v = pull;
			else {
				v.clear();		v.resize(21);
			}
		}
		else {
			cin >> num;
			if (s == order[0] && v[num] == 0) v[num] = num;
			else if (s == order[1]&& v[num] != 0) v[num] = 0;
			else if (s == order[2]) {
				if (v[num] != 0) cout << 1 << '\n';
				else cout << 0 << '\n';
			}
			else {
				if (v[num] != 0) v[num] = 0;
				else v[num] = num;
			}
		}
	}
}