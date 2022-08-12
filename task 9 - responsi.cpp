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
