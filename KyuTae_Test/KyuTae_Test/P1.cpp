#include<iostream>
#include<cstring>
#include<string>
using namespace std;
int U, L, C[100000], n, upper[100000], lower[100000];
int Ucnt, Lcnt;
int main() {
	cin >> U >> L >> n;
	for (int i = 0; i < n; i++) {
		cin >> C[i];
		if (C[i] == 2) {
			upper[i] = lower[i] = 1;
			Ucnt++; Lcnt++;
		}
	}

	// 1인 경우 upper나 lower 중 하나에 넣어준다.
	for (int i = 0; i < n; i++) {
		if (C[i] == 1) {
			if (U > Ucnt) {
				Ucnt++;
				upper[i] = 1;
			}
			else {
				Lcnt++;
				lower[i] = 1;
			}
		}
	}
	if (U == Ucnt && L == Lcnt) {
		string ans = "";
		for (int i = 0; i < n; i++) ans += to_string(upper[i]);
		ans += ",";
		for (int i = 0; i < n; i++) ans += to_string(lower[i]);
		cout << ans;
	}
	else {
		cout << "IMPOSSIBLE";
	}
}