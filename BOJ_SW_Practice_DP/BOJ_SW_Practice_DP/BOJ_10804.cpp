#include<iostream>
#include<algorithm>
using namespace std;
int a[21];
int main() {
	int s, e;
	for (int i = 1; i <= 20; i++) a[i] = i;
	for (int i = 0; i < 10; i++) {
		cin >> s >> e;
		int dif = (e - s + 1) / 2;
		while (dif--) {
			swap(a[s], a[e]);
			s++; e--;
		}
	}
	for (int i = 1; i <= 20; i++) cout << a[i] << ' ';
}