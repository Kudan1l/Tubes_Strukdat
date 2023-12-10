#include "tubes.h"

void createListKonsumen(ListKonsum &K) {
    first(K) = NULL;
}

adr_konsumen createElemenKonsumen(infokonsum a) {
    adr_konsumen K;
    K = new elemenKonsumen;
    info(K) = a;
    next(K) = NULL;
    return K;
}

void insertLastKonsumen(ListKonsum &K, adr_konsumen addKonsumen) {
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

void showAllKonsumen(ListKonsum K) {
    adr_konsumen Konsumen = first(K);
    int i = 1;
    cout << "----- List Konsumen -----" << endl;
    if (Konsumen != NULL) {
        while (Konsumen != NULL) {
            cout << "* KONSUMEN " << i << endl;
            cout << "Nama\t\t: " << info(Konsumen).nama << endl;
            cout << "ID\t\t: " << info(Konsumen).id << endl;
            cout << "Alamat\t\t: " << info(Konsumen).alamat << endl;
            cout << "Jumlah Produk\t: " << info(Konsumen).jumlah_produk << endl;
            cout << "Total Belanja\t: " << info(Konsumen).total_belanja << endl;
            Konsumen = next(Konsumen);
            cout << endl;
            i++;
        }
    } else {
        cout << "Tidak Ada Konsumen";
    }
}

void mainMenu() {
    cout << "--------- Main Menu ----------" << endl;
    cout << "1. Tambah Konsumen" << endl;
    cout << "2. Tampilkan Konsumen" << endl;
    cout << "3. Exit" << endl;
    cout << "Masukan Pilihan: ";
}
