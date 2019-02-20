#include<iostream>
using namespace std;
int main() {
	int a[104] = { 0, }, n, sum = 0; cin >> n; 
	for (int i = 0; i < n; i++) {cin >> a[i]; sum += a[i];}
	if (sum < n - sum) cout << "Junhee is not cute!";
	else cout << "Junhee is cute!";
}