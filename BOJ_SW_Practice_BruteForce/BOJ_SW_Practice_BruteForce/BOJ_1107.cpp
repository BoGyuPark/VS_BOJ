#include<iostream>
#include<string>
#include<math.h>
using namespace std;
int n, m, i, j, len;
char broken[11];
bool possible(string num) {
	for (int k = 0; k < num.size(); k++) {
		char c = num[k];
		for (int z = 0; z < m; z++) {
			if (c == broken[z]) {
				return false;
			}
		}	
	}
	return true;
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> n >> m;
	for (i = 0; i < m; i++)	cin >> broken[i];
	int ans = abs(n - 100);
	for (i = 0; i <= 1000000; i++) {
		string s = to_string(i);
		if (possible(s)) {
			if (ans > abs(i - n) + s.size()) {
				ans = abs(i - n) + s.size();
				len = s.size();
			}
		}
	}
	cout << ans;
}