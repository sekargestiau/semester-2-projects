/*

**Program Penentuan Jumlah Siswa Remedial dan Penentuan Nilai-nilai Ujian Tertinggi**

Nama	: Sekar Gesti Amalia Utami
NIM	: M0521071
Kelas	: C
Prodi	: Informatika

*/

#include <iostream>
#include <numeric>
#include <algorithm>
#include <iterator>

using namespace std;


// fungsi insertion sort dengan ascending order (urutan naik)
void insertionSortAscending(float arr[], int n){
	int i, key, j;
	for (i = 1; i < n; i++){
		key = arr[i];
		j = i - 1;

		while (j >= 0 && arr[j] > key){
			arr[j + 1] = arr[j];
			j = j - 1;
		}
		arr[j + 1] = key;
	}
}

// fungsi insertion sort dengan descending order (urutan turun)
void insertionSortDescending(float arr[], int n){
    for (int i = 1; i < n; i++){
        int key = arr[i];
        int j = i - 1;
        while (key > arr[j] && j >= 0){
            arr[j + 1] = arr[j];
            --j;
        }
        arr[j + 1] = key;
    }
}

// fungsi print 5 nilai ujian tertinggi
void print5NilaiTertinggi(float arr[], int n){
	int k;
    if (n >= 5){
        for(int i=n-1, k=0; i >= 0 && k < 5; i--, k++){
            cout << "[" << k+1 << "] " << arr[i] << "\n";
        }
    }else{
        cout << "\n[Jumlah siswa yang Anda input tidak mencapai 5 orang. Informasi terkait 5 nilai tertinggi tidak dapat ditampilkan]" << endl;
    }
}

// fungsi print array
void printArray(float arr[], int n){
	int i;
	for (i = 0; i < n; i++)
		cout << "[" << i+1 << "] " << arr[i] << " " << endl;
	cout << endl;
}


int main(){
    int choice;
	cout << "=============================================================" << endl;
    cout << "----------- PENENTUAN JUMLAH SISWA YANG REMIDIAL ------------" << endl;
    cout << "=============================================================\n" << endl;
    
	do {
        cout << "MENU" << endl;
        cout << "1. CEK JUMLAH SISWA YANG REMIDIAL" << endl;
        cout << "2. KELUAR" << endl;
        cout << "\n---------------------------------------" << endl;
        cout << "Masukkan angka menu yang Anda pilih : ";
        cin >> choice;
        switch (choice){
            case 1:
				int jumlahSiswa, batasLulus;
				int counter = 0;
			
				cout << "\n[Anda bisa memasukkan nilai dalam bentuk desimal]\nMasukkan jumlah siswa : ";
				cin >> jumlahSiswa;
                cout << "Masukkan batas nilai lulus : ";
                cin >> batasLulus;
				float arr[jumlahSiswa];

				for(int k = 0; k < jumlahSiswa; k++){
					cout << "[" << k+1 << "] Masukkan nilai ujian : ";
					cin >> arr[k];
				}
				int n = sizeof(arr) / sizeof(arr[0]);
                cout << "\nData nilai siswa yang Anda masukkan :" << endl;
				printArray(arr, n);
				cout << "Data nilai siswa terurut (terbesar ke terkecil):" << endl;
				insertionSortDescending(arr, n);
				printArray(arr, n);
				cout << "Data nilai siswa terurut (terkecil ke terbesar):" << endl;
				insertionSortAscending(arr, n);
				printArray(arr, n);
				
				float arrRemidial[n];
				for (int i = 0; i < n; i++){
					if(arr[i] < batasLulus){
					arrRemidial[i] == arr[i];
					counter++;
					}
				}
				cout << "\n=> Batas nilai lulus adalah " << batasLulus << ". Maka, jumlah siswa yang remidial : " << counter << " orang" << endl;
                cout << "=> 5 Nilai Tertinggi di Kelas :" << endl;
                print5NilaiTertinggi(arr, n);
                cout << "\n---------------------------------------" << endl;
				
			break;
		}
	}while(choice != 2);

	return 0;
}
