#include<iostream>
using namespace std;
int main() {
	int A, B, C, s, e, sum = 0, a[101] = { 0, };	cin >> A >> B >> C;
	for (int i = 0; i < 3; i++) {
		cin >> s >> e;
		for (int j = s; j < e; j++) a[j]++;
	}
	for (int i = 1; i < 101; i++) {
		if (a[i] != 0) {
			if (a[i] == 1) 	sum += A;
			else if (a[i] == 2) sum += (2 * B);
			else sum += (3 * C);
		}
	}
	cout << sum;
}