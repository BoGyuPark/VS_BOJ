//BOJ_1676_NumOfZero_Factorial
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	int N; cin >> N;
	int cnt = 0;
	int mod = 10;
	int arr[506] = { 0, };
	ll t = 1;
	for (int i = 1; i <= N; i++){
		arr[i] = i;
	}

	int flag = -1;
	int twoflag = 0, fivFlag = 0;
	while (flag!=0){
		flag = 0;
		for (int i = 1; i <= N; i++) {
			if (arr[i] % 10 == 0) {
				arr[i] /= 10;
				cnt++;
				flag++;
			}
			else if (arr[i] % 2 == 0){
				arr[i] /= 2;
				twoflag++;
				flag++;
			}
			else if (arr[i] % 5 == 0) {
				arr[i] /= 5;
				fivFlag++;
				flag++;
			}
		}
	}
	int temp = (twoflag > fivFlag ? fivFlag : twoflag);
	cnt += temp;
	for (int i = 1; i <= N; i++) {
		if (arr[i] != 0) {
			t *= arr[i];
			if (t % 10 == 0) {
				cnt++;
				t /= 10;
			}
		}
	}

	cout << cnt;
	return 0;
}