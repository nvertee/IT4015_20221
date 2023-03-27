#include <bits/stdc++.h>
using namespace std;

string plain, cipher;
int key;
void encryp() {
	cipher = "";
	for (int i=0; i<plain.length(); i++)
		if (plain[i]==' ') cipher += ' ';
		else { 
			if (plain[i]>='a') cipher += ((plain[i]-'a'+key)%26+'a');
			else cipher += ((plain[i]-'A'+key)%26+'A');
		}
			cout << cipher << endl;
}

void decryp() {
	plain = "";
	for (int i=0; i<cipher.length(); i++)
		if (cipher[i]==' ') plain += ' ';
		else { 
			if (cipher[i]>='a') plain += ((cipher[i]-'a'-key+26*key)%26+'a');
			else plain += ((cipher[i]-'A'-key+26*key)%26+'A');
		}
			cout << plain << endl;
}

void crack() {
	for (int i=0; i<=25; i++) {
		key = i;
		decryp();
	}
}
int main() {
	
	cout << "CHUONG TRINH MA HOA/ GIAI MA/ PHA MA - MA DICH SHIFT CIPHER" << endl;
	cout << "-----------------------------------------------------------" << endl;
	cout << "Vui long chon chuc nang: " << endl << "1: Ma hoa" << endl << "2: Giai ma" << endl << "3: Pha ma" << endl;
	cout << "-----------------------------------------------------------" << endl;
	
	int x;
	cin >> x;
	
	switch (x) {
		case 1:
			cout << "--------------" << endl << "MA HOA SHIFT CIPHER" << endl << "Hay nhap TIN (plaintext):" << endl;
			fflush(stdin);
			getline(cin, plain);
			cout << "Hay nhap KHOA:" << endl;
			cin >> key;
			cout << "------------------" << endl;
			cout << "Ket qua MA: ";
			encryp();
			break;
		case 2:
			cout << "--------------" << endl << "GIAI MA SHIFT CIPHER" << endl << "Hay nhap MA (ciphertext):" << endl;
			fflush(stdin);
			getline(cin, cipher);
			cout << "Hay nhap KHOA:" << endl;
			cin >> key;
			cout << "------------------" << endl;
			cout << "Ket qua TIN: ";
			decryp();
			break;
		case 3:
			cout << "--------------" << endl << "PHA MA SHIFT CIPHER" << endl << "Hay nhap MA (ciphertext):" << endl;
			fflush(stdin);
			getline(cin, cipher);
			cout << "26 TIN co the la TIN chinh xac:" << endl;
			crack();
			break;
		default:
			cout << "Khong ton tai chuc nang nay!";
			break;
			
	}
	return 0;
}


