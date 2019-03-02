#include<iostream>
using namespace std;
int n, cnt = 0;
int main() {
	cin >> n;
	if (n <= 99) cout << n;
	else {
		for (int i = 100; i <= n; i++) {
			int dif = i % 10 - ((i%100)/ 10);
			if (dif == (((i % 100) / 10) - i / 100)) 
				cnt++;
		}
		cout << cnt + 99;
	}
}