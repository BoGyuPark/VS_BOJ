//BOJ_2089_MinusB
#include<bits/stdc++.h>	
using namespace std;
int main() {
	int n; cin >> n;
	char r;
	string s = "";
	if (n == 0) {
		cout << "0";
		return 0;
	}
	else {
		while (1) {
			if (n % 2 == 0) {
				n = (-n / 2);
				r = '0';
			}
			else {
				if (n > 0) {
					n = (-n / 2);
					r = '1';
				}
				else {
					n = (-n + 1) / 2;
					r = '1';
				}
			}
			s += r;
			if (n == 0)
				break;
		}
		reverse(s.begin(), s.end());
		cout << s;
	}
		
	return 0;
}