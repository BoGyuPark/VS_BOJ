#include<iostream>
using namespace std;
int n, k, i, j, d[10001], nums[101];
int main() {
	cin >> n >> k;
	for (i = 0; i < n; i++) cin >> nums[i];
	for (i = 0; i <= k; i++) d[i] = -1;
	//d[i]는 i원을 만드는데 필요한 동전의 최소 개수
	d[0] = 0;
	for (i = 0; i < n; i++) {
		for (j = 1; j <= k; j++) {
			//index내에 있고, 이전 값이 있어야 한다.
			if (j - nums[i] >= 0 && d[j - nums[i]] != -1) {
				//방문한적 없거나 이전 값보다 새로운 값이 더 작은 경우
				if (d[j] == -1 || d[j] > d[j - nums[i]] + 1)
					d[j] = d[j - nums[i]] + 1;
			}
		}
	}
	cout << d[k];
}