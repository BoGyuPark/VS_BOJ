/*BOJ 5597 과제 안 내신 분..?*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int map[32];
vector<int> v;
int main() {
	for (int i = 0; i < 28; i++) {
		int t; cin >> t;
		map[t] = true;
	}
	for (int i = 1; i < 31; i++) {
		if (map[i]) continue;
		v.push_back(i);
	}
	cout << min(v[0], v[1]) << '\n' << max(v[0], v[1]);
}