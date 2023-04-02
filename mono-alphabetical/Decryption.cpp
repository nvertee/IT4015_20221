#include <bits/stdc++.h>
using namespace std;

int arr[100]; map<char, char> en; char cod[100];
string cipher;

void Inputkey() //nhap KEY tu ban phim
{
	cout << "NHAP VAO BANG THE: (example: BEDKF...)" << endl;
	fflush(stdin);
	for (int i='A'; i<='Z'; i++) {
		char x;
			cin >> x;
			en[x]=i;	
	}
}

void Decryp() {
	string plain = "";
	for (int i=0; i< cipher.length(); i++)
		if (cipher[i]==' ') plain += ' ';
			else plain += en[cipher[i]];
	cout << endl;
	cout << "PLAINTEXT: "<< plain;
}
int main() {

	cout << "CHUONG TRINH MA HOA MOT BANG THE" << endl;
	cout << "----------------------------" << endl << "Hay nhap MA (CIPHERTEXT): " << endl;
	fflush(stdin);
	getline(cin, cipher);
	Inputkey();
	Decryp();
	return 0;
}
