#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;
int n;
struct info {
	string s;
	int len, sum;
};
vector<info> v;
bool cmp(info a, info b) {
	
	if (a.len == b.len) {
		if (a.sum == b.sum) return  a.s < b.s;
		else return a.sum < b.sum;
	}
	else return a.len < b.len;
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		string t; cin >> t;
		int Sum = 0;
		for (int j = 0; j < t.size(); j++) {
			if (isdigit(t[j])) Sum += (t[j] - '0');
		}
		v.push_back({ t,(int)t.size(),Sum });
	}
	sort(v.begin(), v.end(),cmp);
	for (auto i : v) cout << i.s << '\n';
}