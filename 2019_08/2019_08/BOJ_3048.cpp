/*BOJ 3048 개미*/
#include<iostream>
#include<string>
#include<algorithm>
#include<cstring>
using namespace std;
int n, m, T;
string num;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m;
	// 0은 오른쪽, 1은 왼쪽 방향
	for (int i = 0; i < n; i++) num += "0";
	for (int i = 0; i < m; i++) num += "1";

	string s, s1; cin >> s >> s1;
	reverse(s.begin(),s.end());
	s += s1;
	cin >> T;

	for (int i = 0; i < T; i++) {

		//방향이 01 일때만 swap한다.
		for (int i = 0; i < n + m - 1; i++) {
			if (num[i] == '0' && num[i + 1] == '1') {
				swap(num[i], num[i + 1]);
				swap(s[i], s[i + 1]);
				i++;
			}
		}
	}
	cout << s;
}