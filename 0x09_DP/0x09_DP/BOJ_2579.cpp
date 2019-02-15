#include<iostream>
#include<algorithm>
using namespace std;
long long n, a[301], d[301], i;
int main() {
	cin >> n; for (i = 1; i <= n; i++) cin >> a[i];
	d[1] = a[1];	d[2] = a[1] + a[2];
	for (i = 3; i <= n; i++) 
		d[i] = max(d[i - 3] + a[i - 1] + a[i], d[i - 2] + a[i]);
	cout << d[n];
}