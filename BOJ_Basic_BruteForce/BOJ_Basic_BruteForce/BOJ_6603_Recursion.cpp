#include<iostream>
#include<vector>
using namespace std;
int k, arr[14];
vector<int> v;
void go(int len, int index) {
	if (len == 6) {
		for (int i = 0; i < 6; i++) cout << v[i] << " ";
		cout << "\n";
		return;
	}
	if (index == k)	return;
	v.push_back(arr[index]);
	go(len + 1, index + 1);
	v.pop_back();
	go(len, index + 1);
}

int main() {
	while (1) {
		cin >> k;
		if (k == 0)	break;
		for (int i = 0; i < k; i++) cin >> arr[i];
		go(0, 0); cout << "\n";
	}
	return 0;
}