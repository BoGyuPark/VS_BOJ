/*BOJ 10597 순열장난*/
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace	std;
string s;
int check[51],flag;
vector<int> v;
bool isPossible() {
	int maxi = 1;
	for (int i = 0; i<v.size(); i++) {
		maxi = max(maxi, v[i]);
	}
	for (int i = 1; i <= maxi; i++) {
		if (check[i] == false) return false;
	}
	return true;
}
void go(int index) {
	if (flag) return;
	if (index == s.size()) {
		if (isPossible()) {
			for (auto j : v) cout << j << ' ';
			flag = true;
		}
		return;
	}
	int num = s[index] - '0';
	//한자리일때 넣고
	if (!check[num]) {
		check[num] = true;
		v.push_back(num);
		go(index + 1);
		v.pop_back();
		check[num] = false;
	}
	if (index + 1 == s.size()) return;
	num = num * 10 + s[index + 1] - '0';
	//두자리일때 넣고
	if (!check[num]) {
		if (num > 51) return;
		if (check[num]) return;
		else {
			check[num] = true;
			v.push_back(num);
			go(index + 2);
			v.pop_back();
			check[num] = false;
		}
	}
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> s;
	check[0] = 0;
	go(0);
}