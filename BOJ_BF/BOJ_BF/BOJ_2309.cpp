#include<iostream>
#include<algorithm>
using namespace std;
int m[9];
int main() {
	for (int i = 0; i < 9; i++) cin >> m[i];
	sort(m, m + 9);
	do {
		int sum = 0;
		for (int j = 0; j < 7; j++) sum += m[j];
		if (sum == 100) {
			for (int z = 0; z < 7; z++) cout << m[z] << '\n';
			break;
		}
	} while (next_permutation(m, m + 9));
}