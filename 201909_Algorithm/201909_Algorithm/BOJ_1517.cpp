/*BOJ 1517 버블 소트*/
#include<iostream>
using namespace std;
int n, list[500'001], sorted[500'001];
long long ans;

void merge(int l, int m, int r) {
	int idx = l;
	int i = l, j = m + 1;
	while (i <= m && j <= r) {
		if (list[i] > list[j]) {
			ans += m + 1 - i;
			sorted[idx++] = list[j++];
		}
		else sorted[idx++] = list[i++]; 
	}
	if (i > m) while (j <= r) sorted[idx++] = list[j++];
	else while (i <= m) sorted[idx++] = list[i++];
	for (int z = l; z <= r; z++) list[z] = sorted[z];
}

void mergeSort(int left, int right) {
	if (left < right) {
		int mid = (left + right) / 2;
		mergeSort(left, mid), mergeSort(mid + 1, right);
		merge(left, mid, right);
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) cin >> list[i];
	mergeSort(0, n - 1);
	cout << ans;
}