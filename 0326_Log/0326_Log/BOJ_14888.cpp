#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int n, a[101], MAX = -2147483640, MIN = 2147483647;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];
	vector<int> v;
	for (int i = 0; i < 4; i++) {
		int t; cin >> t;
		for (int j = 0; j < t; j++) v.push_back(i + 1);
	}
	do {
		int sum = a[0];
		for (int i = 0; i < v.size(); i++) {
			if (v[i] == 1) sum += a[i + 1];
			else if (v[i] == 2) sum -= a[i + 1];
			else if (v[i] == 3) sum *= a[i + 1];
			else sum /= a[i + 1];
		}
		if (sum > MAX) MAX = sum;
		if (sum < MIN) MIN = sum;
	} while (next_permutation(v.begin(), v.end()));
	//for (auto i : v) cout << i << ' ';
	cout << MAX << '\n' << MIN;
}