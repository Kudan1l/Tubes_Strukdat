#include "tubes.h"

int main()
{
    ListKonsumen K;
    ListProduk P;
    string nama, alamat, ID;
    infoKonsumen Konsumen;
    infoProduk produk;

    int n, nKonsumen;

    /*

    createListKonsumen(K);

    cout << "Masukan Jumlah Konsumen: ";
    cin >> nKonsumen;
    cout << endl;

    for (int i = 1; i <= nKonsumen; i++) {
        cout << "Data Konsumen" << endl;
        cout << "Nama\t\t: ";
        cin >> Konsumen.nama;
        cout << "ID\t\t: ";
        cin >> Konsumen.id;
        cout << "Alamat\t\t: ";
        cin >> Konsumen.alamat;
        cout << endl;
        insertLastKonsumen(K, createElemenKonsumen(Konsumen));
    }

    showAllKonsumen(K);

    */
    createListKonsumen(K);
    createListProduk(P);

    bool cek = true;
    while (cek) {
        mainMenu();
        int pilihan;
        cin >> pilihan;
        cout << endl;

       switch (pilihan) {
        case 1: // Memnambahkan Konsumen
            cout << "Data Konsumen" << endl;
            cout << "Nama\t\t: ";
            cin >> Konsumen.nama;
            cout << "ID\t\t: ";
            cin >> Konsumen.id;
            cout << "Alamat\t\t: ";
            cin >> Konsumen.alamat;
            cout << endl;
            insertLastKonsumen(K, createElemenKonsumen(Konsumen));
            break;
        case 2: // Menampilkan Semua Konsumen
            showAllKonsumen(K);
            break;
        case 3: // Mencari Konsumen Menggunakan ID
            cout << "---------- Cari Konsumen ----------" << endl;
            cout << "Masukan ID\t: ";
            cin >> ID;
            cout << endl;
            searchKonsumen(K, ID);
            break;
        case 4: // Menambahkan data produk
            cout << "Data Produk" << endl;
            cout << "Jenis\t\t: ";
            cin >> produk.jenis;
            cout << "Harga\t\t: ";
            cin >> produk.harga;
            cout << "Stock\t\t: ";
            cin >> produk.stok;
            cout << endl;
            insertProduk(P, createElemenProduk(produk));
            break;
        case 5: // Menampilkan produk
            showProduk(P);
            break;
        case 6: // Program Selesai
            cout << "Terima Kasih" << endl << endl;
            cout << "Created by: " << endl;
            cout << "1. Agung Laksono Putra (1303220113)" << endl;
            cout << "2. Ahmad Rohman Nurrohim (1303220156)" << endl;
            cek = false;
            break;
        default:
            cout << "Pilihan tidak tersedia" << endl << endl;
       }
    }
}
