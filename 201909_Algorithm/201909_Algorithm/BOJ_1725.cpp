/*BOJ_1725 ������׷�*/
#include<iostream>
#include<stack>
using namespace std;
int n, h[100'002], ans;
stack<int> s;	//index�� �ִ´�.
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) cin >> h[i];
	
	//������ �׻� ���̰� ������������ ���δ�.
	for (int i = 0; i <= n; i++) {
		while (!s.empty() && h[s.top()] > h[i]) {
			int width;
			int idx = s.top();
			s.pop();

			//������ ���� ó������ �ش� ��ǥ���� ����
			if (s.empty()) width = i;
			else width = i - 1 - s.top();

			if (ans < h[idx] * width) ans = h[idx] * width;
		}
		s.push(i);
	}
	cout << ans;
}