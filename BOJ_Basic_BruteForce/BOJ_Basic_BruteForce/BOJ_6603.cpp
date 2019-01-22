#include<iostream>
#include<algorithm>
using namespace std;
int main() {
	int n, temp;
	while (1) {
		int arr[15];
		int c[15] = { 0,0,0,0,0,0,1,1,1,1,1,1,1,1,1 };
		cin >> n;
		if (n == 0)	break;
		for (int i = 0; i < n; i++) cin >> arr[i];
		do {
			for (int i = 0; i < n; i++) {
				if (c[i] == 0)
					cout << arr[i] << ' ';
			}
			cout << '\n';
		} while (next_permutation(c, c + n));
		cout << '\n';
	}
	return 0;
}