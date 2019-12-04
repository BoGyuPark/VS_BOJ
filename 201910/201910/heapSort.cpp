#include<iostream>
using namespace std;
int n, arr[1'000'001];
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n; for (int i = 0; i < n; i++) cin >> arr[i];
	//heapify
	for (int i = 1; i < n; i++) {
		int c = i;
		do {
			int root = (c - 1) / 2;
			if (arr[root] < arr[c]) {
				swap(arr[root], arr[c]);
			}
			c = root;
		} while (c != 0);
	}
	for (int i = n - 1; i >= 0; i--) {
		swap(arr[i], arr[0]);
		int root = 0, c = 1;
		do {
			c = root * 2 + 1;
			if (c < i - 1 && arr[c] < arr[c + 1]) c++;
			if (c < i && arr[root] < arr[c]) swap(arr[root], arr[c]);
			root = c;
		} while (c < i);
	}
	for (int i = 0; i < n; i++) cout << arr[i] << '\n';
}