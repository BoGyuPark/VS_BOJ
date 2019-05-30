#include<iostream>
#include<string>
using namespace std;
int main() {
	int n = 0;
	char m;
	cin >> n >> m;
	int cnt=0;
	for (int i = 1; i <= n; i++) {
		string s = "";
		s = to_string(i);
		for (int j = 0; j < s.size(); j++) {
			if (s[j] == m) {
				cnt++;
			}
		}
	}
	cout << cnt;
}