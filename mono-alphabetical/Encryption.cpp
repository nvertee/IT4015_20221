#include <bits/stdc++.h>
using namespace std;

int arr[100]; map<char, char> en; char cod[100];
string plain;

//Random key for mono-alphabetical
int partition(int start, int end) //use in quickSort
{
    int pivot = arr[start];
    int count = 0;
    for (int i = start + 1; i <= end; i++) {
        if (arr[i] <= pivot)
            count++;
    }
    int pivotIndex = start + count;
    swap(arr[pivotIndex], arr[start]);
 	swap(cod[pivotIndex], cod[start]);

    int i = start, j = end;
    while (i < pivotIndex && j > pivotIndex) {
        while (arr[i] <= pivot) {
            i++;
        }
        while (arr[j] > pivot) {
            j--;
        }
        if (i < pivotIndex && j > pivotIndex) {
            swap(arr[i++], arr[j--]);
            swap(cod[i++], cod[j--]);
        }
    }
    return pivotIndex;
}
 
void quickSort(int start, int end)
{
    if (start >= end)
        return;
    int p = partition(start, end);
    quickSort(start, p - 1);
    quickSort(p + 1, end);
}

void randomkey() {
	//Sinh random key
	//Ket qua random key duoc luu trong map en[] (TIN - ma)
	srand(time(NULL));
	for (int i='A'; i<='Z'; i++)
		{
			cod[i-'A']=i;
			arr[i-'A']=rand();
		}
	quickSort(0,'Z'-'A');
	for (int i='A'; i<='Z'; i++)
		en[i]=cod[i-'A'];
	cout << "KEY: ";
	for (int i='A'; i<='Z'; i++)
		cout << en[i];
}

void Inputkey() //nhap KEY tu ban phim
{
	cout << "NHAP VAO BANG THE: (example: BEDKF...)" << endl;
	fflush(stdin);
	for (int i='A'; i<='Z'; i++) cin >> en[i];
	}

void Encryp() {
	string cipher = "";
	for (int i=0; i< plain.length(); i++)
		if (plain[i]==' ') cipher += ' ';
			else cipher += en[plain[i]];
	cout << endl;
	cout << "CIPHERTEXT: "<< cipher;
}
int main() {

	cout << "CHUONG TRINH MA HOA MOT BANG THE" << endl;
	cout << "HAY CHON CHUC NANG:" <<  endl << "1. KEY NGAU NHIEN" << endl << "2. NHAP KEY" << endl << "------------------" << endl;
	int x;
	cin >> x;
	switch (x) {
		case 1:
			cout << "----------------------------" << endl << "Hay nhap TIN (plaintext): ";
			fflush(stdin);
			getline(cin, plain);
			randomkey();
			Encryp();
			break;
		case 2:
			cout << "----------------------------" << endl << "Hay nhap TIN (plaintext): ";
			fflush(stdin);
			getline(cin, plain);
			Inputkey();
			Encryp();
			break;
		default:
			cout << "Khong ton tai chuc nang nay!";
			break;
			
	}
	return 0;
}
