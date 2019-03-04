#include<iostream>
#include<algorithm>
using namespace std;
int k, wait[13], c[13];
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	while (true) {
		cin >> k;
		if (k == 0) break;
		for (int i = 0; i < k; i++) cin >> wait[i];
		for (int i = 0; i < 6; i++) c[i] = 1;
		do {
			for (int i = 0; i < k; i++) 
				if (c[i] == 1) cout << wait[i] << ' ';
			cout << '\n';
		} while (prev_permutation(c, c + k));
		cout << '\n';
	}
}