/*BOJ 1182 부분수열의 합*/
#include<iostream>
using namespace std;
int n, s, arr[21];
int cnt = 0;
void go(int index, int sum) {

	if (index == n) {
		if (sum == s) {
			cnt++;
			return;
		}
		return;
	}
	go(index + 1, sum + arr[index]);
	go(index + 1, sum);
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> s;
	for (int i = 0; i < n; i++) cin >> arr[i];
	go(0, 0);
	if (s == 0) cnt--;
	cout << cnt;
}
///*BOJ 1182 부분수열의 합*/
//#include<iostream>
//using namespace std;
//int n, s, arr[21], sel[21], check[21];
//int cnt = 0;
//void go(int index, int start, int dest) {
//	
//	if (index == dest) {
//		int sum = 0;
//		for (int j = 0; j < dest; j++) sum += sel[j];
//		if (sum == s) cnt++;
//		return;
//	}
//	for (int i = start; i < n; i++) {
//		if (check[i]) continue;
//		check[i] = true;
//		sel[index] = arr[i];
//		go(index + 1, i, dest);
//		check[i] = false;
//	}
//}
//int main() {
//	ios_base::sync_with_stdio(0); cin.tie(0);
//	cin >> n >> s;
//	for (int i = 0; i < n; i++) cin >> arr[i];
//	for (int i = 1; i <= n; i++) go(0,0,i);
//	cout << cnt;
//}