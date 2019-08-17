/*BOJ 16943 숫자 재배치*/
#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;
int A, B, C,sel[11],check[11];
string s;
vector<int > v;
void go(int index) {
	if (index == s.size()) {
		int temp = 0;
		if (s[sel[0]] == '0') return;
		for (int j = 0; j < index; j++) temp = temp * 10 + (s[sel[j]] - '0');
		if (temp <= B) v.push_back(temp);
		return;
	}
	for (int i = 0; i < s.size(); i++) {
		if (check[i]) continue;
		check[i] = true;
		sel[index] = i;
		go(index + 1);
		check[i] = false;
	}
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> A >> B;
	s = to_string(A);
	go(0);
	sort(v.begin(), v.end());
	if (v.size() == 0) cout << -1;
	else cout << v[v.size() - 1];
}