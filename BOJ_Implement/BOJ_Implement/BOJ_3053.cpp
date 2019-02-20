#include<iostream>
#define M_PI 3.14159265358979323846
using namespace std;
int main() {
	int n; cin >> n;
	cout << fixed;
	cout.precision(6);
	cout << M_PI * n*n << '\n';
	cout << (double)2 * n*n;
}