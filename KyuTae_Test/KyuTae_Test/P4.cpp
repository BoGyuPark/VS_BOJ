#include<iostream>
#include<algorithm>
using namespace std;
int n, m, A[100000], B[100000];
int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> A[i];
	for (int i = 0; i < m; i++) cin >> B[i];
	sort(A, A + n);
	sort(B, B + m);
	int i = 0;
	for (int k = 0; k < n; k++) {
		while (i < m - 1 && B[i] < A[k]) {
			i += 1;
			if (A[k] == B[i]) {
				cout << A[k] << '\n';
				return 0;
			}
		}
		if (A[k] == B[i]) {
			cout << A[k] << '\n';
			return 0;
		}
	}
	cout << -1;
	return 0;

}