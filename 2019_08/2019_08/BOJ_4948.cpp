/*BOJ 4948 베르트랑 공준*/
#include<iostream>
using namespace std;
#define MAX 246913
int arr[MAX], T;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	arr[1] = true;
	for (int i = 2; i < MAX; i++) {
		if (arr[i]) continue;
		for (int j = i * 2; j < MAX; j += i) arr[j] = true;
	}

	while (true){
		cin >> T;
		if (T == 0) break;
		int cnt = 0;
		for (int i = T + 1; i <= T * 2; i++) {
			if (arr[i] == false) cnt++;
		}
		cout << cnt << '\n';
	}
}