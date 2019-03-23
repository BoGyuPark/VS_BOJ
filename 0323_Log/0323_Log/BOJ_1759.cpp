#include<iostream>
#include<algorithm>
using namespace std;
char wait[16], sel[16];
int l, n, c[16];
void dfs(int index,int start, int mo, int ja) {
	if (index == l) {
		if (mo >= 1 && ja >= 2) {
			for (int j = 0; j < l; j++) cout << sel[j];
			cout << '\n';
			return;
		}else return;
	}
	for (int i = start; i < n; i++) {
		if (c[i] == true) continue;
		c[i] = true;
		sel[index] = wait[i];
		if (wait[i] == 'a' || wait[i] == 'e' || wait[i] == 'i' || wait[i] == 'o' || wait[i] == 'u') 
			dfs(index + 1, i, mo + 1, ja);
		else dfs(index + 1, i, mo, ja + 1);
		c[i] = false;
	}
}
int main() {
	cin >> l >> n;
	//a c i s t w
	for (int i = 0; i < n; i++) cin >> wait[i];
	sort(wait, wait + n);
	dfs(0,0,0,0);
}