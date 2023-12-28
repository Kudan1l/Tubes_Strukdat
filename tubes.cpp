#include "tubes.h"

void createListKonsumen(ListKonsumen &K) {
    first(K) = NULL;
}

adr_konsumen createElemenKonsumen(infoKonsumen a) {
    adr_konsumen K;
    K = new elemenKonsumen;
    info(K) = a;
    next(K) = NULL;
    return K;
}

void insertLastKonsumen(ListKonsumen &K, adr_konsumen addKonsumen) {
    adr_konsumen Q = first(K);
    if (first(K) == NULL) {
        first(K) = addKonsumen;
    } else {
        while (next(Q) != NULL) {
            Q = next(Q);
        }
        next(Q) = addKonsumen;
    }
}

void showAllKonsumen(ListKonsumen K) {
    adr_konsumen Konsumen = first(K);
    int i = 1;
    cout << "---------- List Konsumen ----------" << endl;
    if (Konsumen != NULL) {
        while (Konsumen != NULL) {
            cout << "* KONSUMEN " << i << endl;
            cout << "Nama\t\t: " << info(Konsumen).nama << endl;
            cout << "ID\t\t: " << info(Konsumen).id << endl;
            cout << "Alamat\t\t: " << info(Konsumen).alamat << endl;
            Konsumen = next(Konsumen);
            cout << endl;
            i++;
        }
    } else {
        cout << "Tidak Ada Konsumen" << endl << endl;
    }
}

void searchKonsumen(ListKonsumen K, string ID) {
    adr_konsumen Konsumen = first(K);
    bool cek = false;

    while (Konsumen != NULL) {
        if (info(Konsumen).id == ID) {
            cout << "Nama\t\t: " << info(Konsumen).nama << endl;
            cout << "ID\t\t: " << info(Konsumen).id << endl;
            cout << "Alamat\t\t: " << info(Konsumen).alamat << endl;
            cout << endl;
            cek = true;
        }
        Konsumen = next(Konsumen);
    }
     if (!cek) {
        cout << "Konsumen Tidak Ditemukan" << endl << endl;
    }
}

void createListProduk(ListProduk &P) {
    first(P) = NULL;
}

adr_produk createElemenProduk(infoProduk x) {
    adr_produk P = new elemenProduk;
    info(P) = x;
    next(P) = NULL;
    return P;
}

void insertProduk(ListProduk &P, adr_produk addProduk) {
    adr_produk Q = first(P);
    if (first(P) == NULL) {
        first(P) = addProduk;
    } else {
        while (next(Q) != NULL) {
            Q = next(Q);
        }
        next(Q) = addProduk;
    }
}

void showProduk(ListProduk P) {
    adr_produk produk = first(P);
    cout << "----------- List Produk -----------" << endl;
    if (produk != NULL) {
        while (produk != NULL) {
            int i = 1;
            cout << "* PRODUK " << i << endl;
            cout << "Jenis\t: " << info(produk).jenis << endl;
            cout << "Harga\t: " << info(produk).harga << endl;
            cout << "Stock\t: " << info(produk).stok << endl;
            cout << "Terjual\t: " << info(produk).terjual << endl;
            cout << "Profit\t: " << info(produk).profit << endl;
            produk = next(produk);
            cout << endl;
            i++;
        }
    } else {
        cout << "Produk tidak tersedia" << endl << endl;;
    }
}


void mainMenu() {
    cout << "------------ Main Menu ------------" << endl;
    cout << "1. Tambah Konsumen" << endl;
    cout << "2. Tampilkan Konsumen" << endl;
    cout << "3. Cari Konsumen" << endl;
    cout << "4. Tambah Produk" << endl;
    cout << "5. Tampilkan Produk" << endl;
    cout << "6. Exit" << endl;
    cout << "Masukan Pilihan: ";
}
