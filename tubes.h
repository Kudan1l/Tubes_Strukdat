#ifndef TUBES_H_INCLUDED
#define TUBES_H_INCLUDED

#include <iostream>

#define info(P) (P)->info
#define next(P) (P)->next
#define first(L) (L).first
#define connect(P) (P)->connectBelanjaan
#define belanjaan(P) (P)->Belanjaan
#define jBeli(P) (P)->jumlahBeli
#define tHarga(P) (P)->totalHarga

using namespace std;

struct Konsumen {
    string nama;
    string alamat;
    string id;
};

struct Produk {
    string jenis;
    int terjual;
    int stok;
    int profit;
    int harga;
};

typedef struct elmProduk *adrProduk;

typedef struct elmKonsumen *adrKonsumen;

typedef struct childProduk *adrChildBelanjaan;

typedef Konsumen infoKonsumen;

typedef Produk infoProduk;

struct elmKonsumen {
    infoKonsumen info;
    adrKonsumen next;
    adrChildBelanjaan Belanjaan;
};

struct elmProduk {
    infoProduk info;
    adrProduk next;
};



struct childProduk {
    adrProduk connectBelanjaan;
    int jumlahBeli;
    int totalHarga;
    adrChildBelanjaan next;
};

struct ListKonsumen {
    adrKonsumen first;
};

struct ListProduk {
    adrProduk first;
};

// Konsumen
void createListKonsumen(ListKonsumen &K);
adrKonsumen createKonsumen(infoKonsumen infoK);
void addKonsumen(ListKonsumen &K, adrKonsumen addK);
void showKonsumen(ListKonsumen K);
void hapusKonsumen(ListKonsumen &K, string idKonsumen);

// Produk
void createListProduk(ListProduk &P);
adrProduk createProduk(infoProduk infoP);
void addProduk(ListProduk &P, adrProduk addP);
void showProduk(ListProduk P);
void hapusProduk(ListProduk &P, ListKonsumen &K, string jenisProdukDicari);
// Child
void addProdukBeli(ListKonsumen &K, ListProduk &P, string idKonsumen, string jenisProdukDicari, int jumlah);
void hapusChild(ListKonsumen &K, string idKonsumen, string jenisProdukDicari);

// Search
adrKonsumen cariKonsumen(ListKonsumen K, string idKonsumen);
adrProduk cariProduk(ListProduk P, string jenisProdukDicari);
void cariChild(ListKonsumen K, string jenisProdukDicari);
void showOneKonsumen(ListKonsumen K, ListProduk P, string idKonsumen);
void showOneProduk(ListProduk P, string jenisProdukDicari);

void mainMenu();


#endif // TUBES_H_INCLUDED
