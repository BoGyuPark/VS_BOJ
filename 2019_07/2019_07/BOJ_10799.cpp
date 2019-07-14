/*BOJ 10799 ¼è¸·´ë±â*/
#include<iostream>
#include<stack>
#include<string>
#include<vector>
using namespace std;
vector<int> lazer_idx;
vector<pair<int, int>> iron;
int check[100'001];
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	string str;
	cin >> str;
	for (int i = 0; i < str.size() - 1; i++) {
		if (str[i] == '(' && str[i + 1] == ')') {
			lazer_idx.push_back(i);
			check[i] = check[i + 1] = true;
			i++;
		}
	}

	/*for (auto j : lazer_idx) cout << j << ' ';
	cout << '\n';*/
	stack<int> s;
	for (int i = 0; i < str.size(); i++) {
		if (check[i] == true) {
			i++;
			continue;
		}

		if (str[i] == '(') {
			s.push(i);
		}
		else if (str[i] == ')') {
			iron.push_back({ s.top(),i });
			s.pop();
		}
	}

	/*for (auto j : iron) cout << j.first << ',' << j.second << ' ';
	cout << '\n';*/

	int ans = 0;
	for (int i = 0; i < iron.size(); i++) {
		int lazer_cnt = 0;
		for (int j = 0; j < lazer_idx.size(); j++) {
			if (iron[i].first < lazer_idx[j] && lazer_idx[j] < iron[i].second) {
				lazer_cnt++;
			}
		}
		ans += lazer_cnt + 1;
	}
	cout << ans;

}