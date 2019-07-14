/*BOJ 17298 오큰수 다시 풀기*/
#include<iostream>
#include<stack>
#include<cstring>
using namespace std;
int ans[1'000'001], n, numlist[1'000'001];
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	memset(ans, -1, sizeof(ans));
	cin >> n;
	stack<int> s;
	for (int i = 0; i < n; i++) cin >> numlist[i];

	for (int i = n - 1; i >= 0; i--) {
		while (!s.empty()) {
			if (s.top() > numlist[i]) {
				ans[i] = s.top();
				break;
			}
			else s.pop();
		}
		s.push(numlist[i]);
	}
	for (int i = 0; i < n; i++) cout << ans[i] << ' ';
}
