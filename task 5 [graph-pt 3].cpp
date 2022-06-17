#include <iostream>
#include <map>

using namespace std;

map<std::string, std::string> perwakilan;

string find(string X) {
        if (perwakilan[X] == X) {
            return X;
        }
        return find(perwakilan[X]);
    }


void merge(string A, string B) {
    string wakilA = find(A);
    string wakilB = find(B);

    perwakilan[wakilA] = wakilB;

}

int main(){
    int choice, kotaAsal, kotaTujuan;

    perwakilan["Bus"] = "Bus";
    perwakilan["Kereta Api"] = "Kereta Api";
    perwakilan["Kapal Feri"] = "Kapal Feri";
    perwakilan["Pesawat"] = "Pesawat";
    perwakilan["Kota Surakarta"] = "Kota Surakarta";
    perwakilan["Kota Bogor"] = "Kota Bogor";
    perwakilan["Kota Surabaya"] = "Kota Surabaya";
    perwakilan["Kota Semarang"] = "Kota Semarang";
    perwakilan["Kota Jakarta"] = "Kota Jakarta";
    perwakilan["Kota Makassar"] = "Kota Makassar";
    perwakilan["Kota Jayapura"] = "Kota Jayapura";
    perwakilan["Kota Bali"] = "Kota Bali";
    perwakilan["Kota Pontianak"] = "Kota Pontianak";
    perwakilan["Kota Palembang"] = "Kota Palembang";


    merge("Bus","Kereta Api");
    merge("Kereta Api", "Kota Surakarta");
    merge("Kota Surakarta", "Kota Jakarta");
    merge("Kota Jakarta", "Kota Bogor");
    merge("Kota Bogor", "Kota Surabaya");
    merge("Kota Surabaya", "Kota Semarang");
    merge("Kapal Feri", "Pesawat");
    merge("Pesawat", "Kota Makassar");
    merge("Kota Makassar", "Kota Jayapura");
    merge("Kota Jayapura", "Kota Bali");
    merge("Kota Bali", "Kota Pontianak");
    merge("Kota Pontianak", "Kota Palembang");

    cout << "=============================================================" << endl;
    cout << "----------- MODA TRANSPORTASI KELILING INDONESIA ------------" << endl;
    cout << "=============================================================\n" << endl;  
    
    do {
        cout << "MENU" << endl;
        cout << "1. MENGECEK MODA TRANSPORTASI" << endl;
        cout << "2. KELUAR" << endl;
        cout << "\n---------------------------------------" << endl;
        cout << "Masukkan angka menu yang Anda pilih : ";
        cin >> choice;
        switch (choice){
            case 1:
            cout << "\n[DAFTAR KOTA-KOTA DI INDONESIA]" << endl;
            cout << "1. Kota Surakarta\n2. Kota Bogor\n3. Kota Surabaya\n4. Kota Semarang\n5. Kota Jakarta" << endl;
            cout << "6. Kota Makassar\n7. Kota Jayapura\n8. Kota Bali\n9. Kota Pontianak\n10. Kota Palembang" << endl;
            cout << "\nMasukkan Angka Kota Asal Anda   : ";
            cin >> kotaAsal;
            cout << "Masukkan Angka Kota Tujuan Anda : ";
            cin >> kotaTujuan;

            if((kotaAsal == 1 && kotaTujuan == 2) || (kotaAsal == 2 && kotaTujuan == 1)){
                if (find("Kota Surakarta") == find("Kota Bogor")){
                cout << "\n=> Anda bisa menggunakan moda transportasi Bus atau Kereta Api <=\n" << endl;
                cout << "\n---------------------------------------" << endl;
                }
            }else if((kotaAsal == 1 && kotaTujuan == 3) || (kotaAsal == 3 && kotaTujuan == 1)){
                if (find("Kota Surakarta") == find("Kota Surabaya")){
                cout << "\n=> Anda bisa menggunakan moda transportasi Bus atau Kereta Api <=\n" << endl;
                cout << "\n---------------------------------------" << endl;
                }
            }else if((kotaAsal == 1 && kotaTujuan == 4) || (kotaAsal == 4 && kotaTujuan == 1)){
                if (find("Kota Surakarta") == find("Kota Semarang")){
                cout << "\n=> Anda bisa menggunakan moda transportasi Bus atau Kereta Api <=\n" << endl;
                cout << "\n---------------------------------------" << endl;
                }
            }else if((kotaAsal == 1 && kotaTujuan == 5) || (kotaAsal == 5 && kotaTujuan == 1)){
                if (find("Kota Surakarta") == find("Kota Jakarta")){
                cout << "\n=> Anda bisa menggunakan moda transportasi Bus atau Kereta Api <=\n" << endl;
                cout << "\n---------------------------------------" << endl;
                }
            }else if((kotaAsal == 2 && kotaTujuan == 3) || (kotaAsal == 3 && kotaTujuan == 2)){
                if (find("Kota Bogor") == find("Kota Surabaya")){
                cout << "\n=> Anda bisa menggunakan moda transportasi Bus atau Kereta Api <=\n" << endl;
                cout << "\n---------------------------------------" << endl;
                }
            }else if((kotaAsal == 2 && kotaTujuan == 4) || (kotaAsal == 4 && kotaTujuan == 2)){
                if (find("Kota Bogor") == find("Kota Semarang")){
                cout << "\n=> Anda bisa menggunakan moda transportasi Bus atau Kereta Api <=\n" << endl;
                cout << "\n---------------------------------------" << endl;
                }
            }else if((kotaAsal == 2 && kotaTujuan == 5) || (kotaAsal == 5 && kotaTujuan == 2)){
                if (find("Kota Bogor") == find("Kota Jakarta")){
                cout << "\n=> Anda bisa menggunakan moda transportasi Bus atau Kereta Api <=\n" << endl;
                cout << "\n---------------------------------------" << endl;
                }
            }else if((kotaAsal == 3 && kotaTujuan == 4) || (kotaAsal == 4 && kotaTujuan == 3)){
                if (find("Kota Surabaya") == find("Kota Semarang")){
                cout << "\n=> Anda bisa menggunakan moda transportasi Bus atau Kereta Api <=\n" << endl;
                cout << "\n---------------------------------------" << endl;
                }
            }else if((kotaAsal == 3 && kotaTujuan == 5) || (kotaAsal == 5 && kotaTujuan == 3)){
                if (find("Kota Surabaya") == find("Kota Jakarta")){
                cout << "\n=> Anda bisa menggunakan moda transportasi Bus atau Kereta Api <=\n" << endl;
                cout << "\n---------------------------------------" << endl;
                }
            }else if((kotaAsal == 4 && kotaTujuan == 5) || (kotaAsal == 5 && kotaTujuan == 4)){
                if (find("Kota Semarang") == find("Kota Jakarta")){
                cout << "\n=> Anda bisa menggunakan moda transportasi Bus atau Kereta Api <=\n" << endl;
                cout << "\n---------------------------------------" << endl;
                }
            }else{
                cout << "\n=> Anda bisa menggunakan moda transportasi Kapal Feri atau Pesawat <=" << endl;
                cout << "\n---------------------------------------" << endl;
            }
            break;
        }
    }while(choice != 2);
        
    return 0;
}
