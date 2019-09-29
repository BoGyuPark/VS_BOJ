/*BOJ 6549 히스토그램에서 가장 큰 직사각형*/
#include<iostream>
#include<stack>
#include<algorithm>
#include<cstring>
using namespace std;
int n, h[100'002];
long long ans;
stack<int> s;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	while (true) {
		cin >> n;
		if (n == 0) break;
		for (int i = 0; i < n; i++) cin >> h[i];
		ans = 0;
		for (int i = 0; i <= n; i++) {
			while (!s.empty() && h[s.top()] > h[i]) {
				int pivotIdx = s.top();
				s.pop();
				int width;
				if (s.empty()) width = i;
				else width = i - 1 - s.top();
				ans = max(ans, (long long)width*h[pivotIdx]);
			}
			s.push(i);
		}
		cout << ans << '\n';
		memset(h, 0, sizeof(h));
		while (!s.empty()) s.pop();
	}
}