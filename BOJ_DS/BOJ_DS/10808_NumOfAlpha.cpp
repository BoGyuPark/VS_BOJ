//BOJ_10808_NumOfAlpha
#include<bits/stdc++.h>
using namespace std;
int main() {
	char alpha[] = "abcdefghijklmnopqrstuvwxyz";
	char word[100] = { 0, };
	int temp[30] = { 0, };
	int wordLen, alphaLen;
	cin >> word;
	wordLen = strlen(word);
	alphaLen = strlen(alpha);
	for (int i = 0; i < wordLen; i++) {
		for (int j = 0; j < alphaLen; j++) {
			if (word[i] == alpha[j]) {
				temp[j]++;
				break;
			}
		}
	}

	for (int i = 0; i < alphaLen; i++)
		cout << temp[i] << ' ';
	return 0;
}