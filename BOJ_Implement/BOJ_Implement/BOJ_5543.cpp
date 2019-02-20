#include<iostream>
using namespace std;
int main() {
	int a[3] = { 0, };
	int b[2] = { 0, };
	int h = 0, c = 0;
	for (int i = 0; i < 3; i++) {
		cin >> a[i];
		if (a[i] < h || h == 0) h = a[i];
	}
	for (int i = 0; i < 2; i++) {
		cin >> b[i];
		if (b[i] < c || c == 0) c = b[i];
	}
	cout << h + c - 50;
}