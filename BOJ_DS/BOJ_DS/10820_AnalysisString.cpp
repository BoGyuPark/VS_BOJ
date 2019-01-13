//BOJ_10820_AnalysisString
#include<bits/stdc++.h>
using namespace std;
int main() {
	string st;
	while(getline(cin,st)){
		int s, b, n, e;
		s = b = n = e = 0;
		int len = st.length();
		for(int i=0; i<len; i++) {
			if (st[i] == ' ') {
				e++;
			}
			else if (st[i] >= 97 && st[i] <= 122) {
				s++;
			}
			else if (st[i] >= 65 && st[i] <= 90) {
				b++;
			}
			else {
				n++;
			}
		}
		cout << s << ' ' << b << ' ' << n << ' ' << e << "\n";
	}
	return 0;
}