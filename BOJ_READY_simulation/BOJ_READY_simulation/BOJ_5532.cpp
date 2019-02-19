#include<iostream>
using namespace std;
int main() {
	int L, A, B, C, D;
	cin >> L >> A >> B >> C >> D;
	for (int i = 1; i <= L; i++) {
		if (A - C * i <= 0 && B - D * i <= 0) {
			cout << L - i;
			break;
		}
	}
}