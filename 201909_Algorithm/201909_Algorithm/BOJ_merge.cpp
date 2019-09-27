/*BOJ 머지소트*/
#include<iostream>
using namespace std;
int n, list[1'000'001], temp[1'000'001];
void merge(int s, int mid, int e) {
	int idx = s;
	int left_s = s;
	int right_s = mid + 1;

	while (left_s <= mid && right_s <= e) {
		if (list[left_s] < list[right_s]) temp[idx++] = list[left_s++];
		else temp[idx++] = list[right_s++];
	}

	//왼쪽 배열을 모두 고름
	if (left_s > mid) {
		for (int i = right_s; i <= e; i++) temp[idx++] = list[i];
	}
	else {
		for (int i = left_s; i <= mid; i++) temp[idx++] = list[i];
	}

	for (int i = s; i <= e; i++) list[i] = temp[i];
}

void mergeSort(int s, int e) {
	if (s < e) {
		int mid = (s + e) / 2;
		mergeSort(s, mid);
		mergeSort(mid + 1, e);
		//merge(s, mid, e);
		int idx = s;
		int left_s = s;
		int right_s = mid + 1;

		while (left_s <= mid && right_s <= e) {
			if (list[left_s] < list[right_s]) temp[idx++] = list[left_s++];
			else temp[idx++] = list[right_s++];
		}

		//왼쪽 배열을 모두 고름
		if (left_s > mid) {
			for (int i = right_s; i <= e; i++) temp[idx++] = list[i];
		}
		else {
			for (int i = left_s; i <= mid; i++) temp[idx++] = list[i];
		}

		for (int i = s; i <= e; i++) list[i] = temp[i];
	}
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) cin >> list[i];
	mergeSort(0, n - 1);
	for (int i = 0; i < n; i++) cout << list[i] << '\n';
}