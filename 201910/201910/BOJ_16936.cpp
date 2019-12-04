/* BOJ 16936 ³ª3°ö2*/
#include<iostream>
using namespace std;
typedef long long ll;
int n, check[101];
ll arr[101], sel[101];
int isAble(ll value) {
	for (int i = 0; i < n; i++) {
		if (value == arr[i]) {
			if (!check[i]) return i;
			else return -1;
		}
	}
	return -1;
}
void go(ll now, int depth) {
	if (depth == n - 1) {
		sel[depth] = now;
		for (int j = 0; j < n; j++) cout << sel[j] << ' ';
		exit(0);
	}
	ll next = now / 3;
	if (now % 3 == 0) {
		int idx = isAble(next);
		if (idx != -1) {
			check[idx] = true;
			sel[depth] = now;
			go(next, depth + 1);
			check[idx] = false;
		}
	}
	
	next = now * 2;
	int idx = isAble(next);
	if (idx != -1) {
		check[idx] = true;
		sel[depth] = now;
		go(next, depth + 1);
		check[idx] = false;
	}
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) cin >> arr[i];
	for (int i = 0; i < n; i++) {
		go(arr[i], 0);
	}
}