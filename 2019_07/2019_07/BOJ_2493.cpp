/*BOJ 2493 ž*/
#include<iostream>
#include<stack>
using namespace std;
int n, topHeight[500'001], ans[500'001];
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) cin >> topHeight[i];
	stack<pair<int,int>> s;
	s.push({ 1e9 + 7 , -1});
	for (int i = 0; i < n; i++) {
		while (s.top().first < topHeight[i]) s.pop();
		if (s.top().first >= 1e9) ans[i] = 0;
		else ans[i] = s.top().second;
		s.push({ topHeight[i], i+1});
	}
	for (int i = 0; i < n; i++) cout << ans[i] << ' ';
}