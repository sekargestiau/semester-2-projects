#include <iostream>
#include <cstdlib>
#include <ctime>

#define NIM 71

enum feedback_t {
    TERLALU_KECIL,
    TERLALU_BESAR,
    BENAR
};

int angka_rahasia;

feedback_t coba_tebak(int tebakan) {
    if (tebakan < angka_rahasia) {
        return TERLALU_KECIL;
    }
    if (tebakan > angka_rahasia) {
        return TERLALU_BESAR;
    }
    return BENAR;
}

int maks_tebakan(int nilai_maks) {
    int maks = 1;
    while (nilai_maks > 0) {
        nilai_maks = nilai_maks / 2;
        maks++;
    }
    return maks;
}

// ============================================================================

int batas_kanan = 100 + NIM;
int batas_kiri = 1;

// ============================================================================

int generate_tebakan_berikutnya(int tebakan_sebelumnya, feedback_t feedback) {
    // INSTRUKSI : lengkapi code untuk fungsi ini supaya menghasilkan return berupa tebakan berikutnya
    
    int nilai_tengah = (batas_kanan + batas_kiri)/2;
    if(feedback == 1){
        batas_kanan = tebakan_sebelumnya;
    }else if(feedback == 0){
        batas_kiri = tebakan_sebelumnya;
    }
    return nilai_tengah;
    
}

int main() {
    std::cout << "*** TEBAK ANGKA ANTARA 1 SAMPAI DENGAN " << (100 + NIM) << " ***" << std::endl << std::endl;

    std::srand((unsigned int)std::time(NULL));

    // generate angka rahasia antara 1 sampai 100 + NIM
    angka_rahasia = 1 + (std::rand() % (100 + NIM));

    // INSTRUKSI : anda dapat menambah beberapa baris kode di sini sesuai kebutuhan
    
    int tebakan_awal; // INSTRUKSI : masukkan nilai tebakan awal yang sesuai
    std::cout << "Masukkan tebakan Anda : ";
    std::cin >> tebakan_awal;

    int tebakan_maks = maks_tebakan(100 + NIM);
    int tebakan_total = 0;
    int tebakan_berikutnya = tebakan_awal;

    std::cout << "Maksimal jumlah tebakan: " << tebakan_maks << std::endl << std::endl;

    while (true) {
        feedback_t feedback = coba_tebak(tebakan_berikutnya);
        tebakan_total++;

        std::cout << "Anda menebak angka " << tebakan_berikutnya << std::endl;

        if (feedback == TERLALU_KECIL) {
            std::cout << "Terlalu kecil!" << std::endl << std::endl;
        } else if (feedback == TERLALU_BESAR) {
            std::cout << "Terlalu besar!" << std::endl << std::endl;
        } else {
            std::cout << "Benar!" << std::endl << std::endl;
            break;
        }

        if (tebakan_total == tebakan_maks) {
            std::cout << "Anda mencapai maksimal jumlah tebakan!" << std::endl;
            break;
        }

        tebakan_berikutnya = generate_tebakan_berikutnya(tebakan_berikutnya, feedback);
    }

    std::cout << "Anda menebak sebanyak " << tebakan_total << " kali" << std::endl;

    return 0;
}
