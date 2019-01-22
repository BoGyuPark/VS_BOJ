//BOJ_10973
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
vector<int> v;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n; cin >> n;
	while (n--) {
		int t; cin >> t;
		v.push_back(t);
	}
	bool flag = prev_permutation(v.begin(), v.end());
	if (flag == 0) {
		cout << -1;
	}
	else {
		for (int i = 0; i < v.size(); i++)
			cout << v[i] << ' ';
	}
	return 0;
}