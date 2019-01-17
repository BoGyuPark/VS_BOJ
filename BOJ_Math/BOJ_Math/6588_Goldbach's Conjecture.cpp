//BOJ_6588_Goldbach's Conjecture
#include<bits/stdc++.h>
using namespace std;
#define MAX 1000001
int p[MAX];
bool c[MAX];
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int pn = 0;
	for (int j = 2; j <= MAX - 1; j++) {
		if (c[j] == false) {
			p[pn++] = j;
			for (int z = j * 2; z <= MAX - 1; z += j) {
				c[z] = true;
			}
		}
	}
	
	while (1) {
		int n; cin >> n;
		if (n == 0)
			break;
		for (int i = 1; i < pn; i++) {
			if (c[n - p[i]] == false) {
				cout << n << " = " << p[i] << " + " << n-p[i] << '\n';
				break;
			}
		}
	}
	return 0;
}