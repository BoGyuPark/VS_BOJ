/*BOJ 4673 ¼¿ÇÁ³Ñ¹ö*/
#include<iostream>
using namespace std;
int num[10100];
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	for (int i = 1; i < 10001; i++) {
		int temp = i;
		int next = temp;
		while (temp != 0) {
			next += (temp % 10);
			temp /= 10;
		}
		num[next] = true;
	}
	for (int i = 1; i < 10001; i++) {
		if (num[i]) continue;
		cout << i << '\n';
	}
}