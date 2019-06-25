#include<iostream>
#include<vector>
using namespace std;
int sel[3], c[20], arr[20], Max, valueList[20];
vector<pair<int, int>> v;
void dfs(int index, int start) {
	if (index == 2) {
		v.push_back({ sel[0],sel[1] });
		return;
	}
	for (int i = start; i < 20; i++) {
		if (c[i] == true) continue;
		if (arr[i] != -1) {
			c[i] = true;
			sel[index] = arr[i];
			dfs(index + 1, i);
			c[i] = false;
		}
	}
}

void removeValue(int t) {
	for (int i = 0; i < 20; i++) {
		if (arr[i] == t) {
			arr[i] = -1;
			return;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int a, b;
	int j = 1;
	for (int i = 0; i < 20; i+=2) {
		arr[i] = arr[i + 1] = j;
		j++;
	}
	cin >> a >> b;
	int myIdx = 0;
	myIdx = (a == b ? a + 9 : (a + b) % 10);

	removeValue(a);	removeValue(b);
	dfs(0, 0);

	for (auto i : v) {
		//¶¯
		if (i.first == i.second) valueList[i.first + 9]++;	
		//²ý
		else valueList[(i.first + i.second) % 10]++;	
	}

	Max = v.size();
	int sum = 0;
	for (int i = 0; i < myIdx; i++) {
		sum += valueList[i];
	}
	cout << fixed;
	cout.precision(3);
	cout << sum / (double)Max;
}