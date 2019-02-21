#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int a[1001], n;
int main() {
	for (int t = 1; t <= 10; t++) {
		cin >> n;
		int ans = 0;
		for (int i = 0; i < n; i++)	cin >> a[i];
		for (int i = 2; i < n; i++) {
			if(a[i] == 0) continue;
			int temp = a[i];
			//¿ÞÂÊ Àü¸Á
			int ldif = 1000; int lfag = false;
			for (int j = 1; j <= 2; j++) {
				if (temp <= a[i - j]) {
					lfag = true;
					break;
				}
				else {
					if (ldif > temp - a[i - j]) {
						ldif = temp - a[i - j];
					}
				}
			}
			//¿À¸¥ÂÊ Àü¸Á
			int rdif = 1000; int rflag = false;
			for (int k = 1; k <=2; k++) {
				if (temp <= a[i + k]) {
					rflag = true;
					break;
				}
				else {
					if (rdif > temp - a[i +k ]) {
						rdif = temp - a[i + k];
					}
				}
			}
			if (lfag == true || rflag == true) ans += 0;
			else ans += min(rdif, ldif);
		}
		cout << '#' << t << ' ' << ans << '\n';
	}
}