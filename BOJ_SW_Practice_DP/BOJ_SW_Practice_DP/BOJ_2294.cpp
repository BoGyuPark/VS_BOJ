#include<iostream>
using namespace std;
int n, k, i, j, d[10001], nums[101];
int main() {
	cin >> n >> k;
	for (i = 0; i < n; i++) cin >> nums[i];
	for (i = 0; i <= k; i++) d[i] = -1;
	//d[i]�� i���� ����µ� �ʿ��� ������ �ּ� ����
	d[0] = 0;
	for (i = 0; i < n; i++) {
		for (j = 1; j <= k; j++) {
			//index���� �ְ�, ���� ���� �־�� �Ѵ�.
			if (j - nums[i] >= 0 && d[j - nums[i]] != -1) {
				//�湮���� ���ų� ���� ������ ���ο� ���� �� ���� ���
				if (d[j] == -1 || d[j] > d[j - nums[i]] + 1)
					d[j] = d[j - nums[i]] + 1;
			}
		}
	}
	cout << d[k];
}