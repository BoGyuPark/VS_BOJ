/*BOJ_1725 히스토그램*/
#include<iostream>
#include<stack>
using namespace std;
int n, h[100'002], ans;
stack<int> s;	//index를 넣는다.
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) cin >> h[i];
	
	//스택은 항상 높이가 오름차순으로 쌓인다.
	for (int i = 0; i <= n; i++) {
		while (!s.empty() && h[s.top()] > h[i]) {
			int width;
			int idx = s.top();
			s.pop();

			//스택이 빈경우 처음부터 해당 좌표까지 길이
			if (s.empty()) width = i;
			else width = i - 1 - s.top();

			if (ans < h[idx] * width) ans = h[idx] * width;
		}
		s.push(i);
	}
	cout << ans;
}