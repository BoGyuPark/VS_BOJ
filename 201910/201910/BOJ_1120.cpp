/*BOJ 1120 ¹®ÀÚ¿­*/
#include<iostream>
#include<string>
using namespace std;
string A, B;
int ans = 2147483647;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> A >> B;
	int lenDif = B.size() - A.size();
	for (int i = 0; i <= lenDif; i++) {
		int cnt = 0;
		for (int j = 0; j < A.size(); j++) {
			if (A[j] != B[j + i]) cnt++;
		}
		if (ans > cnt) ans = cnt;
	}
	cout << ans;
}