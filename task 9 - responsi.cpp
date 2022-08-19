/*
    RESPONSI PRAKTIKUM STRUKTUR DATA DAN ALGORITMA

Nama  : Sekar Gesti Amalia Utami
NIM   : M0521071
Kelas : C
*/

#include <iostream>
#include <list>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <math.h>
#include <string>
#include <iterator>
#include <vector>

using namespace std;

string semuaAnggota[66] = {"Digno", "Ardhyla", "Tita", "Kharisma", "Sekar", "Nita", "Anindita", "Raissa", 
"Sarah", "Afrizal", "Beatrix", "Ria", "Ihsan", "Furqon", "Rayhan", "Rizki", "Qonita", "Didan", "Abdi", "Fitria",
"Iskandar", "Kalista","Aura", "Rizan", "Lutfi", "Anang", "Haqqi", "Bram", "Irzan", "Julian", "Cahyo", "Irzi", "Abiyyu",
"Sangaji", "Diana", "Hilda", "Fauzan", "Hilmy", "Rama", "Nisa", "Tri", "Syaifullah", "Rio", "Aditia", "Afif", "Alfiki", "Andika",
"Andreas", "Ivander", "Babas", "Azzam", "Asyahra", "Gentur", "Ivan", "Nabilla", "Salomo", "Dyang", "Andini", "Hanina", "Adeline",
"Dafina", "Helmi", "Naurah", "Sitti", "Yitzhak", "Yuzzar" };

struct ProductCode{
    string namaProduk;
    int stockProduk;
    int hargaProduk;
};

enum node_t {
    GERBANG_DEPAN,
    GERBANG_BELAKANG,
    REKTORAT,
    AUDITORIUM,
    PERPUSTAKAAN,
    UPT_TIK,
    F_MIPA,
    F_KEDOKTERAN,
    F_PERTANIAN,
    DANAU,
    IKA,
    SPMB,
    BAA_BAPSI,
    MENWA,
    LPPM,
    UNS_INN,
    RUMAH_DINAS,
    F_ILMU_BUDAYA,
    F_EKONOMI_BISNIS,
    F_ILMU_SOSIAL_DAN_POLITIK,
    F_KEGURUAN_DAN_ILMU_PENDIDIKAN,
    PASCASARJANA,
    BIRO_MAWA,
    STUDENT_CENTER,
    MEDICAL_CENTER,
    SPAM,
    STADION,
    GOR,
    PORSIMA,
    PPLH,

    NODE_COUNT,
    NODE_INVALID = -1
};

map<node_t, string> node_name;
