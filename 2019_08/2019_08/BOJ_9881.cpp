// hill 최대 1000개 , 각 hill 높이 최대 100
#include<iostream>
using namespace std;
int n, arr[1001], ans = 2147483647;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) cin >> arr[i];
	for (int i = 1; i < 101; i++) {
		int needpay = 0;
		int s = i, e = i + 17;
		for (int j = 0; j < n; j++) {
			int dif = arr[j] - s;	
			if (dif < 0) {
				needpay += (dif*dif);
			}else{
				if (dif > 17) {
					dif = arr[j] - e;
					needpay += (dif*dif);
				}
			}
		}
		if (ans > needpay ) ans = needpay;
	}
	cout << ans;
}