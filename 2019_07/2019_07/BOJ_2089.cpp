/*BOJ 2089 -2Áø¼ö*/
#include<iostream>
#include<stack>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n;
	cin >> n;
	if (n == 0) {
		cout << 0;
		return 0;
	}
	stack<int> s;
	while (n != 0) {
		if (n < 0) {
			if (n % -2 == 0) {
				s.push(0);
			}
			else {
				s.push(1);
				n -= 1;
			}
			n = n / -2;
		}
		else {
			s.push(n%-2);
			n /= -2;
		}
	}
	while (!s.empty()) {
		cout << s.top();
		s.pop();
	}
}