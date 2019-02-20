#include<iostream>
using namespace std;
int main() {
	int sum = 0, f,t;
	cin >> f;
	for (int i = 0; i < 9; i++) {
		cin >> t;
		sum += t;
	}
	cout << f - sum;
}