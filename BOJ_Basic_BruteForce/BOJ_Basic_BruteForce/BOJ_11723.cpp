#include<iostream>
#include<string>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int m, x, S = 0; string temp; cin >> m;
	while (m--) {
		 cin >> temp;
		 if (temp.compare("all") == 0) {
			 S = (1 << 21) - 1;
		 }
		 else if (temp.compare("empty") == 0) {
			 S = 0;
		 }
		 else {
			 cin >> x;
			 if (temp.compare("add") == 0) {
				 if ((S & (1 << x)) == 0)
					S = S | (1 << x);
			 }
			 else if (temp.compare("remove") == 0) {
				 if ((S & (1 << x)) != 0)
					S = S & ~(1 << x);
			 }
			 else if (temp.compare("check") == 0) {
				 cout << ((S&(1 << x)) == 0 ? 0 : 1) << "\n";
			 }
			 else if (temp.compare("toggle") == 0) {
				 if ((S & (1 << x)))	S = S & ~(1 << x);
				 else S = S | (1 << x);
			 }
		 }
	}
	return 0;
}