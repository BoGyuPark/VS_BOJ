#include<iostream>
using namespace std;
int n, arr[1'000'001], sorted[1'000'001];
void merge(int s, int m, int e) {
	int i = s, j = m + 1, k = s;
	while (i <= m && j <= e) {
		if (arr[i] < arr[j]) sorted[k] = arr[i], i++;
		else sorted[k] = arr[j], j++;
		k++;
	}
	if (i > m) {
		for (int a = j; a <= e; a++) sorted[k] = arr[a], k++;
	}
	else {
		for (int a = i; a <= m; a++) sorted[k] = arr[a], k++;
	}
	for (int a = s; a <= e; a++) arr[a] = sorted[a];
}

void mergeSort(int s, int e) {
	if (s < e) {
		int middle = (s + e) / 2;
		mergeSort(s, middle);
		mergeSort(middle + 1, e);
		merge(s, middle, e);
	}
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n; for (int i = 0; i < n; i++) cin >> arr[i];
	mergeSort(0, n - 1);
	for (int i = 0; i < n; i++) cout << arr[i] << '\n';
}