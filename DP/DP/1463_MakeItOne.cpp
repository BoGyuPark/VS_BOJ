//BOJ_1463_MakeItOne
#include<bits/stdc++.h>
using namespace std;
int main()
{
	int N; cin >> N;
	//int형 배열은 25만까지만 가능
	int *d = new int[N + 1];
	d[1] = 0;
	for (int i = 2; i <= N; i++) {
		d[i] = d[i - 1] + 1;
		if (i % 2 == 0 && d[i] > d[i / 2] + 1) {
			d[i] = d[i / 2] + 1;
		}
		if (i % 3 == 0 && d[i] > d[i / 3] + 1) {
			d[i] = d[i / 3] + 1;
		}
	}
	cout << d[N];
	delete[] d;
	return 0;
}