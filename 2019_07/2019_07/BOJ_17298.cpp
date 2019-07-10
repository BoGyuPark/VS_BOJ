#include<iostream>
#include<stack>
#include<vector>
using namespace std;
int n, arr[1'000'000], ans[1'000'000];
stack<int> s;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) cin >> arr[i];
	s.push(1e9);
	for (int i = n - 1; i >= 0; i--) {
		while (s.top() <= arr[i]) s.pop();
		if (s.top() >= 1e9) ans[i] = -1;
		else ans[i] = s.top();
		s.push(arr[i]);
	}
	for (int i = 0; i < n; i++) cout << ans[i] << ' ';
}