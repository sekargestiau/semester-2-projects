#include <iostream>

using namespace std;

enum klub_t {
    REAL_MADRID,
    CHELSEA,
    AC_MILAN,
    VALENCIA,
    JUMLAH_KLUB
};

enum hasil_t {
    MENANG = 3,
    SERI = 1,
    KALAH = 0,
};


int main(){

    // adjacency matrix
    hasil_t HasilPertandingan[JUMLAH_KLUB][JUMLAH_KLUB];
    int SelisihGol[JUMLAH_KLUB][JUMLAH_KLUB];

    // AC MILAN vs VALENCIA = 3-2
    // VALENCIA vs AC MILAN = 2-3
    HasilPertandingan[AC_MILAN][VALENCIA] = MENANG;
    SelisihGol[AC_MILAN][VALENCIA] = 1;
    HasilPertandingan[VALENCIA][AC_MILAN] = KALAH;
    SelisihGol[VALENCIA][AC_MILAN] = -1;

    // AC MILAN vs REAL MADRID = 2-4
    // REAL MADRID vs AC MILAN = 4-2
    HasilPertandingan[AC_MILAN][REAL_MADRID] = KALAH;
    SelisihGol[AC_MILAN][REAL_MADRID] = -2;
    HasilPertandingan[REAL_MADRID][AC_MILAN] = MENANG;
    SelisihGol[REAL_MADRID][AC_MILAN] = 2;

    // AC MILAN vs CHELSEA = 1-3
    // CHELSEA vs AC MILAN = 3-1
    HasilPertandingan[AC_MILAN][CHELSEA] = KALAH;
    SelisihGol[AC_MILAN][CHELSEA] = -2;
    HasilPertandingan[CHELSEA][AC_MILAN] = MENANG;
    SelisihGol[CHELSEA][AC_MILAN] = 2;

    // REAL MADRID vs CHELSEA = 1-1
    // CHELSEA vs REAL MADRID = 1-1
    HasilPertandingan[REAL_MADRID][CHELSEA] = SERI;
    SelisihGol[REAL_MADRID][CHELSEA] = 0;
    HasilPertandingan[CHELSEA][REAL_MADRID] = SERI;
    SelisihGol[CHELSEA][REAL_MADRID] = 0;

    // REAL MADRID vs VALENCIA = 5-4
    // VALENCIA vs REAL MADRID = 4-5
    HasilPertandingan[REAL_MADRID][VALENCIA] = MENANG;
    SelisihGol[REAL_MADRID][VALENCIA] = 1;
    HasilPertandingan[VALENCIA][REAL_MADRID] = KALAH;
    SelisihGol[VALENCIA][REAL_MADRID] = -1;

    // CHELSEA vs VALENCIA = 1-2
    // VALENCIA vs CHELSEA = 2-1
    HasilPertandingan[CHELSEA][VALENCIA] = KALAH;
    SelisihGol[CHELSEA][VALENCIA] = -1;
    HasilPertandingan[VALENCIA][CHELSEA] = MENANG;
    SelisihGol[VALENCIA][CHELSEA] = 1;

    cout << "\n[REAL MADRID]" << endl;
    cout << "=> Hasil pertandingan Real Madrid vs Chelsea adalah SERI dengan skor 1-1 dan selisih gol sebanyak " << SelisihGol[REAL_MADRID][CHELSEA] << endl;
    cout << "=> Hasil pertandingan Real Madrid vs AC Milan dimenangkan oleh Real Madrid dengan skor 4-2 dan selisih gol sebanyak " << SelisihGol[REAL_MADRID][AC_MILAN] << endl;
    cout << "=> Hasil pertandingan Real Madrid vs Valencia dimenangkan oleh Real Madrid dengan skor 5-4 dan selisih gol sebanyak " << SelisihGol[REAL_MADRID][VALENCIA] << endl;

    cout << "\n[CHELSEA]" << endl;
    cout << "=> Hasil pertandingan Chelsea vs Real Madrid adalah SERI dengan skor 1-1 dan selisih gol sebanyak " << SelisihGol[CHELSEA][REAL_MADRID] << endl;
    cout << "=> Hasil pertandingan Chelsea vs AC Milan dimenangkan oleh Chelsea dengan skor 3-1 dan selisih gol sebanyak " << SelisihGol[CHELSEA][AC_MILAN] << endl;
    cout << "=> Hasil pertandingan Chelsea vs Valencia dimenangkan oleh Valencia dengan skor 1-2 dan selisih gol sebanyak " << SelisihGol[CHELSEA][VALENCIA] << endl;

    cout << "\n[AC MILAN]" << endl;
    cout << "=> Hasil pertandingan AC Milan vs Real Madrid dimenangkan oleh Real Madrid dengan skor 2-4 dan selisih gol sebanyak " << SelisihGol[AC_MILAN][REAL_MADRID] << endl;
    cout << "=> Hasil pertandingan AC Milan vs Chelsea dimenangkan oleh Chelsea dengan skor 1-3 dan selisih gol sebanyak " << SelisihGol[AC_MILAN][CHELSEA] << endl;
    cout << "=> Hasil pertandingan AC Milan vs Valencia dimenangkan oleh AC Milan dengan skor 3-2 dan selisih gol sebanyak " << SelisihGol[AC_MILAN][VALENCIA] << endl;

    cout << "\n[VALENCIA]" << endl;
    cout << "=> Hasil pertandingan Valencia vs Real Madrid dimenangkan oleh Real Madrid dengan skor 4-5 dan selisih gol sebanyak " << SelisihGol[VALENCIA][REAL_MADRID] << endl;
    cout << "=> Hasil pertandingan Valencia vs Chelsea dimenangkan oleh Valencia dengan skor 2-1 dan selisih gol sebanyak " << SelisihGol[VALENCIA][CHELSEA] << endl;
    cout << "=> Hasil pertandingan Valencia vs AC Milan dimenangkan oleh AC Milan dengan skor 2-3 dan selisih gol sebanyak " << SelisihGol[VALENCIA][AC_MILAN] << endl;

    cout << "\n[INFORMASI TOTAL PEROLEHAN POIN TIM]" << endl;
    cout << "=> TOTAL PEROLEHAN POIN REAL MADRID : " << (HasilPertandingan[REAL_MADRID][VALENCIA] + HasilPertandingan[REAL_MADRID][AC_MILAN] + HasilPertandingan[REAL_MADRID][CHELSEA]) << " poin" << endl;
    cout << "=> TOTAL PEROLEHAN POIN CHELSEA     : " << (HasilPertandingan[CHELSEA][VALENCIA] + HasilPertandingan[CHELSEA][AC_MILAN] + HasilPertandingan[CHELSEA][REAL_MADRID]) << " poin" << endl;
    cout << "=> TOTAL PEROLEHAN POIN AC MILAN    : " << (HasilPertandingan[AC_MILAN][VALENCIA] + HasilPertandingan[AC_MILAN][REAL_MADRID] + HasilPertandingan[AC_MILAN][CHELSEA]) << " poin" << endl;
    cout << "=> TOTAL PEROLEHAN POIN VALENCIA    : " << (HasilPertandingan[VALENCIA][AC_MILAN] + HasilPertandingan[VALENCIA][REAL_MADRID] + HasilPertandingan[VALENCIA][CHELSEA]) << " poin" << endl;
    
    cout << "\n[INFORMASI TOTAL SELISIH GOL TIM]" << endl;
    cout << "=> TOTAL SELISIH GOL REAL MADRID :  " << (SelisihGol[REAL_MADRID][VALENCIA] + SelisihGol[REAL_MADRID][AC_MILAN] + SelisihGol[REAL_MADRID][CHELSEA]) << endl;
    cout << "=> TOTAL SELISIH GOL CHELSEA     :  " << (SelisihGol[CHELSEA][VALENCIA] + SelisihGol[CHELSEA][AC_MILAN] + SelisihGol[CHELSEA][REAL_MADRID]) << endl;
    cout << "=> TOTAL SELISIH GOL AC MILAN    : " << (SelisihGol[AC_MILAN][VALENCIA] + SelisihGol[AC_MILAN][REAL_MADRID] + SelisihGol[AC_MILAN][CHELSEA]) << endl;
    cout << "=> TOTAL SELISIH GOL VALENCIA    : " << (SelisihGol[VALENCIA][AC_MILAN] + SelisihGol[VALENCIA][REAL_MADRID] + SelisihGol[VALENCIA][CHELSEA]) << endl;
    cout << "\n";

    return 0;
}
