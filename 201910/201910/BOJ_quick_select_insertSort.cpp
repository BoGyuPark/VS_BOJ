#include<iostream>
using namespace std;
int n, arr[1001];
void quickSort(int s, int e) {
	if (s >= e) return;
	int pivot = s, i = s + 1, j = e;
	while (i <= j) {
		while (arr[pivot] >= arr[i]) i++;
		while (j > s && arr[pivot] <= arr[j]) j--;
		if (i > j) swap(arr[pivot], arr[j]);
		else swap(arr[i], arr[j]);
	}
	quickSort(s, j - 1);
	quickSort(j + 1, e);
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) cin >> arr[i];
	quickSort(0, n - 1);
	for (int i = 0; i < n; i++) cout << arr[i] << '\n';
}