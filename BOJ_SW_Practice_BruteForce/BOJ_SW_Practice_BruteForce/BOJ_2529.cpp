#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
char bu[10];
int k, i, num[10], sum, flag;
int main() {
	cin >> k;	ios_base::sync_with_stdio(false); cin.tie(NULL);
	for (i = 0; i < k; i++) cin >> bu[i];
	for (i = 0; i < 10; i++)	num[i] = i;
	string maxi = "-1", mini = "9999999999";
	do {
		flag = 0;
		for (i = 0; i < k; i++) {
			if (bu[i] == '<') {
				if (num[i] < num[i + 1]) continue;
				else {
					flag = 1;
					break;
				}
			}
			if (bu[i] == '>') {
				if (num[i] > num[i + 1]) continue;
				else {
					flag = 1;
					break;
				}
			}
		}
		if (flag == 0) {
			string temp = "";
			for (i = 0; i < k + 1; i++) {
				temp += to_string(num[i]);
			}
			if (maxi < temp) maxi = temp;
			if (mini > temp)	mini = temp;
		}
	} while (next_permutation(num, num + 10));
	::cout << maxi << "\n" << mini;
}