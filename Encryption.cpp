#include <bits/stdc++.h>
using namespace std;

string plain;
int key;
void encryp() {
	string cipher = "";
	for (int i=0; i<plain.length(); i++)
		if (plain[i]==' ') cipher += ' ';
		else { 
			if (plain[i]>='a') cipher += ((plain[i]-'a'+key)%26+'a');
			else cipher += ((plain[i]-'A'+key)%26+'A');
		}
			cout << cipher;
}
int main() {
	/* 	Input:
			+ Line 1: plaintext
			+ Line 2: key
		Output: Ciphertext used Shift cipher
	*/
	getline(cin,plain);
	cin >> key;
	encryp();
	return 0;
}

