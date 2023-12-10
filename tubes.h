#ifndef TUBES_H_INCLUDED
#define TUBES_H_INCLUDED
#include <iostream>

#define info(P) P->info
#define next(P) P->next
#define first(L) L.first

using namespace std;

struct Konsumen {
    string nama;
    string alamat;
    string id;
    int jumlah_produk;
    int total_belanja;
};

struct Produk {
    string jenis;
    int terjual;
    int stok;
    int harga;
};

struct Belanjaan {
    string Jenis;

};

typedef struct elemenProduk *adr_produk;

typedef struct elemenKonsumen *adr_konsumen;

typedef Konsumen infokonsum;

typedef Produk infoproduk;

struct elemenKonsumen {
    infokonsum info;
    adr_konsumen next;
};

struct elemenProduk {
    infoproduk info;
    adr_produk next;
};

struct ListKonsum {
    adr_konsumen first;
};

struct ListProduk {
    adr_produk first;
};

void createListKonsumen(ListKonsum &K);
void createListProduk(ListProduk &P);
adr_konsumen createElemenKonsumen(infokonsum a);
// adr_produk insertData_Produk(infoproduk b);
void insertLastKonsumen(ListKonsum &K, adr_konsumen addKonsumen);
void showAllKonsumen(ListKonsum K);
/*
void ShowAllData_parent(ListKonsum K, ListProduk P);
void DeleteData();
void SearchData_KonsumenProduk(ListKonsum K, ListProduk P, string name, string kategori);
void SearchDataBelanjaan();
void TambahDataBelanjaan();
void InsertDataBelanjaKeKonsumen();
void ShowAllData();
void SearchData_BelanjaKonsumen();
void DeleteData_BelanjaKonsumen();
void JumlahBelanjaKonsumen();
*/

void mainMenu();


#endif // TUBES_H_INCLUDED
