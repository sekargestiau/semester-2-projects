#include <iostream>
#include <map>

using namespace std;
struct ProductCode{
    string name;
    int stock;
    int price;
};


int main()
{
    int SaldoAwal, SaldoAkhir, NumProduct, CurrentStock, choice;
    string InputCode;
    map <string, ProductCode> DataProduct;

    ProductCode code;
    
    code.name = "Buku Tulis Sinar Dunia Isi 58";
    code.stock = 120;
    code.price = 3000;
    DataProduct["SD001"] = code;

    code.name = "Buku Gambar A3";
    code.stock = 150;
    code.price = 9500;
    DataProduct["BGA002"] = code;

    code.name = "Pensil Joyko 2B";
    code.stock = 225;
    code.price = 2000;
    DataProduct["PJB003"] = code;

    code.name = "Lem Kertas Glukol";
    code.stock = 175;
    code.price = 5500;
    DataProduct["LKG005"] = code;

    code.name = "Jangka Besi Joyko";
    code.stock = 110;
    code.price = 10000;
    DataProduct["JBJ006"] = code;

    code.name = "Penggaris Besi 50 cm";
    code.stock = 360;
    code.price = 7000;
    DataProduct["PB007"] = code;

    code.name = "Correction Pen Kenko";
    code.stock = 275;
    code.price = 4000;
    DataProduct["CPK008"] = code;

    code.name = "Ballpoint Pilot";
    code.stock = 370;
    code.price = 2600;
    DataProduct["BP009"] = code;

    cout << "==================================" << endl;
    cout << "----------- ATK STORE ------------" << endl;
    cout << "==================================\n" << endl;  
    
    do {
        cout << "MENU" << endl;
        cout << "1. MEMBELI PRODUK" << endl;
        cout << "2. KELUAR" << endl;
        cout << "\n---------------------------------------" << endl;
        cout << "Masukkan angka menu yang Anda pilih : ";
        cin >> choice;
        switch (choice){
            case 1:
                cout << "\n[DAFTAR KODE PRODUK BESERTA NAMA PRODUK]" << endl;
                for (
                map<string, ProductCode>::iterator it = DataProduct.begin();
                it != DataProduct.end();
                ++it
                ){
                cout << it->first << " : " << it->second.name << endl;
                }
                cout << "\n---------------------------------------" << endl;
                cout << "\nMasukkan saldo Anda : Rp ";
                cin >> SaldoAwal;
                cout << "\nMasukkan kode produk yang ingin Anda beli : ";
                cin >> InputCode;
                if(InputCode == "BGA002"){
                    ProductCode code = DataProduct["BGA002"];
                    cout << "\nStok Produk " << code.name << " (BGA002)  : " << code.stock << " buah" << endl;
                    cout << "Harga Produk " << code.name << " (BGA002) : Rp " << code.price << endl;
                    cout << "\nMasukkan jumlah produk yang ingin Anda beli : ";
                    cin >> NumProduct;
                    if((NumProduct * DataProduct["BGA002"].price) > SaldoAwal){
                        cout << "\n[INFORMASI]" << endl;
                        cout << "Mohon maaf Saldo Anda tidak mencukupi untuk membeli produk ini" << endl;
                        cout << "\n";
                    }else{
                        CurrentStock = DataProduct["BGA002"].stock - NumProduct;
                        SaldoAkhir = SaldoAwal - (NumProduct * DataProduct["BGA002"].price);
                        cout << "\n[INFORMASI]" << endl;
                        cout << "Anda telah membeli produk " << code.name << " (BGA002) sebanyak " << NumProduct << " buah" << endl;
                        cout << "\n\nStok Produk " << code.name << " (BGA002) Terbaru : " << CurrentStock << " buah" << endl;
                        cout << "Saldo Akhir Anda : Rp " << SaldoAkhir << endl;
                        cout << "\n--------------TERIMA KASIH-------------" << endl;
                    }
                }else if(InputCode == "BP009"){
                    ProductCode code = DataProduct["BP009"];
                    cout << "\nStok Produk " << code.name << " (BP009)  : " << code.stock << " buah" << endl;
                    cout << "Harga Produk " << code.name << " (BP009) : Rp " << code.price << endl;
                    cout << "\nMasukkan jumlah produk yang ingin Anda beli : ";
                    cin >> NumProduct;
                    if((NumProduct * DataProduct["BP009"].price) > SaldoAwal){
                        cout << "\n[INFORMASI]" << endl;
                        cout << "Mohon maaf Saldo Anda tidak mencukupi untuk membeli produk ini" << endl;
                        cout << "\n";
                    }else{
                        CurrentStock = DataProduct["BP009"].stock - NumProduct;
                        SaldoAkhir = SaldoAwal - (NumProduct * DataProduct["BP009"].price);
                        cout << "\n[INFORMASI]" << endl;
                        cout << "Anda telah membeli produk " << code.name << " (BP009) sebanyak " << NumProduct << " buah" << endl;
                        cout << "\n\nStok Produk " << code.name << " (BP009) Terbaru : " << CurrentStock << " buah" << endl;
                        cout << "Saldo Akhir Anda : Rp " << SaldoAkhir << endl;
                        cout << "\n--------------TERIMA KASIH-------------" << endl;
                    }
                }else if(InputCode == "CPK008"){
                    ProductCode code = DataProduct["CPK008"];
                    cout << "\nStok Produk " << code.name << " (CPK008)  : " << code.stock << " buah" << endl;
                    cout << "Harga Produk " << code.name << " (CPK008) : Rp " << code.price << endl;
                    cout << "\nMasukkan jumlah produk yang ingin Anda beli : ";
                    cin >> NumProduct;
                    if((NumProduct * DataProduct["CPK008"].price) > SaldoAwal){
                        cout << "\n[INFORMASI]" << endl;
                        cout << "Mohon maaf Saldo Anda tidak mencukupi untuk membeli produk ini" << endl;
                        cout << "\n";
                    }else{
                        CurrentStock = DataProduct["CPK008"].stock - NumProduct;
                        SaldoAkhir = SaldoAwal - (NumProduct * DataProduct["CPK008"].price);
                        cout << "\n[INFORMASI]" << endl;
                        cout << "Anda telah membeli produk " << code.name << " (CPK008) sebanyak " << NumProduct << " buah" << endl;
                        cout << "\n\nStok Produk " << code.name << " (CPK008) Terbaru : " << CurrentStock << " buah" << endl;
                        cout << "Saldo Akhir Anda : Rp " << SaldoAkhir << endl;
                        cout << "\n--------------TERIMA KASIH-------------" << endl;
                    }
                }else if(InputCode == "JBJ006"){
                    ProductCode code = DataProduct["JBJ006"];
                    cout << "\nStok Produk " << code.name << " (JBJ006)  : " << code.stock << " buah" << endl;
                    cout << "Harga Produk " << code.name << " (JBJ006) : Rp " << code.price << endl;
                    cout << "\nMasukkan jumlah produk yang ingin Anda beli : ";
                    cin >> NumProduct;
                    if((NumProduct * DataProduct["JBJ006"].price) > SaldoAwal){
                        cout << "\n[INFORMASI]" << endl;
                        cout << "Mohon maaf Saldo Anda tidak mencukupi untuk membeli produk ini" << endl;
                        cout << "\n";
                    }else{
                        CurrentStock = DataProduct["JBJ006"].stock - NumProduct;
                        SaldoAkhir = SaldoAwal - (NumProduct * DataProduct["JBJ006"].price);
                        cout << "\n[INFORMASI]" << endl;
                        cout << "Anda telah membeli produk " << code.name << " (JBJ006) sebanyak " << NumProduct << " buah" << endl;
                        cout << "\n\nStok Produk " << code.name << " (JBJ006) Terbaru : " << CurrentStock << " buah" << endl;
                        cout << "Saldo Akhir Anda : Rp " << SaldoAkhir << endl;
                        cout << "\n--------------TERIMA KASIH-------------" << endl;
                    }
                }else if(InputCode == "LKG005"){
                    ProductCode code = DataProduct["LKG005"];
                    cout << "\nStok Produk " << code.name << " (LKG005)  : " << code.stock << " buah" << endl;
                    cout << "Harga Produk " << code.name << " (LKG005) : Rp " << code.price << endl;
                    cout << "\nMasukkan jumlah produk yang ingin Anda beli : ";
                    cin >> NumProduct;
                    if((NumProduct * DataProduct["LKG005"].price) > SaldoAwal){
                        cout << "\n[INFORMASI]" << endl;
                        cout << "Mohon maaf Saldo Anda tidak mencukupi untuk membeli produk ini" << endl;
                        cout << "\n";
                    }else{
                        CurrentStock = DataProduct["LKG005"].stock - NumProduct;
                        SaldoAkhir = SaldoAwal - (NumProduct * DataProduct["LKG005"].price);
                        cout << "\n[INFORMASI]" << endl;
                        cout << "Anda telah membeli produk " << code.name << " (LKG005) sebanyak " << NumProduct << " buah" << endl;
                        cout << "\n\nStok Produk " << code.name << " (LKG005) Terbaru : " << CurrentStock << " buah" << endl;
                        cout << "Saldo Akhir Anda : Rp " << SaldoAkhir << endl;
                        cout << "\n--------------TERIMA KASIH-------------" << endl;
                    }
                }else if(InputCode == "PB007"){
                    ProductCode code = DataProduct["PB007"];
                    cout << "\nStok Produk " << code.name << " (PB007)  : " << code.stock << " buah" << endl;
                    cout << "Harga Produk " << code.name << " (PB007) : Rp " << code.price << endl;
                    cout << "\nMasukkan jumlah produk yang ingin Anda beli : ";
                    cin >> NumProduct;
                    if((NumProduct * DataProduct["PB007"].price) > SaldoAwal){
                        cout << "\n[INFORMASI]" << endl;
                        cout << "Mohon maaf Saldo Anda tidak mencukupi untuk membeli produk ini" << endl;
                        cout << "\n";
                    }else{
                        CurrentStock = DataProduct["PB007"].stock - NumProduct;
                        SaldoAkhir = SaldoAwal - (NumProduct * DataProduct["PB007"].price);
                        cout << "\n[INFORMASI]" << endl;
                        cout << "Anda telah membeli produk " << code.name << " (PB007) sebanyak " << NumProduct << " buah" << endl;
                        cout << "\n\nStok Produk " << code.name << " (PB007) Terbaru : " << CurrentStock << " buah" << endl;
                        cout << "Saldo Akhir Anda : Rp " << SaldoAkhir << endl;
                        cout << "\n--------------TERIMA KASIH-------------" << endl;
                    }
                }else if(InputCode == "PJB003"){
                    ProductCode code = DataProduct["PJB003"];
                    cout << "\nStok Produk " << code.name << " (PJB003)  : " << code.stock << " buah" << endl;
                    cout << "Harga Produk " << code.name << " (PJB003) : Rp " << code.price << endl;
                    cout << "\nMasukkan jumlah produk yang ingin Anda beli : ";
                    cin >> NumProduct;
                    if((NumProduct * DataProduct["PJB003"].price) > SaldoAwal){
                        cout << "\n[INFORMASI]" << endl;
                        cout << "Mohon maaf Saldo Anda tidak mencukupi untuk membeli produk ini" << endl;
                        cout << "\n";
                    }else{
                        CurrentStock = DataProduct["PJB003"].stock - NumProduct;
                        SaldoAkhir = SaldoAwal - (NumProduct * DataProduct["PJB003"].price);
                        cout << "\n[INFORMASI]" << endl;
                        cout << "Anda telah membeli produk " << code.name << " (PJB003) sebanyak " << NumProduct << " buah" << endl;
                        cout << "\n\nStok Produk " << code.name << " (PJB003) Terbaru : " << CurrentStock << " buah" << endl;
                        cout << "Saldo Akhir Anda : Rp " << SaldoAkhir << endl;
                        cout << "\n--------------TERIMA KASIH-------------" << endl;
                    }
                }else if(InputCode == "SD001"){
                    ProductCode code = DataProduct["SD001"];
                    cout << "\nStok Produk " << code.name << " (SD001)  : " << code.stock << " buah" << endl;
                    cout << "Harga Produk " << code.name << " (SD001) : Rp " << code.price << endl;
                    cout << "\nMasukkan jumlah produk yang ingin Anda beli : ";
                    cin >> NumProduct;
                    if((NumProduct * DataProduct["SD001"].price) > SaldoAwal){
                        cout << "\n[INFORMASI]" << endl;
                        cout << "Mohon maaf Saldo Anda tidak mencukupi untuk membeli produk ini" << endl;
                        cout << "\n";
                    }else{
                        CurrentStock = DataProduct["SD001"].stock - NumProduct;
                        SaldoAkhir = SaldoAwal - (NumProduct * DataProduct["SD001"].price);
                        cout << "\n[INFORMASI]2" << endl;
                        cout << "Anda telah membeli produk " << code.name << " (SD001) sebanyak " << NumProduct << " buah" << endl;
                        cout << "\n\nStok Produk " << code.name << " (SD001) Terbaru : " << CurrentStock << " buah" << endl;
                        cout << "Saldo Akhir Anda : Rp " << SaldoAkhir << endl;
                        cout << "\n--------------TERIMA KASIH-------------" << endl;
                    }
                }else{
                    cout << "\n[INFORMASI] \nKode Produk yang Anda masukkan salah!\n" << endl;
                }
            break; 
        }
    }while(choice!=2);
    

    return 0;
}
