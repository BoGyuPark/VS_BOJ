/*BOJ 17299 오등큰수*/
#include<iostream>
#include<stack>
#include<cstring>
using namespace std;
int ans[1'000'001], numlist[1'000'001], F[1'000'001], n;
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	memset(ans, -1, sizeof(ans));
	stack<int> s;
	for (int i = 0; i < n; i++) {
		cin >> numlist[i];
		F[numlist[i]]++;
	}

	for (int i = n - 1; i >= 0; i--) {
		while (!s.empty()) {
			if (F[numlist[i]] < F[s.top()]) {
				ans[i] = s.top();
				break;
			}
			else {
				s.pop();
			}
		}
		s.push(numlist[i]);
	}
	for (int i = 0; i < n; i++) cout << ans[i] << ' ';
}