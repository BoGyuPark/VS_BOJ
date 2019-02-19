#include<iostream>
#include<algorithm>
using namespace std;
int m, x, y, a[4] = { 0,1,2,3, }, ind1, ind2;
int main() {
	cin >> m;
	while (m--) {
		cin >> x >> y;
		for (int i = 1; i < 4; i++) {
			if (a[i] == x) ind1 = i;
			if (a[i] == y) ind2 = i;
		}
		swap(a[ind1], a[ind2]);
	}
	cout << a[1];
}