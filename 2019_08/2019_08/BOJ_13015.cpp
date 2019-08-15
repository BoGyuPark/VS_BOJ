/*BOJ 13015 º° Âï±â 23*/
#include<iostream>
using namespace std;
int n;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	int pivot = n - 1, e = 4 * n - 3;
	for (int i = 0; i < n * 2 - 1; i++) {

		if (i == 0 || i == n * 2 - 2) {
			for (int j = 0; j < e; j++) {
				if (j < n || j > e - n - 1) cout << '*';
				else cout << ' ';
			}
		}
		else if (i < n) {
			for (int j = 0; j < e; j++) {
				if (j == i || j == i + pivot || j == e - i - 1 || j == e - i - pivot - 1) {
					cout << '*';
					if (j == e - i - 1) break;
				}
				else cout << ' ';
			}
		}
		else {
			int temp = n * 2 - 2 - i;
			for (int j = 0; j < e; j++) {
				if (j == temp || j == temp + pivot || j == e - 1 - temp || j == e - 1 - temp - pivot) {
					cout << '*';
					if (j == e - 1 - temp) break;
				}
				else cout << ' ';
			}
		}
		cout << '\n';
	}
}