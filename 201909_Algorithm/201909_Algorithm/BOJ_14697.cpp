/*BOJ 14697 방 배정하기*/
#include<iostream>
using namespace std;
int num[3], n;
bool solve() {
	int firstMax = n / num[0];
	int secondeMax = n / num[1];

	for (int i = 0; i <= firstMax; i++) {
		for (int j = 0; j <= secondeMax; j++) {
			int temp = n - (i*num[0] + j * num[1]);
			if (temp >= 0 && temp%num[2] == 0) return true;
		}
	}
	return false;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	for (int i = 0; i < 3; i++) cin >> num[i];
	cin >> n;
	cout<<solve();
}