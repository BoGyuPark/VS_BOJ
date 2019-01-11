//BOJ_1149_RGBdistance
#include<bits/stdc++.h>
using namespace std;
int arr[1001][3] = { 0, };
int FindMin(int mIndex, int N)
{
	int R, G, B;
	int mini, minIndex;
	int sum = 0;

	for (int j = 0; j < N; j++) {
		if (j == 0) {
			mini = arr[0][mIndex];	minIndex = mIndex;
		}
		else {
			//이전 min이 Red면
			if (minIndex == 0) {
				if (arr[j][1] > arr[j][2]) {
					mini = arr[j][2];
					minIndex = 2;
				}
				else {
					mini = arr[j][1];
					minIndex = 1;
				}
			}
			//이전 min이 Green이면
			else if (minIndex == 1) {
				if (arr[j][0] > arr[j][2]) {
					mini = arr[j][2];
					minIndex = 2;
				}
				else {
					mini = arr[j][0];
					minIndex = 0;
				}
			}
			else {
				if (arr[j][0] > arr[j][1]) {
					mini = arr[j][1];
					minIndex = 1;
				}
				else {
					mini = arr[j][0];
					minIndex = 0;
				}
			}
		}
		sum += arr[j][minIndex];
	}
	return sum;
}

int main() {
	int N; cin >> N;
	int R, G, B, ans;
	for (int j = 0; j < N; j++){
		cin >> R >> G >> B;
		arr[j][0] = R; arr[j][1] = G; arr[j][2] = B;
	}
	int arr[3] = { 0, };
	arr[0] = FindMin(0, N);
	arr[1] = FindMin(1, N);
	arr[2] = FindMin(2, N);
	ans = arr[0];
	for (int i = 1; i < 3; i++) {
		if (ans > arr[i])
			ans = arr[i];
	}
	cout << ans << "\n";
	return 0;
}